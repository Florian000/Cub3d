#include "../include/cub3d.h"

//gives accessto data
t_data  *get_data(void)
{
    static t_data data;

    return (&data);
}

int main(int argc, char **argv)
{
    init_data();
    // if (parsing(argc, argv) == INVALID)
    // {
    //     free_data(get_data());
    //     return (err("bad parsing"));
    // }
    //print_brut_map();
    //print_real_map();
    init_game(get_data());
    launcher(get_data()->game);
    exit_game(get_data()->game);
    return (VALID);
}

// void init_text(t_data *cub, char *path)
// {
// 	int i;
// 	int j;
// 	char *temp;
	
// 	i = 3;
// 	j = 0;
// 	cub->textures->EA = calloc(1, sizeof(t_texture));
// 	cub->textures->EA->path = path;
// 	cub->textures->EA->lines = get_xpmfile(cub->textures->EA->path);
// 	if (ft_strncmp(cub->textures->EA->lines[0], "/* XPM */", 9) != 0)
// 		return ; // NOT XPM FILE
// 	get_params(cub->textures->EA);
// 	while (cub->textures->EA->lines[i]&& ft_strncmp(cub->textures->EA->lines[i], "/* pixels */", 12) != 0)
// 	{
// 		cub->textures->EA->color[j] = ft_atoi(cub->textures->EA->lines[i] + 4);
// 		cub->textures->EA->key[j] = cub->textures->EA->lines[i][1];
// 		j++;
// 		i++;
// 	}
// 	while(cub->textures->EA->lines[i] && ft_strncmp(cub->textures->EA->lines[i], "};", 2) != 0)
// 	{
// 		if (!cub->textures->EA->data)
// 			cub->textures->EA->data = ft_substr(cub->textures->EA->lines[i], 1, cub->textures->EA->width);
// 		else
// 			cub->textures->EA->data = ft_strjoin(cub->textures->EA->data, ft_substr(cub->textures->EA->data, 1, cub->textures->EA->width));
// 		i++;
// 	}
// }