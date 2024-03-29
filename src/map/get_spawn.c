/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spawn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>           +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 08:39:15 by user              #+#    #+#             */
/*   Updated: 2024/03/29 15:30:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	valid_char(char c)
{
	if (c == ' ' || c == '1' || c == '0' || c == '2')
		return (1);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (2);
	return (0);
}

int	get_spawn(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (map->map[++y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (!valid_char(map->map[y][x]))
				return (0);
			if (valid_char(map->map[y][x]) == 2 && map->spawn_dir)
				return (0);
			if (valid_char(map->map[y][x]) == 2)
			{
				map->spawn_dir = map->map[y][x];
				map->spawn_pos[X] = x + 0.5;
				map->spawn_pos[Y] = y + 0.5;
			}
			x++;
		}
	}
	if (!map->spawn_dir)
		return (0);
	return (1);
}
