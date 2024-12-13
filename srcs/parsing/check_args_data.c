/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:03:41 by jvittoz           #+#    #+#             */
/*   Updated: 2024/12/08 19:47:24 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	sub_add_txt(t_texture *t, char **tab)
{
	if (t->path != NULL)
		return (INVALID);
	if (t == NULL)
	{
		t = malloc(sizeof(t_texture));
		if (!t)
			return (err("bad malloc"));
	}
	if (t->path)
		free(t->path);
	t->path = ft_strdup(tab[1]);
	if (!t->path)
		return (err("bad malloc"));
	return (VALID);
}

int	add_texture_to_data(char **tab)
{
	t_textures	*t;

	t = get_data()->textures;
	if (!tab[0] || !tab[1])
		return (err("Invalid texture format or missing arguments"));
	if (ft_strncmp(tab[0], "NO", 3) == VALID)
		return (sub_add_txt(t->no, tab));
	else if (ft_strncmp(tab[0], "SO", 3) == VALID)
		return (sub_add_txt(t->so, tab));
	else if (ft_strncmp(tab[0], "WE", 3) == VALID)
		return (sub_add_txt(t->we, tab));
	else if (ft_strncmp(tab[0], "EA", 3) == VALID)
		return (sub_add_txt(t->ea, tab));
	else
		return (err("Unknown texture identifier"));
	return (VALID);
}

int	add_texture(char *str)
{
	char	**tab;
	int		result;

	tab = ft_split(str, ' ');
	if (!tab)
		return (INVALID);
	if (tab[0] && tab[1] && !tab[2])
	{
		result = add_texture_to_data(tab);
		return (ft_free2(result, tab));
	}
	return (ft_free2(INVALID, tab));
}

int	check_color(char **nb)
{
	int	i;

	i = 0;
	if (!nb)
		return (INVALID);
	while (nb[i])
		i++;
	if (i != 3)
		return (INVALID);
	i = 0;
	while (nb[i])
	{
		if (ft_atoi(nb[i]) > 255 || ft_atoi(nb[i]) < 0)
			return (INVALID);
		i++;
	}
	return (VALID);
}

int	ft_isnotdigit(char c)
{
	if (c < '0' || c > '9')
		return (VALID);
	return (INVALID);
}
