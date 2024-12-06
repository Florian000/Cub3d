/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:10:49 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:58:10 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Name
   strlcat - size-bounded string copying and concatenation
   Library
   Utility functions from BSD systems (libbsd, -lbsd)
   Synopsis
#include <bsd/string.h>
size_t  strlcat(char *dst, const char *src, size_t size);
Description
The strlcpy() and strlcat() functions copy and concatenate strings 
respectively.
They are designed to be safer, more consistent, and less error prone 
replacements The strlcpy() function copies up to size - 1 characters from the 
NUL-terminated string src to dst, NUL-terminating the result.for strncpy(3) 
and strncat(3). The strlcpy() function copies up to size - 1 characters from 
the NUL-terminated string src to dst, NUL-terminating the result.
Unlike those functions, strlcpy() and strlcat() take the full size of the 
buffer (not just the length) and guarantee to NUL-terminate the result (as
long as size is larger than 0 or, in the case of strlcat(), as long as 
there is at least one byte free in dst). Note that a byte for the NUL 
should be included in size. Also note that strlcpy() and 
strlcat() only operate on true ''C'' strings. This means that for strlcpy() 
src must be NUL-terminated and for strlcat() both src and dst must be 
NUL-terminated.

The strlcat() function appends the NUL-terminated string src to the end of dst.
It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the result

Return Values
The strlcpy() and strlcat() functions return the total length of the string the
tried to create. For strlcpy() that means the length of src. For strlcat()
that means the initial length of dst plus the length of src. While this 
may seem somewhat confusing, it was done to make truncation detection simple.

Note, however, that if strlcat() traverses size characters without finding a
the length of the string is considered to be size and the destination string 
will not be NUL-terminated (since there was no space for the NUL). 
This keeps strlcat() from running off the end of a string. In practice 
this should not happen (as it means that either size is incorrect or 
that dst is not a proper ''C'' string). The check exists to prevent 
potential security problems in incorrect code.

*/

#include "../../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	if ((!dst && size == 0) || (!src && size == 0))
		return (0);
	while (dst[len] && len < size)
		len++;
	while (src[i] && size && len + i < size -1)
	{
		dst[len + i] = src[i];
		i++;
	}
	if (len < size)
		dst[len + i] = 0;
	i = 0;
	while (src[i])
		i++;
	return (len + i);
}
