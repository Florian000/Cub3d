#include "../include/cub3d.h"

t_data  *get_data(void)
{
    static t_data *data;

    return (data);
}

int main(int argc, char **argv)
{
    t_data  data;

    (void)data;
    if (parsing(argc, argv) == INVALID)
        return (printf("bad parsing"));
    return (VALID);
}