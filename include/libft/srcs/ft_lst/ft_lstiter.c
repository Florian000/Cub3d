/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:07:20 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:31:15 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   Function name ft_lstiter
   Prototype void ft_lstiter(t_list *lst, void (*f)(void *));
   Fichiers de rendu -
   Paramètres lst: L’adresse du pointeur vers un élément.
f: L’adresse de la fonction à appliquer.
Valeur de retour Aucune
Fonctions externes autorisées
Aucune
Description Itère sur la liste ’lst’ et applique la fonction
’f’ au contenu chaque élément.
*/

#include "../../includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst && f)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}
