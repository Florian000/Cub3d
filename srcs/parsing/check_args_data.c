#include "../../include/cub3d.h"

int check_first_args(char *str)
{
    if (*str && str[0] == '\n')
        return (VALID);
    return (INVALID);
}