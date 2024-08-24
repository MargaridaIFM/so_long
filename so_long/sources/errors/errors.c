/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:22:46 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/24 11:10:38 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
 
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

void free_exit(t_fdf *fdf, char *str)
{
    if(str && str[0] != '\0')
        ft_putstr_fd(str, 2);
    if(fdf->win_ptr)
    {
        mlx_destroy_window(fdf->mlx_ptr,fdf->win_ptr);
       // free(fdf->win_ptr);
    }
    // ?
    //if(fdf->img)
    //   mlx_destroy_image(fdf->mlx_ptr, fdf->img);
    if(fdf->mlx_ptr)
    {
        mlx_destroy_display(fdf->mlx_ptr);
        free(fdf->mlx_ptr);
    }
    if(fdf->map)
        free_array(fdf);
    exit(0);
}
void	free_array(t_fdf *fdf)
{
    int idx;
    
    idx = 0;
	while (idx < fdf->rows_nb)
	{
		free(fdf->map[idx]);
		idx++;
	}
	free(fdf->map);
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
// void	free_split(char *array)
// {
// 	int	idx;

// 	idx = 0;
// 	while (array[idx])
// 	{
// 		free(array);
// 		idx++;
// 	}
// }
void null_initialization_fdf(t_fdf *fdf)
{
    fdf->mlx_ptr = NULL;
    fdf->win_ptr = NULL;
    fdf->map = NULL;
    fdf->img = NULL;
    fdf->rows_nb = 0;
    fdf->cols_nb = 0;
}