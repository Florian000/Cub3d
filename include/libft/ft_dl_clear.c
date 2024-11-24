/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:17:13 by jvittoz           #+#    #+#             */
/*   Updated: 2024/11/08 13:17:15 by jvittoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dl_clear(t_dlist **lst, void (*del)(void *))
{
	t_dlist	*next;

	if (lst)
	{
		while (*lst)
		{
			next = (*lst)->next;
			ft_dl_del(*lst, del);
			*lst = next;
		}
	}
}
