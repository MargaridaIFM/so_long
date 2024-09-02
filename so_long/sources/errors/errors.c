/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:22:46 by mfrancis          #+#    #+#             */
/*   Updated: 2024/09/01 16:32:15 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_exit(t_data *data, char *str)
{
	if (str && str[0] != '\0')
		ft_putstr_fd(str, 2);
	if (!data)
		exit(0);
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
}

void	free_array(t_data *data)
{
	int	idx;

	idx = 0;
	while (data->map.map[idx])
	{
		free(data->map.map[idx]);
		idx++;
	}
	free(data->map.map);
}

void	free_array_char(char **array)
{
	int	idx;

	idx = 0;
	while (array[idx])
	{
		free(array[idx]);
		idx++;
	}
	free(array);
}

void	free_sprites(t_data *data)
{
	if (data->sprites.floor.img)
		mlx_destroy_image(data->mlx_ptr, data->sprites.floor.img);
	if (data->sprites.wall.img)
		mlx_destroy_image(data->mlx_ptr, data->sprites.wall.img);
	if (data->sprites.collec1.img)
		mlx_destroy_image(data->mlx_ptr, data->sprites.collec1.img);
	if (data->sprites.collec2.img)
		mlx_destroy_image(data->mlx_ptr, data->sprites.collec2.img);
	if (data->sprites.exit1.img)
		mlx_destroy_image(data->mlx_ptr, data->sprites.exit1.img);
	if (data->sprites.exit2.img)
		mlx_destroy_image(data->mlx_ptr, data->sprites.exit2.img);
	if (data->sprites.enemy.img)
		mlx_destroy_image(data->mlx_ptr, data->sprites.enemy.img);
}

void	free_player(t_data *data)
{
	if (data->player.p_f.img)
		mlx_destroy_image(data->mlx_ptr, data->player.p_f.img);
	if (data->player.p_b.img)
		mlx_destroy_image(data->mlx_ptr, data->player.p_b.img);
	if (data->player.p_r.img)
		mlx_destroy_image(data->mlx_ptr, data->player.p_r.img);
	if (data->player.p_l.img)
		mlx_destroy_image(data->mlx_ptr, data->player.p_l.img);
}
