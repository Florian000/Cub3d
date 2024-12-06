/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:48:36 by fgranger          #+#    #+#             */
/*   Updated: 2023/12/28 12:43:43 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
   • %c Prints a single character.
   • %s Prints a string (as defined by the common C convention).
   • %p The void * pointer argument has to be printed in hexadecimal format. 
   • %i Prints an integer in base 10.
   • %u Prints an unsigned decimal (base 10) number.
   • %x Prints a number in hexadecimal (base 16) lowercase format. 
   • %X Prints a number in hexadecimal (base 16) uppercase format.
   • %% Prints a percent sign. --> putchar with %
*/

int	ft_get_conv(char c)
{
	char	*conv;
	int		i;

	conv = "cspdiuxX%";
	i = 0;
	while (conv)
	{
		if (conv[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	(*ft_get_function(char c)) (va_list args)
{
	int	(*f[9])(va_list);

	f[0] = &ft_c;
	f[1] = &ft_s;
	f[2] = &ft_p;
	f[3] = &ft_d;
	f[4] = &ft_i;
	f[5] = &ft_u;
	f[6] = &ft_x;
	f[7] = &ft_xucase;
	f[8] = &ft_mod;
	return (f[ft_get_conv(c)]);
}

int	ft_print_conv(char c, va_list args)
{
	int	(*f)(va_list);

	f = ft_get_function(c);
	return (f(args));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	len = 0;
	i = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_print_conv(str[i++], args);
		}
		if (!str[i])
			break ;
		if (str[i] != '%')
			len += ft_putchar(str[i++]);
	}
	va_end(args);
	return (len);
}

/*
#include <stdio.h>

int		main()
{
	int	*a;
	int	b;

	b = __INT_MAX__;
	a = &b;
	ft_printf("ft   :%%\n");
	printf("orignal :%%");
	return(0);
}
*/
