/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:04:08 by jvittoz           #+#    #+#             */
/*   Updated: 2024/12/08 20:14:00 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	init_c(t_data *data)
{
	t_color	*c;

	if (!data)
		return (INVALID);
	c = malloc(sizeof(t_color));
	if (!c)
		return (INVALID);
	c->b = -1;
	c->g = -1;
	c->r = -1;
	data->c = c;
	return (VALID);
}

int	init_f(t_data *data)
{
	t_color	*c;

	if (!data)
		return (INVALID);
	c = malloc(sizeof(t_color));
	if (!c)
		return (INVALID);
	c->b = -1;
	c->g = -1;
	c->r = -1;
	data->f = c;
	return (VALID);
}

t_texture	*init_texture(void)
{
	t_texture	*res;

	res = malloc(sizeof(t_texture));
	if (!res)
		return (NULL);
	res->data = NULL;
	res->color = NULL;
	res->height = 0;
	res->key = NULL;
	res->lines = NULL;
	res->nb_colors = 0;
	res->path = NULL;
	res->width = 0;
	return (res);
}

int	init_textures(t_data *data)
{
	t_textures	*t;

	if (!data)
		return (INVALID);
	t = malloc(sizeof(t_textures));
	if (!t)
		return (INVALID);
	t->ea = init_texture();
	t->no = init_texture();
	t->so = init_texture();
	t->we = init_texture();
	data->textures = t;
	return (VALID);
}

int	init_data(void)
{
	t_data	*data;

	data = get_data();
	if (!data)
		return (INVALID);
	ft_bzero(data, sizeof(t_data));
	data->map = malloc(sizeof(t_map));
	data->ori = 0;
	if (!data->map)
		return (INVALID);
	if (end_init_game(data) == INVALID)
		return (INVALID);
	if (init_map(data) == INVALID
		|| init_c(data) == INVALID
		|| init_f(data) == INVALID
		|| init_textures(data) == INVALID)
		return (INVALID);
	data->gd_args = NULL;
	return (VALID);
}
