/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:10:42 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:54:37 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   ft_strjoin
Prototype :             char	*ft_strjoin(char const *s1, char const *s2);
Description Outputs :   Alloue (avec malloc(3)) et retourne une chaine de 
caractères
“fraiche” terminée par un ’\0’ résultant de la concaténation
de s1 et s2. Si l’allocation echoue, la fonction renvoie NULL.
Param. #1 :             La chaine de caractères préfixe.
Param. #2 :             Li l’allocation echoue, la fonction renvoie NULL.
Param. #1 :             La chaine de caractères préfixe.a chaine de caractères 
suffixe.
Return value :          La chaine de caractère “fraiche” résultant de la 
concaténation
des deux chaines.
Libc functions :        malloc(3).
*/

#include "../../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	new = NULL;
	new = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!new)
		return (NULL);
	ft_memcpy(new, s1, ft_strlen(s1));
	ft_memcpy(new + ft_strlen(s1), s2, ft_strlen(s2));
	return (new);
}
