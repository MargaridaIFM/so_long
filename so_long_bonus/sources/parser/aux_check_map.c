/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_check_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:25:03 by mfrancis          #+#    #+#             */
/*   Updated: 2024/09/01 16:31:14 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static char	**copy_map(char **map, int rows, int cols)
{
	char	**new_map;
	int		y;
	int		x;

	new_map = malloc(sizeof(char *) * (rows + 1));
	if (!new_map)
		return (NULL);
	y = 0;
	while (y < rows)
	{
		new_map[y] = malloc((cols + 1) * sizeof(char));
		if (!new_map[y])
			free_array_char(new_map);
		x = 0;
		while (x < cols)
		{
			new_map[y][x] = map[y][x];
			x++;
		}
		new_map[y][x] = '\0';
		y++;
	}
	new_map[y] = NULL;
	return (new_map);
}

static void	flood_fill_map(char **temp_map, int y, int x, t_data *data)
{
	if (temp_map[y][x] == '1' || temp_map[y][x] == '2')
		return ;
	else if (temp_map[y][x] == 'C')
		data->map.coll_p--;
	else if (temp_map[y][x] == 'E')
	{
		data->map.exit_p = 1;
		return ;
	}
	else if (temp_map[y][x] == 'B')
		return ;
	temp_map[y][x] = '2';
	flood_fill_map(temp_map, y - 1, x, data);
	flood_fill_map(temp_map, y + 1, x, data);
	flood_fill_map(temp_map, y, x - 1, data);
	flood_fill_map(temp_map, y, x + 1, data);
}

static void	check_flood_fill(char **temp_map, t_data *data)
{
	if (data->map.coll_p != 0 || data->map.exit_p != 1)
	{
		free_array_char(temp_map);
		free_exit(data, "Error - Elements inaccessible by the player\n");
	}
	free_array_char(temp_map);
}

void	empty_path(t_data *data)
{
	char	**temp_map;

	temp_map = copy_map(data->map.map, data->map.rows, data->map.cols);
	data->map.coll_p = data->map.nb_collect;
	flood_fill_map(temp_map, data->player.y, data->player.x, data);
	check_flood_fill(temp_map, data);
}

int	ft_strlen_no_newline(char *s)
{
	int	idx;

	idx = 0;
	if (!s)
		return (0);
	while (s[idx] && s[idx] != '\n')
		idx++;
	return (idx);
}
