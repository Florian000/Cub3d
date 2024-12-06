/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:11:20 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 17:23:10 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   NAME         
   strncmp - compare two strings
   SYNOPSIS         
#include <string.h>
int strncmp(const char *s1, const char *s2, size_t n);
DESCRIPTION         
The strcmp() function compares the two strings s1 and s2.  The
locale is not taken into account (for a locale-aware comparison,
see strcoll(3)).  The comparison is done using unsigned
characters.

strcmp() returns an integer indicating the result of the
comparison, as follows:

• 0, if the s1 and s2 are equal;

• a negative value if s1 is less than s2;

• a positive value if s1 is greater than s2.

The strncmp() function is similar, except it compares only the
first (at most) n bytes of s1 and s2.
RETURN VALUE
The strcmp() and strncmp() functions return an integer less than,
equal to, or greater than zero if s1 (or the first n bytes
thereof) is found, respectively, to be less than, to match, or be
greater than s2.
*/

#include "../../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && (unsigned char)s1[i] == (unsigned char)s2[i]
		&& i < n -1)
		i++;
	if (n == 0)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
