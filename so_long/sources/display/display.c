/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:54:34 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/29 00:03:58 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_game(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		free_exit(data, "Error - mlx failed.");
	mlx_get_screen_size(data->mlx_ptr, &data->screen_h_max,
		&data->screen_w_max);
	if (data->map.rows * 64 + 64 > data->screen_h_max || data->map.cols * 64
		+ 64 > data->screen_w_max)
		free_exit(data, "Error - Window size larger than screen size.\n");
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map.cols * 64,
			data->map.rows * 64, "so_long");
	if (data->win_ptr == NULL)
		free_exit(data, "Error - Impossible initiate the window.\n");
	load_sprites(data);
	draw_map(data);
	call_hooks(data);
}
void	load_sprites(t_data *data)
{
	data->sprites.wall.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/wall.xpm", &data->sprites.wall.width,
			&data->sprites.wall.height);
	data->sprites.floor.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/floor.xpm", &data->sprites.floor.width,
			&data->sprites.floor.height);
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
	// OU POR CAMA ?
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
		|| data->player.p_f.img == NULL || data->player.p_b.img == NULL
		|| data->player.p_r.img == NULL || data->player.p_l.img == NULL
		|| data->sprites.exit1.img == NULL || data->sprites.exit2.img == NULL
		|| data->sprites.collec1.img == NULL)
		free_exit(data, "Error - Failed to load sprites.\n");
}

// void	draw_background(t_data *data)
// {
// 	int	y;
// 	int	x;
//
// 	printf("aqui\n");
// 	print_map(data->map.map);
//
// 	if (data->map.map == NULL)
// 		free_exit(data, "Error - Map data is not properly initialized.\n");
// 	y = 0;
// 	while (data->map.map[y])
// 	{
// 		x = 0;
// 		while (data->map.map[y][x])
// 		{
// 			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
// 				data->sprites.floor.img, x * 64, y * 64);
// 			x++;
// 		}
// 		y++;
// 	}
// }
void	draw_map(t_data *data)
{
	int	y;
	int	x;

	if (data->map.map == NULL)
		free_exit(data, "Error - Map data is not properly initialized.\n");
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			draw_elements(data, y, x);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player.p_f.img,
		data->player.x * 64, data->player.y * 64);
}
void	draw_elements(t_data *data, int y, int x)
{
	if (data->map.map[y][x] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.floor.img, x * 64, y * 64);
	if (data->map.map[y][x] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.wall.img, x * 64, y * 64);
	if (data->map.map[y][x] == 'E' && data->map.flag_exit == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.exit1.img, x * 64, y * 64);
	if (data->map.map[y][x] == 'E' && data->map.flag_exit == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.exit2.img, x * 64, y * 64);
	if (data->map.map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.collec1.img, x * 64, y * 64);
}

void call_hooks(t_data *data)
{
	mlx_key_hook(data->win_ptr, handle_key, data);

	//mlx_mouse_hook() ver se a cruz tem de funcionar

}
int	handle_key(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		free_exit(data, "");
	else if(keysym = XK_w)
		data->map.

	update_map(data);
	verify_exit(data);
	draw_map(data);
	return (0);
}

/*
[] DISPLAY
	[x] Create a window using MiniLibX
		[x] Create the requint			moves;ired structure to store all the necessary information
	[] Sprites (images) for your game and store them into memory
		[x] Draw the background
		[x] Draw the walls, collectibles, and Exit
		[x] Draw the player
	[x]RENDER MAP
		[x] Draw the map
		[x] Draw the player
	[] HOOKS
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
			[] Is the requested new position inside the map ?
				[] if the new position is outside the map, don't do anything. Never too sure)		
		[] mouse_handler (if necessary)
		[] close_handler,
			this is a hook on the red cross that closes the program correctly
		[] loop_hook (=> you game loop)
		
IMPORTANTE:
[] sprites do player mudarem ? e no key_handler ?

[] have to collect all collectibles to unlock the exit
*/