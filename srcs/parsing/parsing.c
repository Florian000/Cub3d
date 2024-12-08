/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:04:32 by jvittoz           #+#    #+#             */
/*   Updated: 2024/12/08 19:58:59 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//goes through all parsing events
void parsing(int argc, char **argv)
{
	t_data *data;

	data = get_data();
	check_arguments(argc, argv);
	if (read_map(argv[1]) == INVALID)
		exit_game(get_data()->game, "map error");
	if (init_real_map() == INVALID)
		exit_game(get_data()->game, "real map error");
	fill_real_map();
	if (validate_map(data->map) == INVALID)
		exit_game(get_data()->game, "map invalid");
}
