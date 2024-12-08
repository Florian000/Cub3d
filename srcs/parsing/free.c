#include "../../include/cub3d.h"

int ft_free2(int res, char **str)
{
    int i;

    i = 0;
    while (str[i])
        free(str[i++]);
    free(str);
    return (res);
}
