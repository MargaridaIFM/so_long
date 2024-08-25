/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_criteria.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:16:49 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/25 15:54:26 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

void valid_chars(t_data *data)
{
	int y;
	int x;

	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->cols)
		{
			if (data->map[i][j] != '0' && data->map[i][j] != '1'
				&& data->map[i][j] != 'P' && data->map[i][j] != 'E'
				&& data->map[i][j] != 'C')
				free_exit(data, "Error - Invalid elements\n");
            x++;    
		}
        y++;
	}
    check_num_elem(data, 'P');
    check_num_elem(data, 'E');
    check_num_c(data, 'C');
}

void check_num_elem(t_data *data, char c)
{  
    int y;
    int x;
    int counter;

    y = 0;
    counter = 0;
    while (y < data->rows)
    {
        x = 0;
        while (x < data->cols)
        {
            if (data->map[i][j] == c)
                counter++;
        x++;
        }
        y++;
    }
     if(counter != 1)
        free_exit(data, "Error - Invalid number of elements\n");
}
void check_num_c(t_data *data, char c)
{ 
    int y;
    int x;
    int counter;

    y = 0;
    counter = 0;
    while (y < data->rows)
    {
        x = 0;
        while (x < data->cols)
        {
            if (data->map[i][j] == c)
                counter++;
            x++;
        }
        y++;
    }
    if(counter < 1)
       free_exit(data, "Error - Invalid number of elements\n");
    data->colect = counter;
}
void check_walls(t_data *data)
{
    int i;
    
    i = -1;
    while(++i < data->cols)
    {   
        if(data->map[0][i] != '1')
            free_exit(data, "Error 1 - Map isn't sorrounded by walls\n");
    }
    i = -1;
    while(++i < data->cols)
    {   
        if(data->map[data->rows - 1][i] != '1')
            free_exit(data, "Error 2- Map isn't sorrounded by walls\n");
    }
    i = -1;
    while(++i < data->rows)
    {   
        if(data->map[i][0] != '1')
            free_exit(data, "Error 3 - Map isn't sorrounded by walls\n");
    }
    i = -1;
    while(++i < data->rows)
        if(data->map[i][data->cols - 1] != '1')
            free_exit(data, "Error 4 - Map isn't sorrounded by walls\n");
}
