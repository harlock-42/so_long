# Colors

C_GREY		=	\e[1;30m
C_RED		=	\e[1;31m
C_GREEN		=	\e[1;32m
C_YELLOW	=	\e[1;33m
C_BLUE		=	\e[1;34m
C_PURPLE	=	\e[1;35m
C_CYAN		=	\e[1;36m
C_WHITE		=	\e[1;37m
C_END		=	\e[0m


NAME	=	so_long

CC	=	clang

RM	=	rm -rf

CP	=	cp -r

CFLAGS	=	-Werror -Wextra -Wall -c -g3

LFLAGS		=	-lm -lbsd -lX11 -lXext

SRC		+=	check_map.c
SRC		+=	color_px.c
SRC		+=	color_player_px.c
SRC		+=	color_sprite_px.c
SRC		+=	engine.c
SRC		+=	escape_game.c
SRC		+=	get_map.c
SRC		+=	get_map_size.c
SRC		+=	get_px_color_spawn.c
SRC		+=	is_character_in_the_map.c
SRC		+=	is_map_closed.c
SRC		+=	is_map_rectangular.c
SRC		+=	key.c
SRC		+=	load_sprite.c
SRC		+=	main.c
SRC		+=	move.c
SRC		+=	my_mlx_pixel_put.c
SRC		+=	new_image.c
SRC		+=	paint_moving_sprite.c
SRC		+=	parser.c
SRC		+=	print_map.c
SRC		+=	sl_error.c
SRC		+=	wich_case_map.c

SRC_BONUS	+=	calcul_move_bonus.c
SRC_BONUS	+=	check_map_bonus.c
SRC_BONUS	+=	color_px_bonus.c
SRC_BONUS	+=	color_sprite_px_bonus.c
SRC_BONUS	+=	engine_bonus.c
SRC_BONUS	+=	escape_game_bonus.c
SRC_BONUS	+=	get_map_bonus.c
SRC_BONUS	+=	get_map_size_bonus.c
SRC_BONUS	+=	get_px_color_spawn_bonus.c
SRC_BONUS	+=	is_character_in_the_map_bonus.c
SRC_BONUS	+=	is_map_closed_bonus.c
SRC_BONUS	+=	is_map_rectangular_bonus.c
SRC_BONUS	+=	key_bonus.c
SRC_BONUS	+=	load_sprite_bonus.c
SRC_BONUS	+=	main_bonus.c
SRC_BONUS	+=	move_bonus.c
SRC_BONUS	+=	my_mlx_pixel_put_bonus.c
SRC_BONUS	+=	new_image_bonus.c
SRC_BONUS	+=	paint_moving_sprite_bonus.c
SRC_BONUS	+=	paint_number_sprite_bonus.c
SRC_BONUS	+=	parser_bonus.c
SRC_BONUS	+=	print_map_bonus.c
SRC_BONUS	+=	sl_error_bonus.c
SRC_BONUS	+=	wich_case_map_bonus.c

OBJ_PATH	=	./.obj/

OBJ_PATH_BONUS	=	./.obj_bonus/

vpath %.c srcs/
vpath %.c srcs/engine/
vpath %.c srcs/engine/move/
vpath %.c srcs/load_sprite/
vpath %.c srcs/key/
vpath %.c srcs/parser/
vpath %.c srcs/parser/checker/
vpath %.c srcs/utils/
vpath %.c srcs_bonus/
vpath %.c srcs_bonus/engine_bonus/
vpath %.c srcs_bonus/engine_bonus/calcul_move_bonus/
vpath %.c srcs_bonus/engine_bonus/move_bonus/
vpath %.c srcs_bonus/load_sprite_bonus/
vpath %.c srcs_bonus/key_bonus/
vpath %.c srcs_bonus/parser_bonus/
vpath %.c srcs_bonus/parser_bonus/checker_bonus/
vpath %.c srcs_bonus/utils_bonus/


OBJ		=	$(patsubst %.c, $(OBJ_PATH)%.o, $(SRC))

OBJ_BONUS	=	$(patsubst %.c, $(OBJ_PATH_BONUS)%.o, $(SRC_BONUS))

LIBFT_NAME	=	libft.a

LIBMLX_NAME		= libmlx_Linux.a

HEADER_NAME	=	so_long.h

HEADER_NAME_BONUS	=	so_long_bonus.h

LIB_PATH	=	./.lib

HEADER_PATH	=	./include

HEADER_PATH_BONUS	=	./include_bonus

LIBFT_PATH	=	./libft

MLX_LINUX_PATH	=	./minilibx_linux

LIBFT_SRC	=	$(addprefix $(LIBFT_PATH)/, $(LIBFT_NAME))

LIBFT		=	$(addprefix $(LIB_PATH)/, $(LIBFT_NAME))

HEADER		=	$(addprefix $(HEADER_PATH)/, $(HEADER_NAME))

HEADER_BONUS	=	$(addprefix $(HEADER_PATH_BONUS)/, $(HEADER_NAME_BONUS))

LIBMLX_LINUX	=	$(addprefix $(MLX_LINUX_PATH)/, $(LIBMLX_NAME))

all: $(NAME)

$(NAME): $(LIB_PATH) $(LIBFT_SRC) $(LIBFT) $(OBJ_PATH) $(OBJ) $(LIBMLX_LINUX)
	@$(CC) -I$(HEADER_PATH)/ -o $(NAME) $(OBJ) $(LIBFT) $(LIBMLX_LINUX) $(LFLAGS)
	@echo "$<		[$(C_GREEN)OK$(C_END)]"


$(OBJ): $(OBJ_PATH)%.o: %.c $(HEADER)
	@$(CC) -I$(HEADER_PATH)/ $(CFLAGS) $< -o $@

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

bonus : $(NAME) $(LIB_PATH) $(LIBFT_SRC) $(LIBFT) $(OBJ_PATH_BONUS) $(OBJ_BONUS) $(LIBMLX_LINUX)
	@$(CC) -I$(HEADER_PATH_BONUS)/ -o $(NAME) $(OBJ_BONUS) $(LIBFT) $(LIBMLX_LINUX) $(LFLAGS)
	@echo "$<		[$(C_GREEN)OK$(C_END)]"

$(OBJ_BONUS): $(OBJ_PATH_BONUS)%.o: %.c $(HEADER_BONUS)
	@$(CC) -I$(HEADER_PATH_BONUS)/ $(CFLAGS) $< -o $@

$(OBJ_PATH_BONUS):
	@mkdir $(OBJ_PATH_BONUS)

$(LIBFT):
	@$(CP) $(LIBFT_SRC) $(LIB_PATH)

$(LIBFT_SRC):
	@(cd $(LIBFT_PATH) && $(MAKE))

$(LIB_PATH):
	@mkdir $(LIB_PATH)

$(LIBMLX_LINUX):
	@(cd $(MLX_LINUX_PATH) && $(MAKE))

clean:
	@$(RM) $(OBJ_PATH)
	@$(RM) $(OBJ_PATH_BONUS)
	@(cd $(LIBFT_PATH) && $(MAKE) clean)
	@(cd $(MLX_LINUX_PATH) && $(MAKE) clean)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIB_PATH)
	@(cd $(LIBFT_PATH) && $(MAKE) fclean)

re: fclean all
