/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:10:24 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:52:56 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

   NAME         
   strchr - locate character in string
   SYNOPSIS         
#include <string.h>
char *strchr(const char *s, int c);
DESCRIPTION         
The strchr() function returns a pointer to the first occurrence
of the character c in the string s.
Here "character" means "byte"; these functions do not work with
wide or multibyte characters.
RETURN VALUE         
The strchr() and strrchr() functions return a pointer to the
matched character or NULL if the character is not found.  The
terminating null byte is considered part of the string, so that
if c is specified as '\0', these functions return a pointer to
the terminator.

*/

#include "../../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (c == 0)
		return ((char *)(s + i));
	return (NULL);
}
