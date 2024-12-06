/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:08:19 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:33:57 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

   Description
   The C library function int memcmp(const void *s1, const void *s2, size_t n))
   compares the first n bytes of memory area s1 and memory area s2.
   Declaration
   int memcmp(const void *s1, const void *s2, size_t n)
   Parameters
   s1 − This is the pointer to a block of memory.
   s2 − This is the pointer to a block of memory.
   n − This is the number of bytes to be compared.
   Return Value
   if Return value < 0 then it indicates s1 is less than s2.
   if Return value > 0 then it indicates s2 is less than s1.
   if Return value = 0 then it indicates s1 is equal to s2.

*/

#include "../../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
