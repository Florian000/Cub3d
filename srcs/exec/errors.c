#include "../../include/cub3d.h"

int err(char *str)
{
    printf("ERROR : %s\n", str);
    return (INVALID);
}

void    *err_null(char *str)
{
    printf("ERROR : %s\n", str);
    return (NULL);
}