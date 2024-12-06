/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:06:43 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:29:24 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   Function name ft_lstadd_back
   Prototype void ft_lstadd_back(t_list **lst, t_list *new);
   Fichiers de rendu -
   Paramètres lst: L’adresse du pointeur vers le premier élément
   de la liste.
new: L’adresse du pointeur vers l’élément à
rajouter à la liste.
Valeur de retour Aucune
Fonctions externes autorisées
Aucune
Description Ajoute l’élément ’new’ à la fin de la liste
*/

#include "../../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst)
	{
		last = ft_lstlast(*lst);
		last->next = &*new;
	}
	else
		*lst = new;
}
