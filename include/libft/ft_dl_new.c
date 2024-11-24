/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:16:34 by jvittoz           #+#    #+#             */
/*   Updated: 2024/11/08 13:16:35 by jvittoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dl_new(void *data)
{
	t_dlist	*list;

	list = malloc(sizeof(t_dlist));
	if (!list)
		return (NULL);
	list->data = data;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}
