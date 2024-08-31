/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:42:07 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/31 13:42:07 by mfrancis         ###   ########.fr       */
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
static void	initialization_data(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->moves = 1;
	data->sprites.floor.width = 64;
	data->sprites.floor.height = 64;
	data->sprites.wall.width = 64;
	data->sprites.wall.height = 64;
	data->sprites.collec1.width = 64;
	data->sprites.collec1.height = 64;
	data->sprites.exit1.width = 64;
	data->sprites.exit1.height = 64;
	data->sprites.exit2.width = 64;
	data->sprites.exit2.height = 64;
	data->player.p_f.width = 64;
	data->player.p_f.height = 64;
	data->player.p_b.width = 64;
	data->player.p_b.height = 64;
	data->player.p_r.width = 64;
	data->player.p_r.height = 64;
	data->player.p_l.width = 64;
	data->player.p_l.height = 64;
}

int	main(int argc, char *argv[])
{
	t_data	data;

	(void)argv;
	if (argc != 2)
		free_exit(&data, "Error\n");
	initialization_data(&data);
	check_map(&data, argv[1]);
	init_game(&data);
	mlx_string_put(data.mlx_ptr, data.win_ptr, 15, 15, 16777215, "0");
	mlx_loop(data.mlx_ptr);
}

/*
steps:
[x] Understand de MinilibX
	[x] mlx_init()
	[x] mlx_new_window()
	[x] mlx_clear_window()
	[x] mlx_destroy_window()
	[x] mlx_new_image()
	[x] mlx_destroy_image()
	[x] mlx_get_data_addr()
	[x] mlx_put_image_to_window()
	[x] mlx_string_put;
	[x] mlx_hook()
	[x] mlx_mouse_hook()
	[x] mlx_key_hook()
	[x] mlx_loop()
	[x] mlx_xpm_file_to_image()
[x]PARSING
[x] DISPLAY
[x]mlx_string_put inicial
[x] loop_hook (=> you game loop)

[]BONUS
	[] Make the player lose when they touch an enemy patrol.
	[]	Add some sprite animation.
	[x] Display the movement count directly on screen instead
		 of writing it in the shell
*/
