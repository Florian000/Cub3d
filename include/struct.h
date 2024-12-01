typedef struct s_map
{
    int     hight;
    int     length;
    int     pos_x; //player position x axis
    int     pos_y; //player position y axis
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

typedef struct s_player
{
    int pos_x; // PIXEL
    int pos_y; // PIXEL
    double angle;
    float fov;
    int  rotate;
    int  x_way;
    int  y_way;
} t_player;

typedef struct s_ray
{
    double ray_ngl;
    double distance;
    int  horizontal;
} t_ray;

typedef struct s_game
{
    void  *mlx_img;
    void  *mlx_p;
    void  *mlx_win;
    t_ray   *ray; 
    t_player  *play;
} t_game;

typedef struct s_data
{
    t_map   *map;
    char    *gd_args;
    t_textures  *textures;
    t_color     *C;
    t_color     *F;
    t_game      *game;
}   t_data;

