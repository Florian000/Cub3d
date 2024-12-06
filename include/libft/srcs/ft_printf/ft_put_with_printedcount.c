/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:02:22 by fgranger          #+#    #+#             */
/*   Updated: 2022/12/03 21:14:31 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putnbr_base(unsigned long long n, char *base, unsigned int len,
		int *printed)
{
	if (n >= len)
		ft_putnbr_base(n / len, base, len, &(*printed));
	ft_putchar_fd(base[n % len], 1);
	*printed += 1;
}

void	ft_putnbr(int n, int *printed)
{
	long int	nb;

	nb = n;
	if (n < 0)
	{
		write(1, "-", 1);
		*printed += 1;
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10, &(*printed));
	ft_putchar_fd("0123456789"[nb % 10], 1);
	*printed += 1;
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
