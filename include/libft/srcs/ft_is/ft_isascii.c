/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:05:37 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:21:42 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

   Name
   isascii,

   Synopsis
#include <ctype.h>
int isascii(int c);

Description
These functions check whether c, which must have the value of an unsigned 
char or EOF, falls into a certain character class according to the 
current locale.
isascii() checks whether c is a 7-bit unsigned char value that fits into 
the ASCII character set.

Return Value
The values returned are nonzero if the character c falls into the 
tested class, and a zero value if not.

*/

#include "../../includes/libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
