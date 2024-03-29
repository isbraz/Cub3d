/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_breaks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:23:36 by user              #+#    #+#             */
/*   Updated: 2024/03/29 15:30:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	is_line_empty(char *line)
{
	int	index;

	index = 0;
	while (line[index] && line[index] != '\n')
	{
		if (line[index] != ' ')
			return (0);
		index++;
	}
	return (1);
}

int	verify_breaks(t_map *map)
{
	int	index;

	index = map->map_start -1;
	if (index <= 0)
		return (0);
	while (map->input[++index])
		if (map->input[index] == '\n' && is_line_empty(&map->input[index + 1]))
			return (0);
	return (1);
}
