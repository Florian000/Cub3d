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

int	check_first_args(char *str)
{
	if (*str && str[0] == '\n')
		return (VALID);
	if (ft_strncmp(str, "NO ", 3) == VALID
		|| ft_strncmp(str, "SO ", 3) == VALID
		|| ft_strncmp(str, "WE ", 3) == VALID
		|| ft_strncmp(str, "EA ", 3) == VALID)
		return (VALID);
	if (ft_strncmp(str, "C ", 2) == VALID
		|| ft_strncmp(str, "F ", 2) == VALID)
		return (VALID);
	return (INVALID);
}

int	add_texture_to_data(char **tab)
{
	t_textures	*t;

	t = get_data()->textures;
	if (!tab[0] || !tab[1])
		return (err("Invalid texture format or missing arguments"));
	if (ft_strncmp(tab[0], "NO", 3) == VALID)
	{
		if (t->NO->path != NULL)
			return (INVALID);
		if (t->NO == NULL)
		{
			t->NO = malloc(sizeof(*(t->NO)));
			if (!t->NO)
				return (err("bad malloc"));
		}
		if (t->NO->path)
			free(t->NO->path);
		t->NO->path = ft_strdup(tab[1]);
		if (!t->NO->path)
			return (err("bad malloc"));
	}
	else if (ft_strncmp(tab[0], "SO", 3) == VALID)
	{
		if (t->SO->path != NULL)
			return (INVALID);
		if (t->SO == NULL)
		{
			t->SO = malloc(sizeof(*(t->SO)));
			if (!t->SO)
				return (err("bad malloc"));
		}
		if (t->SO->path)
			free(t->SO->path);
		t->SO->path = ft_strdup(tab[1]);
		if (!t->SO->path)
			return (err("bad malloc"));
	}
	else if (ft_strncmp(tab[0], "WE", 3) == VALID)
	{
		if (t->WE->path != NULL)
			return (INVALID);
		if (t->WE == NULL)
		{
			t->WE = malloc(sizeof(*(t->WE)));
			if (!t->WE)
				return (err("bad malloc"));
		}
		if (t->WE->path)
			free(t->WE->path);
		t->WE->path = ft_strdup(tab[1]);
		if (!t->WE->path)
			return (err("bad malloc"));
	}
	else if (ft_strncmp(tab[0], "EA", 3) == VALID)
	{
		if (t->EA->path != NULL)
			return (INVALID);
		if (t->EA == NULL)
		{
			t->EA = malloc (sizeof(*(t->EA)));
			if (!t->EA)
				return (err("bad malloc"));
		}
		if (t->EA->path)
			free(t->EA->path);
		t->EA->path = ft_strdup(tab[1]);
		if (!t->EA->path)
			return (err("bad malloc"));
	}
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

int	add_color_to_data(char **nb, char *color)
{
	t_color	*c;

	if (ft_strncmp(color, "F", 2) == VALID)
	{
		c = get_data()->F;
		c->R = ft_atoi(nb[0]);
		c->G = ft_atoi(nb[1]);
		c->B = ft_atoi(nb[2]);
	}
	if (ft_strncmp(color, "C", 2) == VALID)
	{
		c = get_data()->C;
		c->R = ft_atoi(nb[0]);
		c->G = ft_atoi(nb[1]);
		c->B = ft_atoi(nb[2]);
	}
	return (VALID);
}
