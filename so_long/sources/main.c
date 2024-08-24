/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:24:31 by mfrancis          #+#    #+#             */
/*   Updated: 2024/06/23 21:24:31 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* *@brief
Imitate the functions mlx_pixel_put to calculate the offset memory.
Because the line_length is different from the size of the window, it is faster.
@param mlx: mlx pointer.
@param img: image pointer.
@param x: x coordinate.
@param y: y coordinate.
@param color: color.
@return void.
*/
// FOR ME: put a if before or inside the function fo protection and make sure that i am inside of the window.
// void my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
// {
// 	char *dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel/8));
// 	*(unsigned int *)dst = color;
// }

int	main(int argc, char *argv[])
{
	
}

/*
t_fdf	fdf;

	if(argc != 2)
		ft_printf("Not enough arguments\n");
	null_initialization_fdf(&fdf);
	check_map(&fdf, argv[1]);
	init_fdf(&fdf);
	//mlx_loop(fdf.mlx_ptr);
    free_exit(&fdf, "");
steps:
[x] Understand de MinilibX
	[x] mlx_init()
	[x] mlx_new_window()
	[] mlx_clear_window()
	[x] mlx_destroy_window()
	[x] mlx_new_image()
	[] mlx_destroy_image()
	[x] mlx_get_data_addr()
	[] mlx_put_image_to_window()
	[x] mlx_hook()
	[] mlx_mouse_hook()
	[x] mlx_key_hook()
	[x] mlx_loop()
	[] mlx_xpm_file_to_image() --> bonus part
[]PARSING


[x]PARSING
	[] finish in .ber
	[] The map can be composed of only these 5 characters:
		[] 0 for an empty space,
		[] 1 for a wall,
		[] C for a collectible,
		[] E for the exit,
		[] P for the player’s starting position.
	[] must contain
		[] 1 exit,
		[] 1 or more collectible
		[] 1 starting position
		[] be closed/surrounded by walls
	[] rectangular;
	[] message"Error\n" 


[]BONUS
	[] Make the player lose when they touch an enemy patrol.
	[]Add some sprite animation.
	[]Display the movement count directly on screen instead of writing it in the shell
*/

/*

*/
