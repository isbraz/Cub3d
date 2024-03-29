/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:58:26 by user              #+#    #+#             */
/*   Updated: 2024/03/29 15:30:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#include <utils.h>

static int	get_color(char *color)
{
	char	**split;
	int		colors[3];
	int		index;

	index = 0;
	split = ft_split(color, ',');
	while (split[index])
	{
		if (!ft_isnumeric(split[index]))
			return (free_double(split), -1);
		colors[index] = ft_atoi(split[index]);
		if (colors[index] > 255 || colors[index] < 0)
			return (free_double(split), -1);
		index++;
	}
	free_double(split);
	if (index != 3)
		return (-1);
	return (get_trgb(0, colors[0], colors[1], colors[2]));
}

static int	is_types_correct(t_map *map)
{
	int	index;

	index = 0;
	while (index < 6)
	{
		if (!map->types_info[index])
			return (0);
		if (index == 4)
			map->floor_color = get_color(map->types_info[index]);
		if (index == 5)
			map->ceiling_color = get_color(map->types_info[index]);
		index++;
	}
	if (map->ceiling_color == -1 || map->floor_color == -1)
		return (0);
	return (1);
}

static int	valid_type(char *word)
{
	if (!ft_strcmp(word, "NO"))
		return (NO);
	if (!ft_strcmp(word, "SO"))
		return (SO);
	if (!ft_strcmp(word, "WE"))
		return (WE);
	if (!ft_strcmp(word, "EA"))
		return (EA);
	if (!ft_strcmp(word, "F"))
		return (F);
	if (!ft_strcmp(word, "C"))
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
	return (is_types_correct(map));
}
