/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:54:34 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/28 19:18:29 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_game(t_data *data)
{
	// ver tamanho do meu mapa e janela - ESTA A DAR ERRO
	// data->win_height = data->map.rows * 64;
	// data->win_width = data->map.cols * 64;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		free_exit(data, "Error - mlx failed.");
	mlx_get_screen_size(data->mlx_ptr, &data->screen_h_max,
		&data->screen_w_max);
	if (data->screen_h_max < data->win_height
		|| data->screen_w_max < data->win_width + 64)
		free_exit(data, "Error - Window size larger than screen size.\n");
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map.cols * 64,
			data->map.rows * 64, "so_long");
	if (data->win_ptr == NULL)
		free_exit(data, "Error - Impossible initiate the window.\n");


	load_sprites(data);
	draw_images(data);
	// printf("aqui3\n");
	// free_exit(data, "sair\n");
	// print_moves(mlx_string_put) // bonus
	mlx_key_hook(data->win_ptr, handle_input, data);
}
void	load_sprites(t_data *data)
{
	data->sprites.wall.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/wall.xpm", &data->sprites.wall.width, &data->sprites.wall.height);
	data->sprites.floor.img = mlx_xpm_file_to_image(data->mlx_ptr, "assets/floor.xpm",
			&data->sprites.floor.width, &data->sprites.floor.height);
	data->player.p_f.img = mlx_xpm_file_to_image(data->mlx_ptr, "assets/doc_f.xpm",
			&data->player.p_f.width, &data->player.p_f.height);
	data->player.p_b.img = mlx_xpm_file_to_image(data->mlx_ptr, "assets/doc_b.xpm",
			&data->player.p_b.width, &data->player.p_b.height);
	data->player.p_r.img = mlx_xpm_file_to_image(data->mlx_ptr, "assets/doc_r.xpm",
			&data->player.p_r.width, &data->player.p_r.height);
	data->player.p_l.img = mlx_xpm_file_to_image(data->mlx_ptr, "assets/doc_l.xpm",
			&data->player.p_l.width, &data->player.p_l.height);
	// OU POR CAMA ?
	data->sprites.exit1.img = mlx_xpm_file_to_image(data->mlx_ptr, "assets/door_c.xpm",
			&data->sprites.exit1.width, &data->sprites.exit1.height);
	data->sprites.exit2.img = mlx_xpm_file_to_image(data->mlx_ptr, "assets/door_o.xpm",
			&data->sprites.exit2.width, &data->sprites.exit2.height);
	data->sprites.collec1.img = mlx_xpm_file_to_image(data->mlx_ptr, "assets/pill_1.xpm",
			&data->sprites.collec1.width, &data->sprites.collec1.height);
	if (data->sprites.floor.img == NULL || data->sprites.wall.img == NULL
		|| data->player.p_f.img == NULL || data->player.p_b.img == NULL 
		|| data->player.p_r.img == NULL || data->player.p_l.img == NULL
		 || data->sprites.exit1.img == NULL || data->sprites.exit2.img == NULL 
		 || data->sprites.collec1.img == NULL )
		free_exit(data, "Error - Failed to load sprites.\n");
}
void	draw_images(t_data *data)
{
	//draw_background(data);
	draw_elements(data);
	//draw_player(data);
	// free_exit(data, "");
}

// t_info	*get_play(void)
// {
// 	static t_info	inf;

// 	return (&inf->);
// }
// void	draw_background(t_data *data)
// {
// 	int	y;
// 	int	x;

// 	printf("aqui\n");
// 	print_map(data->map.map);

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
void	draw_elements(t_data *data)
{
	int	y;
	int	x;

	if (data->map.map == NULL)
		free_exit(data, "Error - Map data is not properly initialized.\n");
	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (data->map.map[y][x] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprites.floor.img, x * 64, y * 64);
			if (data->map.map[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprites.wall.img, x * 64, y * 64);
			if(data->map.map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprites.exit1.img, x * 64, y * 64);
			if(data->map.map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprites.collec1.img, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
// void	draw_player(t_data *data)
//{
// 	int	x;
// 	int	y;
// if (data->map.map == NULL)
//		free_exit(data, "Error - Map data is not properly initialized.\n");
// if (data->map.map[y][x] == 'P')
// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprites.p.img, x * 64, y * 64);
//}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		free_exit(data, "");
	return (0);
}
/*
[] DISPLAY
	[x] Create a window using MiniLibX
		[x] Create the required structure to store all the necessary information
	[] load all the required sprites (images) for your game and store them into memory
	[] Create the different hooks
		[] KEY_HANDLER
		[] mouse_handler (if necessary)
		[] close_handler,
			this is a hook on the red cross that closes the program correctly
		[] loop_hook (=> you game loop)

[]RENDER
	[] load all the required sprites (images) for your game and store them into memory
		[x] Draw the background
		[x] Draw the walls, collectibles, and Exit
		[] Draw the player
*/


// // INITIATION data:
// // [] check the windows and map size, Etc;
// // [] open the window
// // [] display the map
// // [] hook the keys
// // [] hook the mouse
// // [] hook close window
// //