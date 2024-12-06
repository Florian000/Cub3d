/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:06:04 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 18:27:27 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

   Description
   The C library function void *calloc(size_t nitems, size_t size) allocates
   the requested memory and returns a pointer to it. The difference in malloc
   and calloc is that malloc does not set the memory to zero where as calloc 
   sets allocated memory to zero.
   Declaration
   void *calloc(size_t nitems, size_t size)
   Parameters
   nitems − This is the number of elements to be allocated.
   size − This is the size of elements.
   Return Value
   This function returns a pointer to the allocated memory, or NULL if the 
   request fails.
*/

#include "../../includes/libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*alloc;

	if (nitems >= SIZE_MAX || size >= SIZE_MAX)
		return (NULL);
	alloc = NULL;
	alloc = malloc(size * nitems);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, nitems * size);
	return (alloc);
}
