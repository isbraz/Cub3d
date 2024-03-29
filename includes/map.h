/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:50:07 by user              #+#    #+#             */
/*   Updated: 2024/03/29 15:30:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define ARGUMENTS_ERROR 400
# define OPENING_ERROR 401
# define BREAKS_ERROR 402
# define SPAWN_ERROR 403
# define TYPES_ERROR 404
# define WALL_ERROR 405

# define INVALID_TYPE 6
# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define F 4
# define C 5

typedef struct s_map {
	char		*types_info[6];
	int			ceiling_color;
	int			floor_color;
	char		**types;
	char		*input;
	char		**map;
	int			map_start;
	char		spawn_dir;
	double		spawn_pos[2];
}	t_map;

void	exit_parsing_error(t_map *map, int status);
void	get_map(t_map *map, char *argv[]);
void	verify_map(t_map *map);
void	free_map(t_map *map);
int		verify_breaks(t_map *map);
int		verify_walls(t_map *map);
int		get_types(t_map *map);
int		get_spawn(t_map *map);

#endif