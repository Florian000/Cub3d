/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:09:10 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:36:58 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

   ft_putstr_fd
Prototype :             void ft_putstr_fd(char const *s, int fd);
Description Outputs :   Outputs the string s to the file descriptor fd.
Param. #1 :             The string to output.
Param. #2 :             The file descriptor.
Return value :          None.
Libc functions :        write(2).

*/

#include "../../includes/libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}
