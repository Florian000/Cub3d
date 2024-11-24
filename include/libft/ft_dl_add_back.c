/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:18:10 by jvittoz           #+#    #+#             */
/*   Updated: 2024/11/08 13:18:12 by jvittoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dl_add_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*last;

	if (!new)
		return ;
	if (lst)
	{
		if (!*lst)
			*lst = new;
		else
		{
			last = ft_dl_last(*lst);
			last->next = new;
			new->prev = last;
		}
	}
}
