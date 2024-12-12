/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:04:45 by jvittoz           #+#    #+#             */
/*   Updated: 2024/12/08 19:04:47 by jvittoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//checks there is one argument ending in .cub
void	check_arguments(int argc, char **argv)
{
	char	*temp;
	int		i;

	if (argc != 2)
		exit_game(get_data()->game, "Wrong number of arguments");
	temp = argv[1];
	i = ft_strlen(temp);
	while (i > 0 && temp[i] != '.')
		i--;
	if (i == 0 && temp[i] == '.')
		exit_game(get_data()->game, "Hidden file");
	if (!temp[i + 1] || !(temp[i + 1] == 'c'))
		exit_game(get_data()->game, "Wrong file extension");
	if (!temp[i + 2] || !(temp[i + 2] == 'u'))
		exit_game(get_data()->game, "Wrong file extension");
	if (!temp[i + 3] || !(temp[i + 3] == 'b'))
		exit_game(get_data()->game, "Wrong file extension");
	if (temp[i + 4] != 0)
		exit_game(get_data()->game, "Wrong file extension");
}

int	add_color(char *str)
{
	char	**tab;
	char	**nb;

	tab = ft_split(str, ' ');
	nb = ft_split(tab[1], ',');
	if (check_color(nb) == INVALID)
	{
		ft_free2(INVALID, nb);
		return (ft_free2(INVALID, tab));
	}
	add_color_to_data(nb, tab[0]);
	ft_free2(VALID, nb);
	return (ft_free2(VALID, tab));
}

int	add_first_args(char *str)
{
	int	result;

	if (ft_strncmp(str, "NO ", 3) == VALID
		|| ft_strncmp(str, "SO ", 3) == VALID
		|| ft_strncmp(str, "WE ", 3) == VALID
		|| ft_strncmp(str, "EA ", 3) == VALID)
	{
		result = add_texture(str);
		return (result);
	}
	if (ft_strncmp(str, "C ", 2) == VALID
		|| ft_strncmp(str, "F ", 2) == VALID)
	{
		result = add_color(str);
		return (result);
	}
	return (INVALID);
}
