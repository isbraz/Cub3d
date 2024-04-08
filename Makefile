INC_DIR = includes

SRCS = src/main.c                     \
		src/utils/ft_strjoin.c        \
		src/utils/ft_strlen.c         \
		src/utils/ft_split.c          \
		src/utils/ft_nsplit.c         \
		src/utils/ft_strdup.c         \
		src/utils/free_double.c       \
		src/utils/ft_isnumeric.c      \
		src/utils/ft_atoi.c           \
		src/utils/is_floor.c          \
		src/utils/get_degree.c        \
		src/utils/get_radian.c        \
		src/utils/ft_memset.c         \
		src/utils/ft_strcmp.c         \
		src/utils/ft_cntchr.c         \
		src/utils/time_now.c          \
		src/map/exit_parsing_error.c  \
		src/map/free_map.c            \
		src/map/verify_breaks.c       \
		src/map/verify_walls.c        \
		src/map/verify_map.c          \
		src/map/get_types.c           \
		src/map/get_spawn.c           \
		src/map/get_map.c             \


OBJS = $(patsubst src/%,.objs/%,$(patsubst %.c,%.o,$(SRCS)))

NAME = cub3D
NAME_MAP1 = cub3D maps/explore.cub

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "cub3D compiled!"

.objs/%.o: src/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	@rm -rf .objs

fclean: clean
	@rm -rf $(NAME)

v: $(NAME)
	@valgrind --leak-check=full ./$(NAME_MAP1)

re: fclean all

.PHONY: all clean fclean re