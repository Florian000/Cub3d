typedef struct s_map
{
    int     hight;
    int     length;
    char    **brut_map;
    int     **real_map;
}   t_map;

typedef struct t_color
{
    int R;
    int G;
    int B;
}   t_color;

typedef struct s_textures
{
    char *NO;
    char *SO;
    char *EA;
    char *WE;
}   t_textures;

typedef struct s_data
{
    t_map   *map;
    char    *gd_args;
    t_textures  *textures;
    t_color     *C;
    t_color     *F;
}   t_data;

typedef struct s_player
{
    int pos_x;
    int pos_y;
    double angle;
    float rd;
} t_player;

typedef struct s_ray
{
    double ray_ngl;
    double distance;
    int  flag;
} t_ray;

typedef struct s_game
{
    void  *mlx_img;
    void  *mlx_p;
    void  *mlx_win;
    t_ray   *ray; 
    t_data   *dt;
    t_player  *play;
} t_game;