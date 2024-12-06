/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:03:52 by fgranger          #+#    #+#             */
/*   Updated: 2024/12/06 20:06:51 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

   Name
   atoi, atol, atoll, atoq - convert a string to an integer
   Synopsis
#include <stdlib.h>
int atoi(const char *nptr);
Description
The atoi() function converts the initial portion of the string 
pointed to by nptr to int. The behavior is the same as 
strtol(nptr, NULL, 10);
except that atoi() does not detect errors.
Return Value
The converted value.

*/

#include "../../includes/libft.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}
