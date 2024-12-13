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

int	only_nb(char *nb1, char *nb2, char *nb3)
{
	int	i;

	i = -1;
	while (nb1[++i])
		if (ft_isnotdigit(nb1[i]) == VALID)
			return (INVALID);
	i = -1;
	while (nb2[++i])
		if (ft_isnotdigit(nb2[i]) == VALID)
			return (INVALID);
	i = -1;
	while (nb3[++i])
		if (ft_isnotdigit(nb3[i]) == VALID)
			return (INVALID);
	return (VALID);
}

int	add_color_to_data(char **nb, char *color)
{
	t_color	*c;

	if (ft_strncmp(color, "F", 2) == VALID)
	{
		c = get_data()->f;
		if (only_nb(nb[0], nb[1], nb[2]) == INVALID || c->r != -1)
			return (INVALID);
		c->r = ft_atoi(nb[0]);
		c->g = ft_atoi(nb[1]);
		c->b = ft_atoi(nb[2]);
	}
	if (ft_strncmp(color, "C", 2) == VALID)
	{
		c = get_data()->c;
		if (only_nb(nb[0], nb[1], nb[2]) == INVALID || c->r != -1)
			return (INVALID);
		c->r = ft_atoi(nb[0]);
		c->g = ft_atoi(nb[1]);
		c->b = ft_atoi(nb[2]);
	}
	return (VALID);
}

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
