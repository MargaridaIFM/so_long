/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:17:58 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/31 13:56:48 by mfrancis         ###   ########.fr       */
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
	t_img		exit1;
	t_img		exit2;
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


// Parsing:
void			check_map(t_data *data, char *file_name);

// check criteria
void			valid_chars(t_data *data);
// static void			check_nb_elements(t_data *data, char c);
// static void			check_char(t_data *data, int y, int x, char c);
// static void			check_num_c(t_data *data, char c);
void			check_walls(t_data *data);

// auxiliar functions
void			empty_path(t_data *data);
//char			**copy_map(char **map, int rows, int cols);
int				ft_strlen_no_newline(char *s);
// static void			flood_fill_map(char **temp_map, int y, int x, t_data *data);
// static void			check_flood_fill(char **temp_map, t_data *data);

// errors:
void			free_exit(t_data *data, char *str);
void			free_array(t_data *data);
void			free_array_char(char **array);
void			free_sprites(t_data *data);
void			free_player(t_data *data);

// Display:
void			init_game(t_data *data);
// static void			load_sprites(t_data *data);
// static void			load_player(t_data *data);

//void			print_map(char **map); // tirar no fim o print map / funcao de debbug

 void			draw_images(t_data *data);
// static void			draw_background(t_data *data);
// static void			draw_elements(t_data *data);
void			draw_player(int keysym, t_data *data);
void	put_moves_screen(t_data *data);

// Functions for Hooks and Masks
void			call_hooks(t_data *data);
// static int				handle_key(int keysym, t_data *data);
// static int				verify_move(t_data *data, int keysym);
// static int				press_cross(t_data *data);
// static void 				update_img (t_data *data, int y, int x)
#endif
