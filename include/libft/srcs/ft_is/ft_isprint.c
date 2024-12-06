/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:06:26 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:23:13 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

   Name
   isprint,

   Synopsis
#include <ctype.h>

int isprint(int c);

Description
These functions check whether c, which must have the value of an
unsigned char or EOF, falls into a certain character class 
according to the current locale.
isprint()
checks for any printable character including space.

Return Value
The values returned are nonzero if the character c falls into 
the tested class, and a zero value if not.

*/

#include "../../includes/libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
