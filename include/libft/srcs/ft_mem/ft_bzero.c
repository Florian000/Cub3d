/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:05:58 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:16:18 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

   NAME         
   bzero - zero a byte string
   SYNOPSIS         
#include <strings.h>
void bzero(void *s, size_t n);
DESCRIPTION         
The bzero() function erases the data in the n bytes of the memory
starting at the location pointed to by s, by writing zeros (bytes
containing '\0') to that area.
The explicit_bzero() function performs the same task as bzero().
It differs from bzero() in that it guarantees that compiler
optimizations will not remove the erase operation if the compiler
deduces that the operation is "unnecessary".
RETURN VALUE         
None.

*/

#include "../../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
	{
		*(char *)(s + i) = 0;
	}
}
