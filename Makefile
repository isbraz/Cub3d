INC_DIR = includes
MLX_DIR = .mlx
CFLAGS = -g  -fsanitize=address #-Wall -Wextra -Werror

SRCS = src/main.c                     \
		src/utils/ft_strjoin.c        \
		src/utils/ft_strlen.c         \
		src/utils/ft_split.c          \
		src/utils/ft_nsplit.c         \
		src/utils/ft_strdup.c         \
		src/utils/free_double.c       \
		src/utils/exit_error.c        \
		src/utils/ft_isnumeric.c      \
		src/utils/ft_atoi.c           \
		src/utils/is_floor.c          \
		src/mlx_utils/new_canvas.c    \
		src/mlx_utils/get_pixel.c     \
		src/mlx_utils/put_pixel.c     \
		src/mlx_utils/get_trgb.c      \
		src/map/get_map.c             \
		src/map/verify_map.c          \
		src/map/verify_walls.c        \
		src/map/verify_breaks.c       \
		src/map/get_types.c           \
		src/map/get_spawn.c           \
		src/minimap/minimap.c         \
		src/minimap/draw_view_line.c  \
		src/scene/scene.c             \
		src/raycast/dda.c			  \
		src/scene/moves.c             \
		src/raycast/raycast.c         \

OBJS = $(patsubst src/%,.objs/%,$(patsubst %.c,%.o,$(SRCS)))

NAME = cub3D
NAME_MAP1 = cub3D testmap.cub

all: $(NAME)

$(NAME): $(OBJS)
	@cd .mlx && ./configure 2>&1 >/dev/null
	@echo "mlx compiled!"
	@$(CC) $(CFLAGS) $(OBJS) -L$(MLX_DIR) -lmlx -I$(MLX_DIR) -lXext -lX11 -lm -lz  -o $(NAME)
	@echo "cub3D compiled!"

.objs/%.o: src/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(MLX_DIR) -c $< -o $@

clean:
	@rm -rf .objs

fclean: clean
	@rm -f $(NAME)

v: $(NAME)
	@valgrind --leak-check=full ./$(NAME_MAP1)

re: fclean all

.PHONY: all clean fclean re