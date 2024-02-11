/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:58:26 by user              #+#    #+#             */
/*   Updated: 2024/02/11 16:39:28 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	is_types_complete(t_map *map)
{
	int	index;

	index = 0;
	while (index < 6)
	{
		if (!map->types_info[index])
			return (0);
		index++;
	}
	return (1);
}

static int	valid_type(char *word)
{
	if (!strcmp(word, "NO"))
		return (NO);
	if (!strcmp(word, "SO"))
		return (SO);
	if (!strcmp(word, "WE"))
		return (WE);
	if (!strcmp(word, "EA"))
		return (EA);
	if (!strcmp(word, "F"))
		return (F);
	if (!strcmp(word, "C"))
		return (C);
	return (INVALID_TYPE);
}

int	get_types(t_map *map)
{
	int		index;
	int		j;
	char	**line;

	j = 0;
	while (j < 6)
	{
		index = 0;
		while (map->types[index])
		{
			line = ft_split(map->types[index], ' ');
			if (!line || !line[1] || line[2])
				return (free_double(line), 0);
			if (valid_type(line[0]) == INVALID_TYPE)
				return (free_double(line), 0);
			if (valid_type(line[0]) == j && map->types_info[j])
				return (free_double(line), 0);
			if (valid_type(line[0]) == j)
				map->types_info[j] = ft_strdup(line[1]);
			free_double(line);
			index++;
		}
		j++;
	}
	return (is_types_complete(map));
}
