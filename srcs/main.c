#include "../include/cub3d.h"

//gives accessto data
t_data  *get_data(void)
{
    static t_data data;

    return (&data);
}

int main(int argc, char **argv)
{
    init_data();
    parsing(argc, argv);
    init_game(get_data());
    welcome_print();
    launcher(get_data()->game);
    exit_game(get_data()->game, NULL);
    return (VALID);
}