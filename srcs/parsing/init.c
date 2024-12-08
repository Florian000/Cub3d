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

int init_map(t_data *data)
{
	if (!data || !data->map)
		return (INVALID);

	data->map->height = 0;
	data->map->length = 0;
	data->map->brut_map = NULL;
	data->map->real_map = NULL;
	return (VALID);
}

int init_c(t_data *data)
{
	if (!data)
		return (INVALID);
	t_color *c = malloc(sizeof(t_color));
	if (!c)
		return (INVALID);
	c->B = -1;
	c->G = -1;
	c->R = -1;
	data->C = c;
	return (VALID);
}

int init_f(t_data *data)
{
	if (!data)
		return (INVALID);

	t_color *c = malloc(sizeof(t_color));
	if (!c)
		return (INVALID);
	c->B = -1;
	c->G = -1;
	c->R = -1;
	data->F = c;
	return (VALID);
}

t_texture *init_texture(void)
{
	t_texture *res;

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

int init_textures(t_data *data)
{
	if (!data)
		return (INVALID);

	t_textures *t = malloc(sizeof(t_textures));
	if (!t)
		return (INVALID);
	t->EA = init_texture();
	t->NO = init_texture();
	t->SO = init_texture();
	t->WE = init_texture();
	data->textures = t;
	return (VALID);
}

int init_data(void)
{
	t_data *data;

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
	if (init_map(data) == INVALID ||
			init_c(data) == INVALID ||
			init_f(data) == INVALID ||
			init_textures(data) == INVALID)
	{
		//free_data(data);
		return (INVALID);
	}
	data->gd_args = NULL;
	return (VALID);
}
