/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:13:09 by jvittoz           #+#    #+#             */
/*   Updated: 2024/11/08 13:18:45 by jvittoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free2(char **d_ptr, va_list line)
{
	int	j;

	d_ptr = va_arg(line, char **);
	j = 0;
	while (d_ptr[j])
		free(d_ptr[j++]);
	free(d_ptr);
	return (j);
}

int	ft_free(int return_val, char *str, ...)
{
	va_list	line;
	void	*ptr;
	char	**d_ptr;
	int		i;

	va_start(line, str);
	i = 0;
	d_ptr = NULL;
	while (str[i])
	{
		if (str[i] == 'v')
		{
			ptr = va_arg(line, void *);
			free(ptr);
		}
		else if (str[i] == 's')
			ft_free2(d_ptr, line);
		i++;
	}
	va_end(line);
	return (return_val);
}
