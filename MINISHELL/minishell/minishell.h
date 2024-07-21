/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 01:49:54 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/21 02:23:08 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//bool write
	// 0 = append
	// 1 = write
typedef struct s_output
{
	bool		write;
	char		*name;
	t_output	*next;
} t_output;

//bool heredoc
	// 0 = no
	// 1 = yes
typedef struct s_input
{
	bool		heredoc;
	char		*name;
	t_input		*next;
} t_input;


typedef struct s_pipe
{
	t_input		*in;
	t_output	*out;
	char		**arguments;
	t_pipe		*next;
} t_pipe;

//bool exitval
	// 0 = no
	// 1 = yes
typedef struct s_pipe_set
{
	int			exit_val;
	char		*raw_text;
	t_pipe		*pipe;
	t_pipe_set	*next;
} t_pipe_set;
