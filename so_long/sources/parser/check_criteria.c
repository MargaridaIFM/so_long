/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_criteria.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:16:49 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/31 13:52:46 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	check_char(t_data *data, int y, int x, char c)
{
	if (c == 'P')
	{
		data->player.x = x;
		data->player.y = y;
	}
	if (c == 'E')
	{
		data->map.exit_x = x;
		data->map.exit_y = y;
	}
}

static void	check_nb_elements(t_data *data, char c)
{
	int	y;
	int	x;
	int	counter;

	y = -1;
	counter = 0;
	while (++y < data->map.rows)
	{
		x = 0;
		while (x < data->map.cols)
		{
			if (data->map.map[y][x] == c)
			{
				counter++;
				check_char(data, y, x, c);
			}
			x++;
		}
	}
	if (counter != 1)
		free_exit(data, "Error - Invalid number of elements\n");
}

static void	check_num_c(t_data *data, char c)
{
	int	y;
	int	x;
	int	counter;

	y = 0;
	counter = 0;
	while (y < data->map.rows)
	{
		x = 0;
		while (x < data->map.cols)
		{
			if (data->map.map[y][x] == c)
				counter++;
			x++;
		}
		y++;
	}
	if (counter < 1)
		free_exit(data, "Error - Invalid number of elements\n");
	data->map.nb_collect = counter;
}

void	valid_chars(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map.rows)
	{
		x = 0;
		while (x < data->map.cols)
		{
			if (data->map.map[y][x] != '0' && data->map.map[y][x] != '1'
				&& data->map.map[y][x] != 'P' && data->map.map[y][x] != 'E'
				&& data->map.map[y][x] != 'C')
				free_exit(data, "Error - Invalid elements\n");
			x++;
		}
		y++;
	}
	check_nb_elements(data, 'P');
	check_nb_elements(data, 'E');
	check_num_c(data, 'C');
}

void	check_walls(t_data *data)
{
	int	y;
	int	x;
	int	col;
	int	row;

	col = data->map.cols - 1;
	row = data->map.rows - 1;
	x = 0;
	while (x < data->map.cols)
	{
		if (data->map.map[0][x] != '1' || data->map.map[row][x] != '1')
			free_exit(data, "Error - Map isn't surrounded by walls\n");
		x++;
	}
	y = 0;
	while (y < data->map.rows)
	{
		if (data->map.map[y][0] != '1' || data->map.map[y][col] != '1')
			free_exit(data, "Error - Map isn't surrounded by walls\n");
		y++;
	}
}
// void	check_num_p(t_data *data, char c)
// {
// 	int	y;
// 	int	x;
// 	int	counter;

// 	y = -1;
// 	counter = 0;
// 	while (++y < data->map.rows)
// 	{
// 		x = 0;
// 		while (x < data->map.cols)
// 		{
// 			if (data->map.map[y][x] == c)
// 			{
// 				counter++;
// 				if (data->map.map[y][x] == 'P')
// 				{
// 					data->player.x = x;
// 					data->player.y = y;
// 				}
// 			}
// 			x++;
// 		}
// 	}
// 	if (counter != 1)
// 		free_exit(data, "Error - Invalid number of elements\n");
// }
// void	check_num_e(t_data *data, char c)
// {
// 	int	y;
// 	int	x;
// 	int	counter;

// 	y = -1;
// 	counter = 0;
// 	while (++y < data->map.rows)
// 	{
// 		x = 0;
// 		while (x < data->map.cols)
// 		{
// 			if (data->map.map[y][x] == c)
// 			{
// 				counter++;
// 				if (data->map.map[y][x] == 'E')
// 				{
// 					data->map.exit_x = x;
// 					data->map.exit_y = y;
// 				}
// 			}
// 			x++;
// 		}
// 	}
// 	if (counter != 1)
// 		free_exit(data, "Error - Invalid number of elements\n");
// }