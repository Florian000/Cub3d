/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:08:51 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:35:43 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

   ft_putchar_fd
Prototype :         void ft_putchar_fd(char c, int fd);
Description :       Outputs the char c to the file descriptor fd.
Param. #1 :         The character to output.
Param. #2 :         The file descriptor.
Return value :      None.
Libc functions :    write(2).

*/

#include "../../includes/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
