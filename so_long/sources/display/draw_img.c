/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 23:01:15 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/30 23:55:33 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	draw_background(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->sprites.floor.img, x * 64, y * 64);
			if (data->map.map[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprites.wall.img, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
static void	draw_elements(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (data->map.map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprites.exit1.img, x * 64, y * 64);
			if (data->map.map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprites.collec1.img, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
void	draw_player(int keysym, t_data *data)
{
	if (keysym == XK_w || keysym == XK_Up)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.p_b.img, data->player.x * 64, data->player.y * 64);
	else if (keysym == XK_s || keysym == XK_Down)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.p_f.img, data->player.x * 64, data->player.y * 64);
	else if (keysym == XK_a || keysym == XK_Left)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.p_l.img, data->player.x * 64, data->player.y * 64);
	else if (keysym == XK_d || keysym == XK_Right)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player.p_r.img, data->player.x * 64, data->player.y * 64);
}
void	draw_images(t_data *data)
{
	draw_background(data);
	draw_elements(data);
	draw_player(XK_s, data);
}