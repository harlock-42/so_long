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

SRC		+=	calcul_move.c
SRC		+=	check_map.c
SRC		+=	color_px.c
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

OBJ_PATH	=	./.obj/

vpath %.c srcs/
vpath %.c srcs/engine/
vpath %.c srcs/engine/calcul_move/
vpath %.c srcs/engine/move/
vpath %.c srcs/load_sprite/
vpath %.c srcs/key/
vpath %.c srcs/parser/
vpath %.c srcs/parser/checker/
vpath %.c srcs/utils/

OBJ		=	$(patsubst %.c, $(OBJ_PATH)%.o, $(SRC))

LIBFT_NAME	=	libft.a

LIBMLX_NAME		= libmlx_Linux.a

HEADER_NAME	=	so_long.h

LIB_PATH	=	./.lib

HEADER_PATH	=	./include

LIBFT_PATH	=	./libft

MLX_LINUX_PATH	=	./minilibx_linux

LIBFT_SRC	=	$(addprefix $(LIBFT_PATH)/, $(LIBFT_NAME))

LIBFT		=	$(addprefix $(LIB_PATH)/, $(LIBFT_NAME))

HEADER		=	$(addprefix $(HEADER_PATH)/, $(HEADER_NAME))

LIBMLX_LINUX	=	$(addprefix $(MLX_LINUX_PATH)/, $(LIBMLX_NAME))

all: $(NAME)

$(NAME): $(LIB_PATH) $(LIBFT_SRC) $(LIBFT) $(OBJ_PATH) $(OBJ) $(LIBMLX_LINUX)
	@$(CC) -I$(HEADER_PATH)/ -o $(NAME) $(OBJ) $(LIBFT) $(LIBMLX_LINUX) $(LFLAGS)
	@echo "$<		[$(C_GREEN)OK$(C_END)]"

$(OBJ): $(OBJ_PATH)%.o: %.c $(HEADER)
	@$(CC) -I$(HEADER_PATH)/ $(CFLAGS) $< -o $@

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(LIBFT):
	@$(CP) $(LIBFT_SRC) $(LIB_PATH)

$(LIBFT_SRC):
	@(cd $(LIBFT_PATH) && $(MAKE))

$(LIB_PATH):
	@mkdir $(LIB_PATH)

$(LIBMLX_LINUX):
	@(cd $(MLX_LINUX_PATH) && $(MAKE))


# add mlx_linux dans clean et fclean
clean:
	@$(RM) $(OBJ_PATH)
	@(cd $(LIBFT_PATH) && $(MAKE) clean)
	@(cd $(MLX_LINUX_PATH) && $(MAKE) clean)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIB_PATH)
	@(cd $(LIBFT_PATH) && $(MAKE) fclean)

re: fclean all
