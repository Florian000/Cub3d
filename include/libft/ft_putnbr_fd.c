/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:00:55 by jvittoz           #+#    #+#             */
/*   Updated: 2023/12/08 09:25:46 by jvittoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	temp;

	temp = n;
	if (temp < 0)
	{
		ft_putchar_fd('-', fd);
		temp = temp * (-1);
	}
	if (temp >= 10)
	{
		ft_putnbr_fd(temp / 10, fd);
		ft_putchar_fd((temp % 10) + 48, fd);
		return ;
	}
	ft_putchar_fd(temp + 48, fd);
}
