/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 01:49:54 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/04 00:02:49 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//  ┌───────────────────────────────────────────────────────────────────────┐
//  │						 	   INCLUDES									│
//  └───────────────────────────────────────────────────────────────────────┘

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <limits.h>
#include <signal.h>
#include <stdbool.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <readline/readline.h>

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │						 		MACROS									│
//  └───────────────────────────────────────────────────────────────────────┘

#define DEL				1
#define KEEP			0
#define KRED  			"\x1B[31m"
#define KGRN  			"\x1B[32m"
#define KWHT  			"\x1B[37m"

/// DELETE IF NOTE NEEDED
///#define KNRM  			"\x1B[0m"
///#define KYEL  			"\x1B[33m"
///#define KBLU  			"\x1B[34m"
///#define KMAG  			"\x1B[35m"
///#define KCYN  			"\x1B[36m"

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │						 ENVIRONMENT SRUCTURE							│
//  └───────────────────────────────────────────────────────────────────────┘

typedef struct s_pipe_set	t_pipe_set;
typedef struct s_output		t_output;
typedef struct s_input		t_input;
typedef struct s_pipe		t_pipe;
typedef struct s_args		t_args;
typedef struct s_env		t_env;

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │						 ENVIRONMENT SRUCTURE							│
//  └───────────────────────────────────────────────────────────────────────┘

// STRUCT DESCRIPTION: t_input
typedef struct s_env
{
	char		*key;
	char		*value;
	t_env		*next;
} t_env;

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							PARSING STUCTURES							│
//  └───────────────────────────────────────────────────────────────────────┘

// STRUCT DESCRIPTION: t_pipe_set
typedef struct s_pipe_set
{
	int			exit_val;
	char		*raw_text;
	t_pipe		*pipe;
	t_pipe_set	*next;
} t_pipe_set;

// STRUCT DESCRIPTION: t_pipe
typedef struct s_pipe
{
	char		*raw_text;
	char		**args;
	t_pipe		*next;
	t_input		*in;
	t_output	*out;
} t_pipe;

// STRUCT DESCRIPTION: t_output
typedef struct s_output
{
	char		*filename;
	bool		write;
	t_output	*next;
} t_output;

// STRUCT DESCRIPTION: t_input
typedef struct s_input
{
	bool		heredoc;
	char		*filename;
	t_input		*next;
} t_input;

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							EXTERN VARIABLES							│
//  └───────────────────────────────────────────────────────────────────────┘

extern t_env *minishell_env;

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							PARSING FUNCTIONS							│
//  └───────────────────────────────────────────────────────────────────────┘

void			find_pipes(t_pipe_set *set);
void			interpret_pipe(t_pipe *p);
void			tokenise(t_pipe *current, char *str);
char			*variable_expansion(char *input);
char			*add_character(char s1, char *s2, bool free1);
char			*expand_wildcards(char *str);
t_pipe_set		*find_pipe_sets(char *str);
char			**wildcard_split(char const *s, char c);
int				in_quotes(char c, int *quote);

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │						  	STRING FUNCTIONS							│
//  └───────────────────────────────────────────────────────────────────────┘

char			*ft_substr(char const *s,  int start, int len);
char			*ft_strjoin(char *s1, char *s2, bool KD1, bool KD2);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
char			*ft_strdup(const char *str1);
char			*ft_substr(char const *s, int start, int len);
int				ft_strlcat(char *dst, const char *src, size_t buff_size);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t buff_size);
int				ft_isspace(char c);
void			ft_freedbl(char **twodimmalloc);
int				ft_isdigit(unsigned short c);
int				ft_isalpha(unsigned short c);
int				ft_isalnum(unsigned char c);


//  ┌───────────────────────────────────────────────────────────────────────┐
//  │						  ENVIRONMENT FUNCTIONS							│
//  └───────────────────────────────────────────────────────────────────────┘

t_env			*create_env_variables(char **real_variables);
bool			key_exists_env(char *key);
void			new_val_env(char *key, char *new_val);
char			*get_val_env(char *key);



void transform_input(char *input);
void signals();