/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:11:06 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:47:46 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

   Name
   strlen - calculate the length of a string
   Synopsis
#include <string.h>
size_t strlen(const char *s);
Description
The strlen() function calculates the length of the string s, excluding 
the terminating null byte (aq\0aq).
Return Value
The strlen() function returns the number of bytes in the string s.
*/

#include "../../includes/libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
