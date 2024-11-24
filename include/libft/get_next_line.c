/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 03:33:00 by jvittoz           #+#    #+#             */
/*   Updated: 2024/04/06 13:17:40 by jvittoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_add_to_buff(char *l_buffer, char *s_buffer)
{
	char	*res;

	if (l_buffer == 0)
	{
		l_buffer = malloc(1 * sizeof(char));
		if (l_buffer == NULL)
			return (NULL);
		l_buffer[0] = 0;
	}
	if (!l_buffer[0] && !s_buffer[0])
	{
		free(l_buffer);
		return (NULL);
	}
	res = ft_join(l_buffer, s_buffer);
	free(l_buffer);
	return (res);
}

char	*ft_read_line(int fd, char *l_buffer)
{
	char	*s_buffer;
	int		byte;

	s_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (s_buffer == NULL)
		return (NULL);
	byte = 1;
	while (byte > 0 && ft_fnl(l_buffer) == -1)
	{
		byte = read(fd, s_buffer, BUFFER_SIZE);
		if (byte == -1)
		{
			free (s_buffer);
			return (NULL);
		}
		s_buffer[byte] = 0;
		l_buffer = ft_add_to_buff(l_buffer, s_buffer);
	}
	free(s_buffer);
	return (l_buffer);
}

char	*ft_get_line(char *l_buffer)
{
	int		new_line;
	int		i;
	char	*res;

	new_line = ft_fnl(l_buffer);
	if (new_line == -1)
		new_line = ft_strlen2(l_buffer) - 1;
	res = malloc ((new_line + 2) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < new_line + 1)
	{
		res[i] = l_buffer[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

char	*ft_clean_buffer(char	*l_buffer)
{
	int		i;
	int		new_line;
	int		len;
	char	*res;

	len = ft_strlen2(l_buffer);
	new_line = ft_fnl(l_buffer);
	res = malloc((len - new_line) * sizeof(char));
	if (res == NULL || new_line == -1)
	{
		if (res)
			free(res);
		free(l_buffer);
		return (NULL);
	}
	i = 0;
	while (new_line + i + 1 < len)
	{
		res[i] = l_buffer[new_line + i + 1];
		i++;
	}
	res[i] = 0;
	free(l_buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*l_buffer;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	l_buffer = ft_read_line(fd, l_buffer);
	if (l_buffer == NULL)
		return (NULL);
	if (l_buffer[0] == 0)
	{
		free(l_buffer);
		return (NULL);
	}
	res = ft_get_line(l_buffer);
	l_buffer = ft_clean_buffer(l_buffer);
	return (res);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main()
{
	int		fd;
	char	*str;

	fd = open("get_next_line.h", O_RDONLY);
	while(1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		printf("%s",str);
		free(str);
	}
	close(fd);
	return (0);
}
*/
