/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:54:34 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/24 11:10:45 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void  init_fdf (t_fdf *fdf)
{
    // map_scale(fdf);
    fdf->mlx_ptr = mlx_init();
    if(fdf->mlx_ptr == NULL)
        free_exit(fdf, "Error");
    fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Fdf");
    if(fdf->win_ptr == NULL)
        free_exit(fdf, "Error");
    //fdf->img->img = mlx_new_image(fdf->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    
    mlx_key_hook(fdf->win_ptr, handle_input, fdf);

    mlx_loop(fdf->mlx_ptr);
    //mlx_mouse_hook();
    
}
int handle_input(int keysym, t_fdf *fdf)
{
    if(keysym == XK_Escape)
        free_exit(fdf, "");
    return(0);
}
// void map_scale(t_fdf *fdf)
// {

// }
// void screen_size(t_fdf *fdf)
// {

// }

// INITIATION FDF:
// [] check the windows and map size, Etc;
// [] open the window
// [] display the map
// [] hook the keys
// [] hook the mouse
// [] hook close window
// 