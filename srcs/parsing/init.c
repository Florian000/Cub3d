#include "../../include/cub3d.h"

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

int read_map(char *file)
{
    int fd;
    char *str;

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
        free(str);
        str = get_next_line(fd);
    }
    close(fd);
    return (VALID);
}