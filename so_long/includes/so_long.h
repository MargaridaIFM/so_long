/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:17:58 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/25 00:36:23 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/libft/libft.h"
# include "../libraries/minilibx-linux/mlx.h"
# include "X11/X.h"
# include "X11/keysym.h"
# include <math.h>
# include <stdio.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		**map;
	t_img	*img;
	int		cols_nb;
	int		rows_nb;
	int		ofset;
}			t_data;

// Parsing:
void check_map(t_data *data, char *file_name);
int check_file_name(char *file_name);
void check_map_shape(t_data *data, int fd);

//auxiliar functions
int	ft_strlen_no_newline(char *s);

// errors:
void free_exit(t_data *data, char *str);
void null_initialization_data(t_data *data);

// Display:

// Functions for Hooks and Masks

#endif

//# define MALLOC_ERROR "Failure in memory alocation"
// typedef enum s_error_msg
// {
// 	NO_ERROR,
// 	MLX_ERROR,
// 	LEN_ERROR_MSG
// }			t_error_msg;