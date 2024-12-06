/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:07:09 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:27:15 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   Function name ft_lstdelone
   Prototype void ft_lstdelone(t_list *lst, void (*del)(void
 *));
 Fichiers de rendu -
 Paramètres lst: L’élément à free
del: L’adresse de la fonction permettant de
supprimer le contenu de l’élément.
Valeur de retour Aucune
Fonctions externes autorisées
free
Description Libère la mémoire de l’élément passé en argument en
utilisant la fonction ’del’ puis avec free(3). La
mémoire de ’next’ ne doit pas être free.
*/

#include "../../includes/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
