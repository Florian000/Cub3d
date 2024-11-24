#include "../../include/cub3d.h"

//checks there is one argument ending in .cub
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

//checks a line has nothing but what is allowed
int check_line(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (ft_isspace(str[i]) == 1)
            i++;
        else
        {
            if (str[i] == '0' || str[i] == '1' || str[i] == 'N' || str[i] == 'S'
                || str[i] == 'E' || str[i] == 'O')
                i++;
            else
                return (INVALID);
        }
    }
    return (VALID);
}

//reallocates one more space to the brut map
int add_space_brutmap(t_data *data)
{
    char    **new_map;
    int     size;
    int     i;

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
    return (VALID);
}

//goes through a file to check all lines;
int read_map(char *file)
{
    int     fd;
    char    *str;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (err("could not open fd"));
    str = get_next_line(fd);
    while (str)
    {
        if (check_line(str) == INVALID)
        {
            free(str);
            return (err("bad obj in file"));
        }
        if (add_line(str) == INVALID)
        {
            free(str);
            return (err("bad malloc in readmap"));
        }
        free(str);
        str = get_next_line(fd);
    }
    close(fd);
    return (VALID);
}