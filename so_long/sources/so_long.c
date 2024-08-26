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
	t_data data;
	(void)argv;
	if(argc != 2)
		free_exit(&data, "Error\n");
	null_initialization_data(&data);
	check_map(&data, argv[1]);
	//init_game ?
	// mlx_loop(data.mlx_ptr);
	free_exit(&data, "");
	
}

/*
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
[] DISPLAY
	[] Create a window using MiniLibX
		[] Create the required structure to store all the necessary information
	[]	load all the required sprites (images) for your game and store them into memory
	[] Create the different hooks
		[] KEY_HANDLER
		[] mouse_handler (if necessary)
		[] close_handler, this is a hook on the red cross that closes the program correctly
		[] loop_hook (=> you game loop)
[]RENDER
	[] Draw the background
	[] Draw the walls, collectibles, and Exit
	[] Draw the player

[] KEY_HANDLER
	[] Is the requested new position a Wall ?
		[] don't do anything
	[] Is the requested new position a Collectible ?
		[] YES - Update the collected items counter and check
		 '->[] check if all collectibles have been collected
			 '->[] Yes - unblock the exit
		[] UPupdate your map 2D array and replace the collectible by a "floor"
	[] If the requested new position is not a wall, nor a collectible, nor outside the map, 
		[]update the  player position to new.
	([] Is the requested new position inside the map ?
		 [] if the new position is outside the map, don't do anything. Never too sure)

[] have to collect all collectibles to unlock the exit

// INITIATION FDF:
// [] check the windows and map size, Etc;
// [] open the window
// [] display the map
// [] hook the keys
// [] hook the mouse
// [] hook close window
// 

[]BONUS
	[] Make the player lose when they touch an enemy patrol.
	[]Add some sprite animation.
	[]Display the movement count directly on screen instead of writing it in the shell
*/

/*

*/
