/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:08:58 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:36:14 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

   ft_putendl_fd
Prototype :             void ft_putendl_fd(char const *s, int fd);
Description Outputs :   Outputs the string s to the file descriptor fd 
followed by a ’\n’.
Param. #1 :             The string to output.
Param. #2 :             The file descriptor.
Return value :          None.
Libc functions :        write(2).

*/

#include "../../includes/libft.h"

void	ft_putendl_fd(const char *s, int fd)
{
	if (s)
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}
