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
    if (parsing(argc, argv) == INVALID)
    {
         //free_data(get_data());
         return (err("bad parsing"));
    }
    print_brut_map();
    print_real_map();
    printf("good init\n");
    init_game(get_data());
    printf("good init\n");
    launcher(get_data()->game);
    exit_game(get_data()->game);
    return (VALID);
}