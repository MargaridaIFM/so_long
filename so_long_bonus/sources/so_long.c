/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/08/31 13:42:07 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/31 13:42:07 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	data->sprites.enemy.width = 64;
	data->sprites.enemy.height = 64;
	data->player.p_f.width = 64;
	data->player.p_f.height = 64;
	data->player.p_b.width = 64;
	data->player.p_b.height = 64;
	data->player.p_r.width = 64;
	data->player.p_r.height = 64;
	data->player.p_l.width = 64;
	data->player.p_l.height = 64;
}

static int	animation(t_data *data)
{
	static int	flag_colletc1 = 0;
	int			y;
	int			x;

	y = -1;
	while (data->map.map[++y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (data->map.map[y][x] == 'C')
			{
				if (flag_colletc1 == 0)
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->sprites.collec1.img, x * 64, y * 64);
				else
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->sprites.collec2.img, x * 64, y * 64);
			}
			x++;
		}
	}
	flag_colletc1 = !flag_colletc1;
	usleep(500000);
	return (0);
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
	mlx_loop_hook(data.mlx_ptr, animation, &data);
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
	[x] Make the player lose when they touch an enemy patrol.
	[x]	Add some sprite animation.
	[x] Display the movement count directly on screen instead
			of writing it in the shell
*/
