/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:10:30 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:53:23 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   NAME
   strdup - duplicate a string
   SYNOPSIS
#include <string.h>
char *strdup(const char *s);
DESCRIPTION
The strdup() function returns a pointer to a new string which is
a duplicate of the string s.  Memory for the new string is
obtained with malloc(3), and can be freed with free(3).
RETURN VALUE
On success, the strdup() function returns a pointer to the
duplicated string.  It returns NULL if insufficient memory was
available, with errno set to indicate the error.
ERRORS
ENOMEM Insufficient memory available to allocate duplicate
string.
*/

#include "../../includes/libft.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (*src)
		dest[i++] = *src++;
	dest[i] = 0;
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*str;

	str = NULL;
	str = (char *) malloc(sizeof(char) * ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	return (ft_strcpy(str, s));
}
