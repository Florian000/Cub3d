/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:07:38 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:31:40 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   Function name ft_lstmap
   Prototype t_list *ft_lstmap(t_list *lst, void *(*f)(void *),
   void (*del)(void *));
   Fichiers de rendu -
   Paramètres lst: L’adresse du pointeur vers un élément.
f: L’adresse de la fonction à appliquer.
del: L’adresse de la fonction permettant de
supprimer le contenu d’un élément.
Valeur de retour La nouvelle liste.
NULL si l’allocation échoue
Fonctions externes autorisées
malloc, free
Description Itère sur la liste ’lst’ et applique la fonction
’f ’au contenu de chaque élément. Crée une nouvelle
liste résultant des applications successives de
’f’. La fonction ’del’ est là pour détruire le
contenu d’un élément si nécessaire.
*/

#include "../../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*first;

	if (!lst || !f || !del)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	first = new;
	lst = lst->next;
	while (lst)
	{
		new->next = ft_lstnew(f(lst->content));
		if (!new->next)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	new->next = NULL;
	return (first);
}
