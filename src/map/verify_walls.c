/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:49:26 by user              #+#    #+#             */
/*   Updated: 2024/02/11 16:39:28 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	is_valid_char(char c)
{
	if (c == '0' ||
		c == 'N' ||
		c == 'S' ||
		c == 'E' ||
		c == 'W' )
		return (1);
	return (0);
}

static int	is_open(char **map, int x, int y)
{
	if ((!x || map[y][x - 1] == ' ') ||
		(!map[y][x + 1] || map[y][x + 1] == ' ') ||
		(!y || ft_strlen(map[y - 1]) < x || map[y - 1][x] == ' ') ||
		(!map[y + 1] || ft_strlen(map[y + 1]) < x || map[y + 1][x] == ' '))
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
			if (is_valid_char(map->map[y][x]))
				if (is_open(map->map, x, y))
					return (0);
			x++;
		}
		y++;
	}
	return (1);
}
