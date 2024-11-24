#include "../include/cub3d.h"

t_data  *get_data(void)
{
    static t_data data;

    return (&data);
}

int main(int argc, char **argv)
{
    init_data();
    if (parsing(argc, argv) == INVALID)
    {
        free_data(get_data());
        return (err("bad parsing"));
    }
    free_data(get_data());
    return (VALID);
}