/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:27:40 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/25 15:44:20 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map(t_data *data, char *file_name)
{
	int	fd;

	if (check_file_name(file_name) != 1)
		free_exit(data, "Error - Wrong file name format\n");
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		free_exit(data, "Error - File is not in the repository.\n");
	check_map_shape(data, fd);
	//ft_printf("Number of coluns: %d\n", data->cols);
	//ft_printf("Number of rows: %d\n", data->rows);
    close(fd);
    fd = open(file_name, O_RDONLY);
    if (fd == -1)
		free_exit(data, "Error - Could not reopen file.\n");
    loading_map(data, fd);
	print_map(data->map);
    close(fd);
	check_map_criteria(data);
}
void  check_map_criteria(t_data *data)
{ 
    valid_chars(data);
    check_walls(data);
    printf("Collectables: %d\n", data->colect);
    empty_path(data);
}
int	check_file_name(char *file_name)
{
	int	len;

	if (!file_name)
		return (0);
	len = ft_strlen(file_name);
	if (len < 4)
		return (0);
	if (strncmp(&file_name[len - 4], ".ber", 4) == 0)
		return (1);
	return (0);
}

void	check_map_shape(t_data *data, int fd)
{
	char	*line;
	int		check_cols;

	line = get_next_line(fd);
	if (!line)
		free_exit(data, "Error - File is empty.\n");
	data->cols = ft_strlen_no_newline(line);
	//ft_printf("First line length: %d\n", data->cols);
	while (line)
	{
		data->rows++;
		check_cols = ft_strlen_no_newline(line);
		//ft_printf("Line %d length: %d\n", data->rows, check_cols);
		if (data->cols != check_cols)
		{
			free(line);
			free_exit(data, "Error - Isn't a parallelogram.\n");
		}
		free(line);
		line = get_next_line(fd);
	}
	if (data->cols == data->rows)
		free_exit(data, "Error - Isn't a rectangule\n");
}

void	loading_map(t_data *data, int fd)
{
	int	i;
    int	j;
    char *line;

    i = 0;
	data->map = malloc((data->rows + 1) * sizeof(char *));
	if (!data->map)
		free_exit(data, "Error - Malloc error.\n");
	while (i < data->rows)
	{
        line = get_next_line(fd);
        if (!line)
			free_exit(data, "Error - Reading line failed.\n");
		data->map[i] = malloc((data->cols + 1) * sizeof(char));
		if (!data->map[i])
			free_exit(data, "Error - Malloc error.\n");
        j = 0;
		while (j < data->cols)
		{
			data->map[i][j] = line[j];
			//printf("Map[%d][%d] %c\n", i, j, data->map[i][j]);
			j++;
		}
        data->map[i][j] = '\0';
        free(line);
		i++;
	}
    data->map[i] = NULL;
}

/*
[]PARSING
	[] Map checklist
		[x] finish in .ber
		[x] Does the file exist
		[x] Is rectangular
			[x]num of line != num of colum
		[x] the map have content
        [x] Load the map;
		[x] The map can be composed of only these 5 characters:
			[x] 0 for an empty space,
			[x] 1 for a wall,
			[x] C for a collectible,
			[x] E for the exit,
			[x] P for the player’s starting position.
        [x] must contain
			[x] 1 exit
			[x] 1 or more collectible
			[x] 1 starting position
        [x] be closed/surrounded by walls
IMP --->[] message"Error\n"

	[]	Exit accessible and all the collectibles accessible from the start position
		[] flood fill
		[] counter for the C and E;
		[] compare the counter with the number of C and E(parsing)
*/

