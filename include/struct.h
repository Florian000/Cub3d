typedef struct s_map
{
    int     hight;
    int     length;
    char    **brut_map;
    int     **real_map;
}   t_map;

typedef struct s_data
{
    t_map   *map;
    char    *gd_args;
}   t_data;

