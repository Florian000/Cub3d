/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <florian.granger@student.42.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:47:50 by fgranger          #+#    #+#             */
/*   Updated: 2022/12/04 10:43:33 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strjoin_free(char *buffer, char *reading)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, reading);
	free(buffer);
	return (tmp);
}
