/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:29:36 by fgranger          #+#    #+#             */
/*   Updated: 2024/12/15 12:27:13 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	exit_game(char *str)
{
	if (str != NULL)
	{
		ft_putstr_fd(RED, STDERR_FILENO);
		ft_putstr_fd("ERROR : ", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putstr_fd(RST, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	else
		exit_print();
	if (get_data())
		free_data(get_data());
	exit(0);
}
