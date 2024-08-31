/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:54:34 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/31 15:40:22 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	load_sprites(t_data *data)
{
	data->sprites.wall.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/wall.xpm", &data->sprites.wall.width,
			&data->sprites.wall.height);
	data->sprites.floor.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/floor.xpm", &data->sprites.floor.width,
			&data->sprites.floor.height);
	data->sprites.exit1.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/door_c.xpm", &data->sprites.exit1.width,
			&data->sprites.exit1.height);
	data->sprites.exit2.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/door_o.xpm", &data->sprites.exit2.width,
			&data->sprites.exit2.height);
	data->sprites.collec1.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/pill_1.xpm", &data->sprites.collec1.width,
			&data->sprites.collec1.height);
	if (data->sprites.floor.img == NULL || data->sprites.wall.img == NULL
		|| data->sprites.exit1.img == NULL || data->sprites.exit2.img == NULL
		|| data->sprites.collec1.img == NULL)
		free_exit(data, "Error - Failed to load sprites.\n");
}

static void	load_player(t_data *data)
{
	data->player.p_f.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/doc_f.xpm", &data->player.p_f.width,
			&data->player.p_f.height);
	data->player.p_b.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/doc_b.xpm", &data->player.p_b.width,
			&data->player.p_b.height);
	data->player.p_r.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/doc_r.xpm", &data->player.p_r.width,
			&data->player.p_r.height);
	data->player.p_l.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/doc_l.xpm", &data->player.p_l.width,
			&data->player.p_l.height);
	if (data->player.p_f.img == NULL || data->player.p_b.img == NULL
		|| data->player.p_r.img == NULL || data->player.p_l.img == NULL)
		free_exit(data, "Error - Failed to load sprites.\n");
}

void	init_game(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		free_exit(data, "Error - mlx failed.");
	mlx_get_screen_size(data->mlx_ptr, &data->screen_w_max,
		&data->screen_h_max);
	if (((data->map.rows * 64) + 32) > data->screen_h_max || ((data->map.cols
				* 64) + 32) > data->screen_w_max)
		free_exit(data, "Error - Window size larger than screen size.\n");
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map.cols * 64,
			data->map.rows * 64, "so_long");
	if (data->win_ptr == NULL)
		free_exit(data, "Error - Impossible initiate the window.\n");
	load_sprites(data);
	load_player(data);
	draw_images(data);
	call_hooks(data);
}

/*
	
[] DISPLAY
	[x] Create a window using MiniLibX
		[x] Create the structure to store all the necessary information
	[] Sprites (images) for your game and store them into memory
		[x] Background
		[x] Walls, collectibles, and Exit
		[x] Player
	[x]RENDER MAP
		[x] Draw the map and walls;
		[x] Collectibles, and Exit
		[x] Draw the player
	[] HOOKS
		[x]hook key;
		[] KEY_HANDLER
			[x] Is the requested new position a Wall ?
				[x] don't do anything
			[x] Is the requested new position a Collectible ?
				[x] YES - Update the collected items counter
					'  - Moves++;
					'->[x] check if all collectibles have been collected
						'->[x] Yes - unblock the exit
				[x] Update map 2D array and replace the collectible by "floor"
				[x] update the  player position to new with the correct img.
			[x] If the requested new position is not a wall, nor a collectible,
				nor outside the map,
				[x] replace the previouse position with "floor"
				[x] update the  player position to new with the correct img.
		[] close_handler,
			this is a hook on the red cross that closes the program correctly
*/

/*
put			moves;
*/
