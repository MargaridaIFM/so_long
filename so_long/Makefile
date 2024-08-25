.SILENT:

NAME			=	so_long

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror -gdwarf-4 #-fsanitize=thread

RM				=	rm -rf

INC_DIR			=	includes/

SRC_DIR			=	sources/

OBJ_DIR			=	objs/

#PROG_DIR		=	program/

PARSER_DIR		=	parser/

#RAY_DIR			=	raytrace/

#MATH_DIR		=	math/

#TYPES_DIR		=	t_types/

ERROR_DIR		=	errors/

DISPLAY_DIR		=	display/

LIBS_DIR		=	libraries/

LFT_PATH		=	$(addprefix $(LIBS_DIR), libft/)

MLX_PATH		=	$(addprefix $(LIBS_DIR), minilibx-linux/)

LINKS			=	-lm -lXext -lX11 -L$(MLX_PATH) -lmlx -L$(LFT_PATH) -lft

SRC				=	$(addprefix $(SRC_DIR), so_long.c) \
					$(addprefix $(SRC_DIR)$(PARSER_DIR), check_map.c) \
					$(addprefix $(SRC_DIR)$(PARSER_DIR), check_criteria.c) \
					$(addprefix $(SRC_DIR)$(PARSER_DIR), aux_check_map.c) \
					$(addprefix $(SRC_DIR)$(ERROR_DIR), errors.c) \
					$(addprefix $(SRC_DIR)$(DISPLAY_DIR), display.c)

OBJ_DIRS		=	$(OBJ_DIR) $(addprefix $(OBJ_DIR), $(PARSER_DIR)) \
					$(addprefix $(OBJ_DIR), $(ERROR_DIR)) \
					$(addprefix $(OBJ_DIR), $(DISPLAY_DIR))

OBJ				=	$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

$(NAME):			$(OBJ) | $(SRC)
					printf 'Compiling $(NAME)\n'
					$(CC) $(CFLAGS) $^ -o $@ -I $(INC_DIR) $(LINKS)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c | $(OBJ_DIRS)
					make dependecies
					printf "Compiling $(NAME) objects... %-33.33s\r" $(notdir $@)
					$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR) 

$(OBJ_DIRS):
					mkdir -p $@

all:				$(NAME)

dependecies:
					make -C $(MLX_PATH)
					make -C $(LFT_PATH)

clean:
					if [ -d $(OBJ_DIR) ]; then $(RM) $(OBJ_DIR); fi
					if [ -d $(DEBUG_DIR) ]; then $(RM) $(DEBUG_DIR); fi

fclean:				clean
					$(RM) $(NAME)
					make fclean -C $(LFT_PATH)
					make clean -C $(MLX_PATH)

re:					fclean all

.PHONY:				all clean fclean re
