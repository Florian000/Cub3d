/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:11:39 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 17:00:53 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

   NAME         
   strrchr - locate character in string
   SYNOPSIS         
#include <string.h>
char *strrchr(const char *s, int c);
DESCRIPTION         
The strrchr() function returns a pointer to the last occurrence
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

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
