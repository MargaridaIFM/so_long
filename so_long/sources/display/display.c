/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:54:34 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/27 00:12:11 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_game(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		free_exit(data, "Error - mlx failed.");
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map.cols * 64,
			data->map.rows * 64, "so_long");
	if (data->win_ptr == NULL)
		free_exit(data, "Error - Impossible initiate the window.\n");
	load_sprites(data);
	draw_images(data);
	//print_moves(mlx_string_put) // bonus
	
	//mlx_loop(data->mlx_ptr);
}
void	load_sprites(t_data *data)
{
	data->sprites.floor = mlx_xpm_file_to_image(data->mlx_ptr,"../../assets/floor.xpm", &data->height_img, &data->width_img);
	data->sprites.wall = mlx_xpm_file_to_image(data->mlx_ptr, "../../assets/wall.xpm", &data->height_img, &data->width_img);
	// data->sprites.player = mlx_xpm_file_to_image();
	// data->sprites.exit = mlx_xpm_file_to_image();
	// data->sprites.collec1 = mlx_xpm_file_to_image();
	// data->sprites.collec2 = mlx_xpm_file_to_image();
	// data->sprites.collec3 = mlx_xpm_file_to_image();
	// data->sprites.collec4 = mlx_xpm_file_to_image();
	// data->sprites.collec5 = mlx_xpm_file_to_image();
}
void draw_images(t_data *data)
{
	printf("aqui\n");
	print_map(data->map.map);
	draw_backfloor(data);
}
void draw_backfloor(t_data *data)
{
	int y;
	int x;

	y = 0;
	while(data->map.map[y])
	{
		x = 0;
		while(data->map.map[y][x])
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprites.floor, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
// void  init_data (t_data *data)
// {
//     // map_scale(data);
//     data->mlx_ptr = mlx_init();
//     if(data->mlx_ptr == NULL)
//         free_exit(data, "Error");
//     //data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH,
//	WINDOW_HEIGHT, "data");
//     if(data->win_ptr == NULL)
//         free_exit(data, "Error");
//     //data->img->img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH,
//		WINDOW_HEIGHT);

//     mlx_key_hook(data->win_ptr, handle_input, data);

//     mlx_loop(data->mlx_ptr);
//     //mlx_mouse_hook();

// }

/*
[] DISPLAY
	[x] Create a window using MiniLibX
		[] Create the required structure to store all the necessary information
	[] load all the required sprites (images) for your game and store them into memory
	[] Create the different hooks
		[] KEY_HANDLER
		[] mouse_handler (if necessary)
		[] close_handler,
			this is a hook on the red cross that closes the program correctly
		[] loop_hook (=> you game loop)

[]RENDER
	- load all the required sprites (images) for your game and store them into memory
		[] Draw the background
		[] Draw the walls, collectibles, and Exit
		[] Draw the player
*/

// int handle_input(int keysym, t_data *data)
// {
//     if(keysym == XK_Escape)
//         free_exit(data, "");
//     return(0);
// }
// // void map_scale(t_data *data)
// // {

// // }
// // void screen_size(t_data *data)
// // {

// // }

// // INITIATION data:
// // [] check the windows and map size, Etc;
// // [] open the window
// // [] display the map
// // [] hook the keys
// // [] hook the mouse
// // [] hook close window
// //