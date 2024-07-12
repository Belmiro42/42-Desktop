/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:12:20 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/04/01 21:26:59 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst,
			const char *src, size_t buff_size);
int		ft_strlcat(char *dst,
			const char *src, size_t buff_size);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_striteri(char *string, void (*f)(unsigned int, char*));
char	*ft_strdup(const char *str1);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(char const *string, char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	*ft_memset(void *str, int ch, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_memcmp(const void *block1, const void *block2, size_t reach);
void	*ft_memchr(const void *str, int c, size_t n);
char	*ft_strmapi(char *string, char (*f)(unsigned int, char));
char	*ft_itoa(int n);
int		ft_isprint(unsigned short c);
int		ft_isdigit(unsigned short c);
int		ft_isascii(unsigned short c);
int		ft_isalpha(unsigned short c);
int		ft_isalnum(unsigned char c);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *str, size_t n);
int		ft_atoi(const char *str);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif