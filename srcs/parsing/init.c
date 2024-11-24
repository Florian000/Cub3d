#include "../../include/cub3d.h"

int  init_data(void)
{
    t_data *data;

    data = get_data();
    ft_bzero(data, sizeof(t_data));
    data->brut_map = NULL;
    data->gd_args = NULL;
    return (VALID);
}