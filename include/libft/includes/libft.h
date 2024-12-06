/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:10:05 by fgranger          #+#    #+#             */
/*   Updated: 2024/12/06 20:01:58 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define SIZE_MAX 18446744073709551615UL

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <limits.h>

//BUFFER SIZE for GNL
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

//Struct for ft_lst functions
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//GNL functions
char	*get_next_line(int fd);
char	*ft_strjoin_free(char *buffer, char *reading);

//ft_is functions
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_isspace(int c);

//ft_to functions
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
int		ft_toupper(int c);
int		ft_tolower(int c);

//ft_mem functions
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t nitems, size_t size);

//ft_put functions
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putchar_fd(char c, int fd);

//ft_str functions
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strnstr(const char	*big, const char *little, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

//ft_lst functions
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
int		ft_lstsize(t_list *lst);

//ft_printf functions
int		ft_printf(const char *str, ...);
int		ft_c(va_list args);
int		ft_s(va_list args);
int		ft_p(va_list args);
int		ft_i(va_list args);
int		ft_u(va_list args);
int		ft_x(va_list args);
int		ft_d(va_list args);
int		ft_xucase(va_list args);
int		ft_mod(va_list args);
void	ft_putnbr_base(unsigned long long n, char *base, unsigned int len,
			int *printed);
void	ft_putnbr(int n, int *printed);
int		ft_putchar(char c);

#endif
