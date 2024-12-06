/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:09:04 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:37:36 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   ft_putnbr_fd
Prototype :             void ft_putnbr_fd(int n, int fd);
Description Outputs :   Outputs the integer n to the file descriptor fd.
Param. #1 :             The integer to print.
Param. #2 :				The file descriptor.
Return value :          None.
Libc functions :        write(2).
*/

#include "../../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;

	nb = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	write(fd, &"0123456789"[nb % 10], 1);
}
