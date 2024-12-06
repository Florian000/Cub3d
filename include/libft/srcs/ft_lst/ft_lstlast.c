/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:07:29 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:27:54 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   Function name ft_lstlast
   Prototype t_list *ft_lstlast(t_list *lst);
   Fichiers de rendu -
   Paramètres lst: Le début de la liste.
   Valeur de retour Dernier élément de la liste
   Fonctions externes autorisées
   Aucune
   Description Renvoie le dernier élément de la liste.
   */

#include "../../includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
