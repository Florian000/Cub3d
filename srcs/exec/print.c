/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:29:36 by fgranger          #+#    #+#             */
/*   Updated: 2024/12/08 20:02:31 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	print_border(const char *border_color)
{
	int	i;

	i = -1;
	printf("%s*", border_color);
	while (++i < PRINT_WIDTH - 2)
		printf("=");
	printf("*\033[0m\n");
}

void	print_centered(const char *text, const char *color)
{
	int	text_len;
	int	padding;

	text_len = ft_strlen(text);
	padding = (PRINT_WIDTH - text_len) / 2;
	printf("%s*%*s%s%*s*\033[0m\n", color, padding, "", \
			text, PRINT_WIDTH - padding - text_len - 2, "");
}

void	print_empty_line(void)
{
	printf("*%*s*\n", PRINT_WIDTH - 2, "");
}

void	welcome_print(void)
{
	print_border(RED);
	print_empty_line();
	print_centered("CUB3D", BLUE);
	print_empty_line();
	print_centered("Welcome to our CUB3D project", GREEN);
	print_empty_line();
	print_centered("Commands :", GREEN);
	print_empty_line();
	print_centered("W = move forward", YELLOW);
	print_centered("S = move backward", YELLOW);
	print_centered("A = move left", YELLOW);
	print_centered("D = move right", YELLOW);
	print_centered("ESC = exit the game", YELLOW);
	print_empty_line();
	print_border(RED);
}

void	exit_print(void)
{
	print_empty_line();
	print_empty_line();
	print_border(RED);
	print_centered("Thanks for playing, we hope to see you back soon", GREEN);
	print_empty_line();
	print_border(RED);
}
