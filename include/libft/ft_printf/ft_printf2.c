/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jvittoz <marvin@42.fr>					 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/11/21 12:57:48 by jvittoz		   #+#	#+#			 */
/*   Updated: 2023/12/11 07:24:06 by jvittoz          ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putunbr(unsigned int i)
{
	if (i > 9)
	{
		ft_putunbr(i / 10);
		ft_putchar((i % 10) + 48);
		return ;
	}
	ft_putchar((i % 10) + 48);
}

void	ft_putptr(void *p)
{
	unsigned long long	n;

	n = (unsigned long long)p;
	if (p == 0)
	{
		ft_putstr("(nil)");
		return ;
	}
	ft_putstr("0x");
	ft_putnbr_basep(n, "0123456789abcdef");
}

int	ft_print_c(int arg)
{
	ft_putchar(arg);
	return (1);
}

int	ft_print_s(char *arg)
{
	if (arg == 0)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(arg);
	return (ft_strlen(arg));
}

int	ft_print_p(void *p)
{
	ft_putptr(p);
	return (ft_count_ptr(p));
}
