/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:17:58 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/29 23:20:26 by mfrancis         ###   ########.fr       */
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

typedef struct s_img
{
	void		*img;
	char		*addr;
	int 		width; // nao incializado!!!
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
	int			flag_exit;
	int 		exit_x;
	int 		exit_y;
}				t_map;
// incluir flags p a exit ?

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
	// void		*collec2;
	// void		*collec3;
	// void		*collec4;
	// void		*collec5;
	t_img		exit1;
	t_img		exit2;

}				t_sprites;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	// int 		height_img; // passar p macro ? - esta so no errors
	// int 		width_img;  // macro ?
	t_player	player;
	t_sprites	sprites;
	// int			win_height;
	// int			win_width;
	int			screen_w_max;
	int			screen_h_max;
	int			moves;
}				t_data;

// Parsing:
void			check_map(t_data *data, char *file_name);
int				check_file_name(char *file_name);
void			check_map_shape(t_data *data, int fd);
void			loading_map(t_data *data, int fd);
void			check_map_criteria(t_data *data);

// check criteria
void			valid_chars(t_data *data);
void			check_num_p(t_data *data, char c);
void			check_num_c(t_data *data, char c);
void			check_num_e(t_data *data, char c);
void			check_walls(t_data *data);
void			empty_path(t_data *data);

// auxiliar functions
int				ft_strlen_no_newline(char *s);
void			print_map(char **map);
void			flood_fill_map(char **temp_map, int y, int x, t_data *data);
void			check_flood_fill(char **temp_map, t_data *data);
char			**copy_map(char **map, int rows, int cols);

// errors:
void			free_exit(t_data *data, char *str);
void			free_array(t_data *data);
void			free_array_char(char **array);
void			free_sprites(t_data *data);
void			free_player(t_data *data);
void			initialization_data(t_data *data);

// Display:
void			init_game(t_data *data);
void			load_sprites(t_data *data);
void			draw_images(t_data *data);
void			draw_background(t_data *data);
void			draw_elements(t_data *data);
void			draw_player(int keysym, t_data *data);


// Functions for Hooks and Masks
void			call_hooks(t_data *data);
int				handle_key(int keysym, t_data *data); // provisoria;
int 			verify_move (t_data *data, int keysym);
#endif

//# define MALLOC_ERROR "Failure in memory alocation"
// typedef enum s_error_msg
// {
// 	NO_ERROR,
// 	MLX_ERROR,
// 	LEN_ERROR_MSG
// }			t_error_msg;