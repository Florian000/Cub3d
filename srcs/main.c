/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:29:36 by fgranger          #+#    #+#             */
/*   Updated: 2024/12/08 20:57:39 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
/*
	-open map message error -> new lines in map
	-recheck E S N W
	-tab = 1 space ? to change to 4 ?
*/

//gives accessto data
t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

int	main(int argc, char **argv)
{
	init_data();
	parsing(argc, argv);
	init_game(get_data());
	welcome_print();
	launcher(get_data()->game);
	exit_game(get_data()->game, NULL);
	return (VALID);
}
