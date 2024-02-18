#ifndef CUB3D_H
# define CUB3D_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

#include <mlx.h>

#define WIN_WIDTH 1600
#define WIN_HEIGHT 900
#define MINIMAP_WIDTH 280
#define MINIMAP_HEIGHT 150
#define MINIMAP_MARGIN 20
#define MINIMAP_SCALE 10
#define MINIMAP_POSITIONY (WIN_HEIGHT - MINIMAP_HEIGHT - MINIMAP_MARGIN)
#define MINIMAP_POSITIONX (MINIMAP_MARGIN)

#define INVALID_TYPE 6
#define NO 0
#define SO 1
#define WE 2
#define EA 3
#define F 4
#define C 5

#define X 0
#define Y 1

#define ARGUMENTS_ERROR 400
#define OPENING_ERROR 401
#define BREAKS_ERROR 402
#define SPAWN_ERROR 403
#define TYPES_ERROR 404
#define WALL_ERROR 405

typedef struct s_image
{
	void	*id;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_player
{
	t_image	sprite;
	t_image	minimap_sprite;
	double	position[2];
}	t_player;

typedef struct s_map {
	char	*types_info[6];
	int		ceiling_color;
	int		floor_color;
	char	**types;
	char	*input;
	char	**map;
	int		map_start;
	char	spawn_dir;
	int		spawn_pos[2];
}	t_map;

typedef struct s_mlx {
	void	*window;
	void	*mlx;
}	t_mlx;

typedef struct s_game {
	t_mlx		mlx;
	t_map		map;
	t_image		scene;
	t_player	player;
}	t_game;

void	exit_error(t_map *map, int status);
int		ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char const *s1);
void	free_double(char **array);
char	**ft_split(char const *s, char c);
char	**ft_nsplit(char const *s, char c, size_t n);
int		ft_isnumeric(char *str);
int		ft_atoi(const char *str);
int		is_floor(char c);


int		get_trgb(int t, int r, int g, int b);
void	put_pixel_canva(t_image *image, int x, int y, int pixel);
int		get_pixel_canva(t_image *image, int x, int y);
void	new_canvas(t_image *canvas, void *mlx, int height, int width);


void	get_map(t_map *map, char *argv[]);
void	free_map(t_map *map);
void	verify_map(t_map *map);
int		verify_breaks(t_map *map);
int		verify_walls(t_map *map);
int		get_types(t_map *map);
int		get_spawn(t_map *map);

void	update_minimap(t_game *game);

void	update_scene(t_game *game);

#endif