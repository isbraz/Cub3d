/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>           +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 08:06:12 by user              #+#    #+#             */
/*   Updated: 2024/03/29 15:30:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <utils.h>
#include <map.h>

void	free_map(t_map *map)
{
	int	index;

	index = 0;
	if (!map)
		return ;
	if (map->input)
		free(map->input);
	if (map->map)
		free_double(map->map);
	if (map->types)
		free_double(map->types);
	while (index < 6)
	{
		if (map->types_info[index])
			free(map->types_info[index]);
		index++;
	}
}
