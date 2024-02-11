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
		src/map/get_types.c        \
		src/map/get_spawn.c        \

OBJS = $(patsubst %.c,.objs/%.o,$(notdir $(SRCS)))

NAME = cub3D

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJS): 
	mkdir -p .objs
	cd .objs && $(CC) -c $(patsubst %,../%,$(SRCS))

clean:
	rm -rf .objs

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re