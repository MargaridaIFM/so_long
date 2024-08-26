/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:22:46 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/26 23:50:40 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
 
// passar para static ? and include one part to free the memory or create a function with both?

// void error_messages(t_error_msg enum_msg)
// {
//     char *msg_to_print[3] = {"", "Failure in memory alocation", "MLX failure"};
//     if(enum_msg < 0 || enum_msg > LEN_ERROR_MSG)
//         return ;
//     else
//     {
//         ft_putstr_fd(msg_to_print[enum_msg], 2);
//         ft_putstr_fd("\n", 2);
//     }
// }

void free_exit(t_data *data, char *str)
{
    if(str && str[0] != '\0')
        ft_putstr_fd(str, 2);
    if(data->map.map)
       free_array(data);
    // if(data->img)
    //   mlx_destroy_image(data->mlx_ptr, data->img);
    if(data->win_ptr)
    {
        mlx_destroy_window(data->mlx_ptr,data->win_ptr);
       //free(data->win_ptr);
    }
    if(data->mlx_ptr)
    {
        mlx_destroy_display(data->mlx_ptr);
        free(data->mlx_ptr);
    }
    exit(0);
}
void	free_array(t_data *data)
{
    int idx;
    
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
// // void	free_split(char *array)
// // {
// // 	int	idx;

// // 	idx = 0;
// // 	while (array[idx])
// // 	{
// // 		free(array);
// // 		idx++;
// // 	}
// // }
void null_initialization_data(t_data *data)
{
    data->mlx_ptr = NULL;
    data->win_ptr = NULL;
    data->height_img = 64;
    data->width_img = 64;
    data->map.map = NULL;
    data->map.rows = 0;
    data->map.cols = 0;
    data->player.x = 0;
    data->player.y = 0;
}