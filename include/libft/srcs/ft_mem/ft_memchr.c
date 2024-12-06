/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:08:13 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:32:43 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

   Description
   The C library function void *memchr(const void *str, int c, size_t n) 
   searches for the first occurrence of the character c (an unsigned char) 
   in the first n bytes of the string pointed to, by the argument str.
   Declaration
   void *memchr(const void *str, int c, size_t n)
   Parameters
   str − This is the pointer to the block of memory where the search is 
   performed. c − This is the value to be passed as an int, but the 
   function performs a 
   byte per byte search using the unsigned char conversion of this value.
   n − This is the number of bytes to be analyzed.
   Return Value
   This function returns a pointer to the matching byte or NULL if the character 
   does not occur in the given memory area.

*/

#include "../../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char )c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
