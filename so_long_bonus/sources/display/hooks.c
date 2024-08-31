/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 23:09:54 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/31 13:59:17 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	update_img(t_data *data, int y, int x)
{
	data->map.map[y][x] = '0';
	data->map.nb_collect--;
	if (data->map.nb_collect == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.exit2.img, data->map.exit_x * 64, data->map.exit_y
			* 64);
}

static int	verify_move(t_data *data, int keysym)
{
	int	y;
	int	x;

	y = data->player.y;
	x = data->player.x;
	if (keysym == XK_w || keysym == XK_Up)
		y--;
	else if (keysym == XK_s || keysym == XK_Down)
		y++;
	else if (keysym == XK_a || keysym == XK_Left)
		x--;
	else if (keysym == XK_d || keysym == XK_Right)
		x++;
	if (data->map.map[y][x] == '1' || (data->map.map[y][x] == 'E'
			&& data->map.nb_collect != 0))
		return (1);
	else if (data->map.map[y][x] == 'C')
	{
		update_img(data, y, x);
		return (0);
	}
	else if (data->map.map[y][x] == 'E' && data->map.nb_collect == 0)
		free_exit(data, "");
	return (0);
}

static int	handle_key(int keysym, t_data *data)
{
	if (verify_move(data, keysym) != 0)
		return (0);
	put_moves_screen(data);
	ft_printf("Moves %d\n", data->moves++);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->sprites.floor.img, data->player.x * 64, data->player.y * 64);
	if (keysym == XK_Escape)
		free_exit(data, "");
	else if (keysym == XK_w || keysym == XK_Up)
		data->player.y--;
	else if (keysym == XK_s || keysym == XK_Down)
		data->player.y++;
	else if (keysym == XK_a || keysym == XK_Left)
		data->player.x--;
	else if (keysym == XK_d || keysym == XK_Right)
		data->player.x++;
	data->map.map[data->player.y][data->player.x] = 'P';
	draw_player(keysym, data);
	return (0);
}

static int	press_cross(t_data *data)
{
	free_sprites(data);
	free_player(data);
	if (data->map.map)
		free_array(data);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	exit(0);
	return (0);
}

void	call_hooks(t_data *data)
{
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_key, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, press_cross,
		data);
}
