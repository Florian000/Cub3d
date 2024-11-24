/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jvittoz <marvin@42.fr>					 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/11/22 11:43:41 by jvittoz		   #+#	#+#			 */
/*   Updated: 2023/12/11 06:33:41 by jvittoz          ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_d(int arg)
{
	ft_putnbr(arg);
	return (ft_count_int(arg));
}

int	ft_print_x(unsigned int arg)
{
	ft_putnbr_base(arg, "0123456789abcdef");
	return (ft_count_base(arg));
}

int	ft_print_xup(unsigned int arg)
{
	ft_putnbr_base(arg, "0123456789ABCDEF");
	return (ft_count_base(arg));
}

int	ft_print_u(unsigned int arg)
{
	ft_putunbr(arg);
	return (ft_count_unsigned(arg));
}
