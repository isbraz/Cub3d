/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:49:26 by user              #+#    #+#             */
/*   Updated: 2024/04/02 13:24:18 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#include <utils.h>

static int	is_open(char **map, int x, int y)
{
	if ((!x || map[y][x - 1] == ' ') ||
		(!map[y][x + 1] || map[y][x + 1] == ' ') ||
		(!y || ft_strlen(map[y - 1]) < x + 1 || map[y - 1][x] == ' ') ||
		(!map[y + 1] || ft_strlen(map[y + 1]) < x + 1 || map[y + 1][x] == ' '))
		return (1);
	return (0);
}

static int	door_closed(char **map, int x, int y)
{
	int	sides_closed;

	sides_closed = 0;
	if (map[y][x - 1] == '2' || map[y][x + 1] == '2' || \
			map[y - 1][x] == '2' || map[y + 1][x] == '2')
		return (0);
	if (map[y][x - 1] == '1')
		sides_closed++;
	if (map[y][x + 1] == '1')
		sides_closed++;
	if (map[y - 1][x] == '1')
		sides_closed++;
	if (map[y + 1][x] == '1')
		sides_closed++;
	return (sides_closed);
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
			if (is_floor(map->map[y][x]) && is_open(map->map, x, y))
				return (0);
			if (map->map[y][x] == '2' && door_closed(map->map, x, y) < 2)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
