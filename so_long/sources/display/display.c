/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:54:34 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/25 16:11:04 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// void  init_data (t_data *data)
// {
//     // map_scale(data);
//     data->mlx_ptr = mlx_init();
//     if(data->mlx_ptr == NULL)
//         free_exit(data, "Error");
//     //data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "data");
//     if(data->win_ptr == NULL)
//         free_exit(data, "Error");
//     //data->img->img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    
//     mlx_key_hook(data->win_ptr, handle_input, data);

//     mlx_loop(data->mlx_ptr);
//     //mlx_mouse_hook();
    
// }
// int handle_input(int keysym, t_data *data)
// {
//     if(keysym == XK_Escape)
//         free_exit(data, "");
//     return(0);
// }
// // void map_scale(t_data *data)
// // {

// // }
// // void screen_size(t_data *data)
// // {

// // }

// // INITIATION data:
// // [] check the windows and map size, Etc;
// // [] open the window
// // [] display the map
// // [] hook the keys
// // [] hook the mouse
// // [] hook close window
// // 