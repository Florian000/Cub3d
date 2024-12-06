/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:07:59 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:31:56 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   Function name                   : ft_lstsize
Prototype                       : int ft_lstsize(t_list *lst);
Fichiers de rendu               : -
Paramètres                      : lst: Le début de la liste
Valeur de retour                : Taille de la liste
Fonctions externes autorisées   : Aucune
Description                     : Compte le nombre d’éléments de la liste.
*/

#include "../../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
