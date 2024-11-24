/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:17:01 by jvittoz           #+#    #+#             */
/*   Updated: 2024/11/08 13:17:02 by jvittoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dl_del(t_dlist *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	if (lst->prev && lst->next)
	{
		lst->prev->next = lst->next;
		lst->next->prev = lst->prev;
	}
	else if (lst->prev)
		lst->prev->next = NULL;
	else if (lst->next)
		lst->next->prev = NULL;
	(*del)(lst->data);
	free(lst);
	lst = NULL;
}
