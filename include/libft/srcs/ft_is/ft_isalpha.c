/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:05:27 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:25:19 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

   Name
   isalpha,

   Synopsis
#include <ctype.h>
int isalpha(int c);

Description
These functions check whether c, which must have the value of an unsigned 
char or EOF, falls into a certain character class according to the 
current locale.
isalpha() checks for an alphabetic character; in the standard "C" locale, 
it is equivalent to (isupper(c) || islower(c)). In some locales, there may 
be additional characters for which isalpha() is true-letters which are 
neither upper case nor lower case.

Return Value
The values returned are nonzero if the character c falls into the tested 
class, and a zero value if not.

*/

#include "../../includes/libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
