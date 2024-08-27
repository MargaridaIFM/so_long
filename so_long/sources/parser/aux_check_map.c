/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_check_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:25:03 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/27 01:09:39 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
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
void	flood_fill_map(char **temp_map, int y, int x)
{
	if (temp_map[y][x] != '1' && temp_map[y][x] != '2')
	{
		temp_map[y][x] = '2';
		flood_fill_map(temp_map, y - 1, x);
		flood_fill_map(temp_map, y + 1, x);
		flood_fill_map(temp_map, y, x - 1);
		flood_fill_map(temp_map, y, x + 1);
	}
}
void	check_flood_fill(char **temp_map, t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (temp_map[y])
	{
		x = 0;
		while (temp_map[y][x])
		{
			if (temp_map[y][x] != '1' && temp_map[y][x] != '2')
				free_exit(data, "Error - Exit and/or collectibles not accessible by the player\n");
			x++;
		}
		y++;
	}
}
char	**copy_map(char **map, int rows, int cols)
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
