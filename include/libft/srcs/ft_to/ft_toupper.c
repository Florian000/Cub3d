/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:10:15 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:38:34 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   NAME
   toupper,
   SYNOPSIS
#include <ctype.h>
int toupper(int c);
DESCRIPTION
These functions convert lowercase letters to uppercase, and vice
versa.

If c is a lowercase letter, toupper() returns its uppercase
equivalent, if an uppercase representation exists in the current
locale.  Otherwise, it returns c.

If c is neither an unsigned char value nor EOF, the behavior of
these functions is undefined.
RETURN VALUE
The value returned is that of the converted letter, or c if the
conversion was not possible.
*/

#include "../../includes/libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
