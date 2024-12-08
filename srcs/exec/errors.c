#include "../../include/cub3d.h"

int err(char *str)
{
    printf("ERROR : %s\n", str);
    return (INVALID);
}

void    *err_null(char *str)
{
    printf("ERROR : %s\n", str);
    return (NULL);
}

void	ft_exit() 		// exit the game
{
    //free_data(get_data());
	printf("Game closed\n"); // print the message
	exit(0); // exit the game
}