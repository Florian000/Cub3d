/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_add_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:17:59 by jvittoz           #+#    #+#             */
/*   Updated: 2024/11/08 13:18:00 by jvittoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dl_add_front(t_dlist **lst, t_dlist *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
	{
		new->next = *lst;
		(*lst)->prev = new;
	}
	*lst = new;
}
