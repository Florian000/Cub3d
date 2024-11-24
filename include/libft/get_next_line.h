/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 03:33:52 by jvittoz           #+#    #+#             */
/*   Updated: 2024/03/18 04:08:26 by jvittoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		ft_strlen(char *str);
char	*ft_join(char *s1, char *s2);
int		ft_fnl(char *str);
char	*ft_add_to_buff(char *Lbuffer, char *Sbuffer);
char	*ft_read_line(int fd, char *Lbuffer);
char	*ft_get_line(char *Lbuffer);
char	*ft_clean_buffer(char *Lbuffer);
char	*get_next_line(int fd);
#endif
