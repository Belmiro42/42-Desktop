/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 01:49:54 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/27 10:38:28 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <bsd/string.h>

typedef struct s_pipe_set	t_pipe_set;
typedef struct s_output		t_output;
typedef struct s_input		t_input;
typedef struct s_pipe		t_pipe;
typedef struct s_args		t_args;

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
	t_args		*args;
	t_input		*in;
	t_output	*out;
	t_pipe		*next;
} t_pipe;

// STRUCT DESCRIPTION: t_input
typedef struct s_input
{
	bool		heredoc;
	char		*filename;
	t_input		*next;
} t_input;

// STRUCT DESCRIPTION: t_output
typedef struct s_output
{
	bool		write;
	char		*name;
	t_output	*next;
} t_output;

// STRUCT DESCRIPTION: t_arg
//Does it contain a wildcard and if so what position is that wildcard in?
typedef struct s_args
{
	bool		wildcard;
	int			*pos;
	char		*name;
	t_output	*next;
} t_args;

char			*ft_strjoin(char const *s1, char const *s2, bool free1, bool free2);
char			*parsing_primitive(char *input);
char			*add_character(char s1, char *s2, bool free1);
int				in_quotes(char c, int *quote);
int				bels_isspace(char c);
int				ft_strlcat(char *dst, const char *src, size_t buff_size);
size_t			ft_strlen(const char *s);
void			find_pipes_1(t_pipe_set *set);
void			interpret_pipe(t_pipe *p);
t_pipe_set		*find_pipe_sets(char *str);