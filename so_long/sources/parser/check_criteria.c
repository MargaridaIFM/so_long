/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_criteria.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:16:49 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/30 15:57:34 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
	check_num_p(data, 'P');
	//printf("Player y:%d x:%d\n", data->player.y, data->player.x);
	check_num_e(data, 'E');
	check_num_c(data, 'C');
  //  printf("Collectables: %d\n", data->map.nb_collect);

}
void	check_num_p(t_data *data, char c)
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
				if (data->map.map[y][x] == 'P')
				{
					data->player.x = x;
					data->player.y = y;
				}
			}
			x++;
		}
	}
	if (counter != 1)
		free_exit(data, "Error - Invalid number of elements\n");
}
void	check_num_e(t_data *data, char c)
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
				if (data->map.map[y][x] == 'E')
				{
					data->map.exit_x = x;
					data->map.exit_y = y;
				}
			}
			x++;
		}
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
	data->map.nb_collect = counter;
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

void empty_path(t_data *data)
{
    char **temp_map;

    temp_map = copy_map(data->map.map, data->map.rows, data->map.cols);
	//print_map(data->map.map);
	//printf("\n");
	//print_map(temp_map);
	//printf("entrou aqui dentro: %c\n", temp_map[data->player.y][data->player.x]);
	data->map.coll_p = data->map.nb_collect;
	flood_fill_map(temp_map, data->player.y, data->player.x, data);
	//printf("\n");
	check_flood_fill(temp_map, data);
	//print_map(temp_map);
	free_array_char(temp_map);
	
}
