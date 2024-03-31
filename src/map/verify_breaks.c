/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_breaks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:23:36 by user              #+#    #+#             */
/*   Updated: 2024/03/31 14:22:45 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	verify_breaks(t_map *map)
{
	int	index;

	index = map->map_start -1;
	if (index <= 0)
		return (0);
	while (map->input[++index])
		if (map->input[index] == '\n' && map->input[index + 1] == '\n')
			return (0);
	return (1);
}
