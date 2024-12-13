/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:04:32 by jvittoz           #+#    #+#             */
/*   Updated: 2024/12/08 21:08:41 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_end_txt(t_data *data)
{
	if (data->textures->ea->path == NULL
		|| data->textures->no->path == NULL
		|| data->textures->so->path == NULL
		|| data->textures->we->path == NULL)
		exit_game(data->game, "insufficient info");
}

void	check_end_clr(t_data *data)
{
	if (data->c->b < 0
		|| data->c->r < 0
		|| data->c->g < 0)
		exit_game(data->game, "insufficient info");
	if (data->f->b < 0
		|| data->f->r < 0
		|| data->f->g < 0)
		exit_game(data->game, "insufficient info");
}

//goes through all parsing events
void	parsing(int argc, char **argv)
{
	t_data	*data;

	data = get_data();
	check_arguments(argc, argv);
	read_map(argv[1]);
	if (init_real_map() == INVALID)
		exit_game(get_data()->game, "real map error");
	fill_real_map();
	if (check_nb_player(get_data()) == INVALID)
		exit_game(get_data()->game, "bad nb player");
	if (validate_map(data->map) == INVALID)
		exit_game(get_data()->game, "map invalid");
	check_end_txt(get_data());
	check_end_clr(get_data());
	check_files_open(data);
}
