/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:10:57 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:59:22 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   Name
   strlcpy - size-bounded string copying

   Synopsis
#include <bsd/string.h>

size_t strlcpy(char *dst, const char *src, size_t size);

Description
The strlcpy() and strlcat() functions copy and concatenate strings 
respectively. They are designed to be safer, more consistent, and 
less error prone replacements for strncpy(3) and strncat(3). Unlike 
those functions, strlcpy() and strlcat() take the full size of the buffer 
(not just the length) and guarantee to NUL-terminate the result (as long 
as size is larger than 0 or, in the case of strlcat(), as long as 
there is at least one byte free in dst). Note that a byte for the NUL 
should be included in size. Also note that strlcpy() and strlcat() only 
operate on true ''C'' strings. This means that for strlcpy() src must be 
NUL-terminated and for strlcat() both src and dst must be NUL-terminated.

The strlcpy() function copies up to size - 1 characters from the
NUL-terminated string src to dst, NUL-terminating the result.

Return Values
The strlcpy() and strlcat() functions return the total length 
of the string they tried to create. For strlcpy() that means the length 
of src. While this may seem somewhat confusing, it was done 
to make truncation detection simple.

*/

#include "../../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(src);
	j = 0;
	if (i + 1 < size)
	{
		while (j < i + 1)
		{
			dst[j] = src[j];
			j++;
		}
	}
	else if (size > 0)
	{
		while (j < size - 1)
		{
			dst[j] = src[j];
			j++;
		}
		dst[j] = 0;
	}
	return (i);
}
