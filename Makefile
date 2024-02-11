INC_DIR = includes
MLX_DIR = .mlx

SRCS = src/main.c                  \
		src/utils/ft_strjoin.c     \
		src/utils/ft_strlen.c      \
		src/utils/ft_split.c       \
		src/utils/ft_nsplit.c      \
		src/utils/ft_strdup.c      \
		src/utils/free_double.c    \
		src/utils/exit_error.c     \
		src/map/get_map.c          \
		src/map/verify_map.c       \
		src/map/verify_walls.c     \
		src/map/verify_breaks.c    \
		src/map/get_types.c        \
		src/map/get_spawn.c        \

OBJS = $(SRCS:%.c=%.o)
OBJS_FINAL = $(patsubst %.c,.objs/%.o,$(notdir $(SRCS)))

NAME = cub3D

all: $(NAME)

$(NAME): $(OBJS)
	cd .mlx && ./configure
	$(CC) $(OBJS_FINAL) -L$(MLX_DIR) -lmlx -I$(MLX_DIR) -lXext -lX11 -lm -lz  -o $(NAME)

%.o: %.c
	@mkdir -p .objs
	@$(CC) -Wall -Wextra -Werror -I$(INC_DIR) -I$(MLX_DIR) -c $< -o .objs/$(notdir $@)

clean:
	rm -rf $(OBJS_FINAL)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re