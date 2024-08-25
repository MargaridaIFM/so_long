/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_criteria.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:16:49 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/25 17:59:27 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// void  check_map_criteria(t_data data)
// {
// valid_chars
//
//     check_walls()
//         free_exit(data, "Maps is not sorrounded by walls\n");
//
//    empty_path
//         free_exit(data, "Error
//	- Inavlid path to the Exit or collectibles\n");
// }

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
	check_num_elem(data, 'P');
	check_num_elem(data, 'E');
	check_num_c(data, 'C');
}

void	check_num_elem(t_data *data, char c)
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
	if (counter != 1)
		free_exit(data, "Error - Invalid number of elements\n");
}
void	check_num_c(t_data *data, char c)
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
	data->map.collect = counter;
}
// void	check_walls(t_data *data)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < data->map.cols)
// 	{
// 		if (data->map.map[0][i] != '1')
// 			free_exit(data, "Error 1 - Map isn't sorrounded by walls\n");
// 	}
// 	i = -1;
// 	while (++i < data->map.cols)
// 	{
// 		if (data->map.map[data->map.rows - 1][i] != '1')
// 			free_exit(data, "Error 2- Map isn't sorrounded by walls\n");
// 	}
// 	i = -1;
// 	while (++i < data->map.rows)
// 	{
// 		if (data->map.map[i][0] != '1')
// 			free_exit(data, "Error 3 - Map isn't sorrounded by walls\n");
// 	}
// 	i = -1;
// 	while (++i < data->map.rows)
// 		if (data->map.map[i][data->map.cols - 1] != '1')
// 			free_exit(data, "Error 4 - Map isn't sorrounded by walls\n");
// }

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
			free_exit(data, "Error - Map isn't surrounded by walls (top/bottom)\n");
		x++;
	}
    y = 0;
	while (y < data->map.rows)
	{
		if (data->map.map[y][0] != '1' || data->map.map[y][col] != '1')
			free_exit(data, "Error - Map isn't surrounded by walls (left/right)\n");
		y++;
	}
}
