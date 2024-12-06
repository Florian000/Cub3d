/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:09:34 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:38:10 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   NAME
   tolower,
   SYNOPSIS
#include <ctype.h>
int tolower(int c);
DESCRIPTION
These functions convert lowercase letters to uppercase, and vice
versa.

If c is an uppercase letter, tolower() returns its lowercase
equivalent, if a lowercase representation exists in the current
locale.  Otherwise, it returns c.

If c is neither an unsigned char value nor EOF, the behavior of
these functions is undefined.
RETURN VALUE
The value returned is that of the converted letter, or c if the
conversion was not possible.
*/

#include "../../includes/libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
