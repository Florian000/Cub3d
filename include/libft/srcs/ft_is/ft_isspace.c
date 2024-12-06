/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:06:26 by fgranger          #+#    #+#             */
/*   Updated: 2024/12/06 20:07:10 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

   Name
   isspqce

   Synopsis
int isspace(int c);

Description
These functions check whether c, which must have the value of an
unsigned char or EOF, falls into a certain character class 
according to the current locale.
isspace()
checks for any spaces

Return Value
The values returned are nonzero if the character c falls into 
the tested class, and a zero value if not.

*/

#include "../../includes/libft.h"

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}