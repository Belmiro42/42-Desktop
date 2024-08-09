/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 01:49:54 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/08 23:39:50 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │								   INCLUDES									│
//  └───────────────────────────────────────────────────────────────────────┘

#include <dirent.h>
#include <errno.h>
#include <limits.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │									MACROS									│
//  └───────────────────────────────────────────────────────────────────────┘

#define DEL 1
#define KEEP 0

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │						STRUCTURE PROTOTYPING							│
//  └───────────────────────────────────────────────────────────────────────┘

typedef struct s_set	t_set;
typedef struct s_output	t_output;
typedef struct s_input	t_input;
typedef struct s_pipe	t_pipe;
typedef struct s_args	t_args;
typedef struct s_env	t_env;

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │								  SRUCTURES									│
//  └───────────────────────────────────────────────────────────────────────┘

// STRUCT DESCRIPTION: t_input
typedef struct s_env
{
	char				*key;
	char				*value;
	t_env				*next;
}						t_env;

// STRUCT DESCRIPTION: t_set
typedef struct s_set
{
	int					exit_val;
	char				*raw_text;
	t_pipe				*pipe;
	t_set				*next;
}						t_set;

// STRUCT DESCRIPTION: t_pipe
typedef struct s_pipe
{
	char				*raw_text;
	char				**args;
	t_pipe				*next;
	t_input				*in;
	t_output			*out;
}						t_pipe;

// STRUCT DESCRIPTION: t_output
typedef struct s_output
{
	bool				append;
	char				*filename;
	t_output			*next;
}						t_output;

// STRUCT DESCRIPTION: t_input
typedef struct s_input
{
	bool				heredoc;
	char				*filename;
	t_input				*next;
}						t_input;

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │								STRING FUNCTIONS							│
//  └───────────────────────────────────────────────────────────────────────┘

size_t					ft_strlen(const char *s);
size_t					ft_strlcpy(char *dst, const char *src,
							size_t buff_size);
char					*ft_substr(char const *s, int start, int len);
char					*ft_strnstr(const char *str, const char *to_find,
							size_t len);
char					*ft_strdup(const char *str1);
char					*ft_substr(char const *s, int start, int len);
char					*ft_itoa(int n);
int						ft_strlcat(char *dst, const char *src,
							size_t buff_size);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
int						ft_isdigit(unsigned short c);
int						ft_isalpha(unsigned short c);
int						ft_isalnum(unsigned char c);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_atoi(const char *str);
void					ft_putstr_fd(char *s, int fd);

// MODIFICADO DESDE LIBFT
char					*ft_strjoin(char *s1, char *s2, bool KD1, bool KD2);
int						ft_isspace(char c);
int						ft_arrlen(char **arr);
void					ft_freedbl(char **twodimmalloc);
char					*add_character(char s1, char *s2, bool free1);

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							PARSING FUNCTIONS							│
//  └───────────────────────────────────────────────────────────────────────┘

void					find_pipes(t_set *set);
void					interpret_pipe(t_pipe *p);
void					tokenise(t_pipe *current, char *str);
char					*variable_expansion(char *input, t_env *environment);
char					*expand_wildcards(char *str);
char					**wildcard_split(char const *s, char c);
int						in_quotes(char c, int *quote);
t_set					*find_sets(char *str);
t_set					*construct_parser_struct(char *input,
							t_env *environment);
int						parse_error(char *str, t_env *environemnt);

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							ENVIRONMENT FUNCTIONS							│
//  └───────────────────────────────────────────────────────────────────────┘

t_env					*create_env_variables(char **envp, int argc,
							char **argv);
bool					key_exists_env(char *key, t_env *environment);
void					new_val_env(char *key, char *new_val,
							t_env **environment);
char					*get_val_env(char *key, t_env *environment);
void					del_var_env(char *key, t_env **environment);

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │								  EXIT PROGRAM								│
//  └───────────────────────────────────────────────────────────────────────┘

void					free_env(t_env *env);
void					free_parser_struct(t_set *set, int *pointer,
							t_env *env);

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │								    BUILTINS								│
//  └───────────────────────────────────────────────────────────────────────┘

int						env_builtin(char **args, t_env *environment);
int						export_builtin(char **args, t_env *environment);
int						echo_builtin(char **args, t_env *environment);
int						pwd_builtin(char **arg, t_env *environment);
int						exit_builtin(char **args, t_env *environment);
int						unset_builtin(char **args, t_env *environment);
int						cd_builtin(char **args, t_env *environment);

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │								  	SIGNALS									│
//  └───────────────────────────────────────────────────────────────────────┘

void					signals(void);

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │								  	ERRORS									│
//  └───────────────────────────────────────────────────────────────────────┘

void					print_error(char *perror, char *errno);
