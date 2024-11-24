#include "../../include/cub3d.h"

//goes through all parsing events
int parsing(int argc, char **argv)
{
    if (check_arguments(argc, argv) == INVALID)
        return (err("bad args"));
    if (read_map(argv[1]) == INVALID)
        return (INVALID);
    if (init_real_map() == INVALID)
        return (err("malloc realmap err"));
    fill_real_map();
    return (VALID);
}