/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:49:26 by user              #+#    #+#             */
/*   Updated: 2024/03/07 15:00:32 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	is_open(char **map, int x, int y)
{
	if ((!x || map[y][x - 1] == ' ') ||
		(!map[y][x + 1] || map[y][x + 1] == ' ') ||
		(!y || ft_strlen(map[y - 1]) < x + 1 || map[y - 1][x] == ' ') ||
		(!map[y + 1] || ft_strlen(map[y + 1]) < x + 1 || map[y + 1][x] == ' '))
		return (1);
	return (0);
}

int	verify_walls(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (is_floor(map->map[y][x]))
				if (is_open(map->map, x, y))
					return (0);
			x++;
		}
		y++;
	}
	return (1);
}
