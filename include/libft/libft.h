/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:04:33 by jvittoz           #+#    #+#             */
/*   Updated: 2024/11/08 13:17:51 by jvittoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_dlist
{
	void			*data;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}	t_dlist;

enum e_yn
{
	yes = 1,
	no = 0
};

int		ft_strlen2(const char *str);
int		ft_isalpha(int n);
int		ft_isdigit(int n);
int		ft_isalnum(int n);
int		ft_isascii(int n);
int		ft_isprint(int n);
int		ft_atoi(const char *s);
char	*ft_itoa(int i);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
void	*ft_calloc(size_t num, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	**ft_space_split(char const *s);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strtrim(char const *s1, char const *s2);
char	**ft_split(const char *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_dl_size(t_dlist *list);
void	ft_dl_swap(t_dlist *a, t_dlist *b);
void	ft_dl_sort(t_dlist *list, int (*sort_cmp)(void *, void *));
void	ft_dl_clear(t_dlist **lst, void (*del)(void *));
void	ft_dl_add_back(t_dlist **lst, t_dlist *new);
char	*ft_strtrim(char const *s, char const *set);
void	ft_dl_add_front(t_dlist **lst, t_dlist *new);
void	ft_dl_del(t_dlist *lst, void (*del)(void *));
t_dlist	*ft_dl_last(t_dlist *lst);
t_dlist	*ft_dl_new(void *data);
t_dlist	*ft_dl_remove_from(t_dlist **lst, t_dlist *elem, void (*del)(void *));
int		ft_isspace(char c);
int		ft_free(int return_val, char *str, ...);
char	*get_next_line(int fd);
int		ft_fnl(char *str);
char	*ft_add_to_buff(char *Lbuffer, char *Sbuffer);
char	*ft_read_line(int fd, char *Lbuffer);
char	*ft_get_line(char *Lbuffer);
char	*ft_clean_buffer(char *Lbuffer);

#endif
