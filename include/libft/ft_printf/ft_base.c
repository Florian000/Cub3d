/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jvittoz <marvin@42.fr>					 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/11/21 11:27:17 by jvittoz		   #+#	#+#			 */
/*   Updated: 2023/12/11 07:38:19 by jvittoz          ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write (1, &str[i++], 1);
}

void	ft_putnbr(int i)
{
	if (i == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	else
	{
		if (i < 0)
		{
			ft_putchar('-');
			ft_putnbr(i * -1);
			return ;
		}
		else if (i > 9)
		{
			ft_putnbr(i / 10);
			ft_putchar((i % 10) + 48);
			return ;
		}
		ft_putchar((i % 10) + 48);
	}
}

void	ft_putnbr_base(unsigned int i, char *base)
{
	unsigned int	size;

	size = ft_strlen(base);
	if (i >= size)
	{
		ft_putnbr_base(i / size, base);
		ft_putchar(base[i % size]);
		return ;
	}
	ft_putchar(base[i]);
}

void	ft_putnbr_basep(unsigned long long i, char *base)
{
	unsigned long long	size;

	size = ft_strlen(base);
	if (i >= size)
	{
		ft_putnbr_basep(i / size, base);
		ft_putchar(base[i % size]);
		return ;
	}
	ft_putchar(base[i]);
}
