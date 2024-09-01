/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:17:58 by mfrancis          #+#    #+#             */
/*   Updated: 2024/09/01 16:29:54 by mfrancis         ###   ########.fr       */
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
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>

//#define malloc(x) NULL

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_map
{
	char		**map;
	int			cols;
	int			rows;
	int			nb_collect;
	int			coll_p;
	int			exit_p;
	int			exit_x;
	int			exit_y;
}				t_map;

typedef struct s_player
{
	int			x;
	int			y;
	t_img		p_f;
	t_img		p_b;
	t_img		p_r;
	t_img		p_l;
}				t_player;

typedef struct s_sprites
{
	t_img		floor;
	t_img		wall;
	t_img		collec1;
	t_img		collec2;
	t_img		exit1;
	t_img		exit2;
	t_img		enemy;
}				t_sprites;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_player	player;
	t_sprites	sprites;
	int			screen_w_max;
	int			screen_h_max;
	int			moves;
}				t_data;

void			check_map(t_data *data, char *file_name);
void			valid_chars(t_data *data);
void			check_walls(t_data *data);
void			empty_path(t_data *data);
int				ft_strlen_no_newline(char *s);
void			free_exit(t_data *data, char *str);
void			free_array(t_data *data);
void			free_array_char(char **array);
void			free_sprites(t_data *data);
void			free_player(t_data *data);
void			init_game(t_data *data);
void			draw_images(t_data *data);
void			draw_player(int keysym, t_data *data);
void			put_moves_screen(t_data *data);
void			call_hooks(t_data *data);

#endif
