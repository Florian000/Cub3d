/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:06:33 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:25:05 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Function :          name ft_itoa
Prototype :         char *ft_itoa(int n);
Turn in files -
Parameters #1 :     The integer to convert.
Return value :      The string representing the integer. NULL if the 
					allocation fails.
External functs :   malloc
Description :       Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.

*/

#include "../../includes/libft.h"

static int	ft_size(long int n)
{
	int	size;

	size = 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int			size;
	char		*nb;
	long int	nbr;

	nbr = n;
	size = ft_size(nbr) + (nbr < 0);
	nb = NULL;
	nb = ft_calloc(size + 1, sizeof(char));
	if (!nb)
		return (NULL);
	if (nbr < 0)
	{
		nb[0] = '-';
		nbr = -nbr;
	}
	nb[size--] = 0;
	while (nbr >= 10)
	{
		nb[size--] = nbr % 10 + 48;
		nbr = nbr / 10;
	}
	nb[size] = nbr % 10 + 48;
	return (nb);
}
