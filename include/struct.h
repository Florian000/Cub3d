#include <stdbool.h>

typedef struct s_data t_data;
typedef struct s_map
{
    int     height;
    int     length;
    int     pos_x;
    int     pos_y;
    char    **brut_map;
    int     **real_map;
}   t_map;

typedef struct t_color
{
    int R;
    int G;
    int B;
    int color;
}   t_color;

typedef struct s_texture
{
    char *path;
    char **lines;
    int     width;
    int     height;
    int     nb_colors;
    int     key_size;
    int *color;
    int *key;
    int *data;
}   t_texture;

typedef struct s_textures
{
    t_texture *NO;
    t_texture *SO;
    t_texture *EA;
    t_texture *WE;
}   t_textures;

typedef struct s_player
{
    double pos_x; // PIXEL
    double pos_y; // PIXEL
    double angle;
    float fov;
    int  rotate;
    int  x_way;
    int  y_way;
    t_data *cub;
} t_player;

typedef struct s_ray
{
    double ray_ngl;
    double distance;
    bool  horizontal;
    float x_step;
    float y_step;
    float h_x;
    float h_y;
    float v_x;
    float v_y;
    float x;
    float y;
    int adjust;
    double wall_h;
    t_data *cub;
} t_ray;

typedef struct s_game
{
    void  *mlx_img;
    void  *mlx_p;
    void  *mlx_win;
    t_ray   *ray; 
    t_player  *player;
    t_data *cub;
} t_game;

typedef struct s_data
{
    t_map   *map;
    char    *gd_args;
    t_textures  *textures;
    t_color     *C;
    t_color     *F;
    t_game      *game;
    int         ori;
}   t_data;
