#include "../../include/cub3d.h"

int check_arguments(int argc, char **argv)
{
    char    *temp;
    int     i;

    if (argc != 2)
        return (INVALID);
    temp = argv[1];
    i = 0;
    while (temp[i] && temp[i] != '.')
        i++;
    if (!temp[i + 1] || !(temp[i + 1] == 'c'))
        return (err("bad map file"));
    if (!temp[i + 2] || !(temp[i + 2] == 'u'))
        return (err("bad map file"));
    if (!temp[i + 3] || !(temp[i + 3] == 'b'))
        return (err("bad map file"));
    if (temp[i + 4] != 0)
        return (err("bad map file"));
    return (VALID);
}

int check_map(t_map *m)
{
    (void)m;
    return (VALID);
}