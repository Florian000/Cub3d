/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:11:12 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:48:18 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   Function name ft_strmapi
   Prototype char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
   Fichiers de rendu -
   Paramètres s: La chaîne de caractères sur laquelle itérer.
f: La fonction à appliquer à chaque caractère.
Valeur de retour La chaîne de caractères résultant des applications 
successives de ’f’. Retourne NULL si l’allocation échoue.
Fonctions externes autorisées malloc
Description Applique la fonction ’f’ à chaque caractère de la chaîne de 
caractères passée en argument pour créer une nouvelle chaîne de caractères 
(avec malloc(3)) résultant des applications successives de ’f’.
*/

#include "../../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		i;

	if (!s || !f)
		return (NULL);
	new = NULL;
	new = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = f(i, s[i]);
		i++;
	}
	return (new);
}
