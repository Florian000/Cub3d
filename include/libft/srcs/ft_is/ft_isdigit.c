/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:06:18 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:22:06 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

   Name
   isdigit,

   Synopsis
#include <ctype.h>
int isdigit(int c);

Description
These functions check whether c, which must have the value of an unsigned 
char or EOF, falls into a certain character class according to the current
locale.
isdigit()
checks for a digit (0 through 9).

Return Value
The values returned are nonzero if the character c falls into the tested class,
and a zero value if not.

*/

#include "../../includes/libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
