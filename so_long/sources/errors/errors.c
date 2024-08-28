/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:22:46 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/28 23:28:35 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// passar para static ? and include one part to free the memory or create a function with both?

// void error_messages(t_error_msg enum_msg)
// {
//     char *msg_to_print[3] = {"", "Failure in memory alocation",
//	"MLX failure"};
//     if(enum_msg < 0 || enum_msg > LEN_ERROR_MSG)
//         return ;
//     else
//     {
//         ft_putstr_fd(msg_to_print[enum_msg], 2);
//         ft_putstr_fd("\n", 2);
//     }
// }

void	free_exit(t_data *data, char *str)
{
	if (str && str[0] != '\0')
		ft_putstr_fd(str, 2);
    free_sprites(data);
	free_player(data);
	if (data->map.map)
		free_array(data);
	if (data->win_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		//free(data->win_ptr);
	}
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	exit(0);
}
void	free_array(t_data *data)
{
	int	idx;

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
void	free_sprites(t_data *data)
{
	if (data->sprites.floor.img)
    {
        mlx_destroy_image(data->mlx_ptr, data->sprites.floor.img);
        data->sprites.floor.img = NULL;    
    }
	if (data->sprites.wall.img)
    {
        mlx_destroy_image(data->mlx_ptr, data->sprites.wall.img);
        data->sprites.wall.img = NULL;            
    }
	if (data->sprites.collec1.img)
    {
        mlx_destroy_image(data->mlx_ptr, data->sprites.collec1.img);
        data->sprites.collec1.img = NULL;            
    }
	if (data->sprites.exit1.img)
    {
        mlx_destroy_image(data->mlx_ptr, data->sprites.exit1.img);
        data->sprites.exit1.img = NULL;            
    }
	if (data->sprites.exit2.img)
    {
        mlx_destroy_image(data->mlx_ptr, data->sprites.exit2.img);
        data->sprites.exit2.img = NULL;            
    }
}
void	free_player(t_data *data)
{
	if (data->player.p_f.img)
    {
        mlx_destroy_image(data->mlx_ptr, data->player.p_f.img);
        data->player.p_f.img = NULL;            
    }
		if (data->player.p_b.img)
    {
        mlx_destroy_image(data->mlx_ptr, data->player.p_b.img);
        data->player.p_b.img = NULL;            
    }
		if (data->player.p_r.img)
    {
        mlx_destroy_image(data->mlx_ptr, data->player.p_r.img);
        data->player.p_r.img = NULL;            
    }
		if (data->player.p_l.img)
    {
        mlx_destroy_image(data->mlx_ptr, data->player.p_l.img);
        data->player.p_l.img = NULL;            
    }
}
void	initialization_data(t_data *data)
{
    ft_bzero(data, sizeof(t_data));
	data->sprites.floor.width = 64;
	data->sprites.floor.height = 64;
	data->sprites.wall.width = 64;
	data->sprites.wall.height = 64;
	data->sprites.collec1.width = 64;
	data->sprites.collec1.height = 64;
	data->sprites.exit1.width = 64;
	data->sprites.exit1.height = 64;
	data->sprites.exit2.width = 64;
	data->sprites.exit2.height = 64;
	data->player.p_f.width = 64;
	data->player.p_f.height = 64;
	data->player.p_b.width = 64;
	data->player.p_b.height = 64;
	data->player.p_r.width = 64;
	data->player.p_r.height = 64;
	data->player.p_l.width = 64;
	data->player.p_l.height = 64;	
}
