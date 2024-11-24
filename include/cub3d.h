#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "libft/libft.h"
#include "struct.h"

#define VALID 0
#define INVALID 1

#define ERR_PARSING 20
#define ERR_LIBX    30
#define ERR_MALLOC  40

//parsing
//check_args
int     check_arguments(int argc, char **argv);
int     read_map(char *file);

//parsing
int     parsing(int argc, char **argv);

//init
int     init_data(void);

//exec/errors
int     err(char *str);
void    *err_null(char *str);

//free
int     free_data(t_data *data);






//debug
void    print_brut_map(void);

//main
t_data  *get_data(void);
int     main(int argc, char **argv);

#endif