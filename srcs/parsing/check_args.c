/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:03:32 by jvittoz           #+#    #+#             */
/*   Updated: 2024/12/08 20:06:16 by fgranger         ###   ########.fr       */
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

//checks a line has nothing but what is allowed
int	check_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]) == 1)
			i++;
		else
		{
			if (str[i] == '0' || str[i] == '1' || str[i] == 'N' || str[i] == 'S'
					|| str[i] == 'E' || str[i] == 'W')
				i++;
			else
				return (INVALID);
		}
	}
	return (VALID);
}

//reallocates one more space to the brut map
int	add_space_brutmap(t_data *data)
{
	char	**new_map;
	int		size;
	int		i;

	size = 0;
	if (data->map->brut_map)
	{
		while (data->map->brut_map[size])
			size++;
	}
	new_map = malloc((size + 2) * sizeof(char *));
	if (!new_map)
		return (INVALID);
	i = 0;
	while (i < size)
	{
		new_map[i] = data->map->brut_map[i];
		i++;
	}
	new_map[size] = NULL;
	new_map[size + 1] = NULL;
	if (data->map->brut_map)
		free(data->map->brut_map);
	data->map->brut_map = new_map;
	return (size);
}

//adds a line to creat brutmap in data (without new gnl)
int add_line(char *src)
{
	t_data  *data;
	int     i;

	data = get_data();
	i = add_space_brutmap(data);
	data->map->brut_map[i] = ft_strdup(src);
	if (data->map->brut_map[i] == NULL)
		return (INVALID);
	data->map->height++;
	if (data->map->length < (int)ft_strlen(src))
		data->map->length = ft_strlen(src);
	return (VALID);
}

//goes through a file to check all lines;
void read_map(char *file)
{
	int     fd;
	char    *str;
	char    *trimmed;
	int     error;

	error = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_game(get_data()->game, "could not open fd");
	str = get_next_line(fd);
	while (str && check_first_args(str) == VALID)
	{
		trimmed = ft_strtrim(str, "\n");
		free(str);
		str = trimmed;
		if (str != NULL && str[0] != 0 && add_first_args(str) == INVALID)
			error = 1;
		free(str);
		str = get_next_line(fd);
	}
	while (str) 
	{
		trimmed = ft_strtrim(str, "\n");
		free(str);
		str = trimmed;
		if (check_line(str) == INVALID)
			error = 2;
		if (add_line(str) == INVALID)
			error = 3;
		free(str);
		str = get_next_line(fd);
	}
	if (str)
		free(str);
	close(fd);
	if (error > 0)
		exit_game(get_data()->game, "Failed to read the map");
}


