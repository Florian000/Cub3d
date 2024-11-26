#include "../../include/cub3d.h"

int check_first_args(char *str)
{
    if (*str && str[0] == '\n')
        return (VALID);
    if (ft_strncmp(str, "NO ", 3) == VALID
        || ft_strncmp(str, "SO ", 3) == VALID
        || ft_strncmp(str, "WE ", 3) == VALID
        || ft_strncmp(str, "EA ", 3) == VALID)
        return (VALID);
    if (ft_strncmp(str, "C ", 2) == VALID
        || ft_strncmp(str, "F ", 2) == VALID)
        return (VALID);
    return (INVALID);
}