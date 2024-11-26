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

int add_texture(char *str)
{
    return (VALID);
}

int check_color(char **nb)
{
    int i;
    int val;

    i = 0;
    if (!nb)
        return (INVALID);
    while (nb[i])
        i++;
    if (i != 3)
        return (INVALID);
    i = 0;
    while (nb[i])
    {
        if (ft_atoi(nb[i]) > 255 || ft_atoi(nb[i]) < 0)
            return (INVALID);
        i++;
    }
    return (VALID);
}

int    add_color_to_data(char **nb, char *color)
{
    int i;
    t_color *c;

    i = 0;
    if (ft_strncmp(color, "F", 2) == VALID)
    {
        c = get_data()->F;
        c->R = ft_atoi(nb[0]);
        c->G = ft_atoi(nb[1]);
        c->B = ft_atoi(nb[2]);
    }
    if (ft_strncmp(color, "C", 2) == VALID)
    {
        c = get_data()->C;
        c->R = ft_atoi(nb[0]);
        c->G = ft_atoi(nb[1]);
        c->B = ft_atoi(nb[2]);
    }
    return (VALID);
}

int add_color(char *str)
{
    char    **tab;
    char     **nb;

    tab = ft_split(str, ' ');
    nb = ft_split(tab[1], ',');
    if (check_color(nb) == INVALID)
        return (ft_free(INVALID, "ss", tab, nb));
    add_color_to_data(nb, tab[0]);
    return (ft_free(VALID, "ss", tab, nb));
}

int add_first_args(char *str)
{
    if (ft_strncmp(str, "NO ", 3) == VALID
        || ft_strncmp(str, "SO ", 3) == VALID
        || ft_strncmp(str, "WE ", 3) == VALID
        || ft_strncmp(str, "EA ", 3) == VALID)
        return (add_texture(str));
    if (ft_strncmp(str, "C ", 2) == VALID
        || ft_strncmp(str, "F ", 2) == VALID)
        return (add_color(str));
    return (VALID);
}