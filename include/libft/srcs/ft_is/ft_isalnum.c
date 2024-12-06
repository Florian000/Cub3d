/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:05:18 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:20:15 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

   Name
   isalnum,

   Synopsis
#include <ctype.h>
int isalnum(int c);

Description
These functions check whether c, which must have the value of an unsigned
char or EOF, falls into a certain character class according to the current 
locale.
isalnum() checks for an alphanumeric character; it is equivalent to 
(isalpha(c) || isdigit(c)).

Return Value
The values returned are nonzero if the character c falls into the tested 
class, and a zero value if not.

*/

#include "../../includes/libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
