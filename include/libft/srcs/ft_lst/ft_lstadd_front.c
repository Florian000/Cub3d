/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:06:53 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:26:34 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   Function name                   : ft_lstadd_front
Prototype                       : void ft_lstadd_front(t_list **lst, t_list 
*new);
Fichiers de rendu               : -
Paramètres                      : lst: L’adresse du pointeur vers le premier 
								élément de la liste.
								  new: L’adresse du pointeur vers l’élément 
								  à rajouter à la liste.
Valeur de retour                : Aucune
Fonctions externes autorisées   : Aucune
Description                     : Ajoute l’élément ’new’ au début de la liste.
*/

#include "../../includes/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
