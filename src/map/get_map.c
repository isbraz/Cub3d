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
#include <fcntl.h>
#include <map.h>

// static int	is_map_start(char *input)
// {
// 	int	index;

// 	index = 0;
// 	while (input[index] && input[index] == ' ')
// 		index++;
// 	if (input[index] == '1' || input[index] == '0')
// 		return (1);
// 	return (0);
// }

static int	is_map_start(char *input)
{
	int	index;

	index = 0;
	while (input[index] && (input[index] == ' ' || input[index] == '\n'))
	{
		if (input[index + 1] == '1' || input[index + 1] == '0')
			return (1);
		index++;
	}
	return (0);
}

static int	get_map_start(char *input)
{
	int		index;

	index = 0;
	if (input[index])
		index++;
	while (input[index])
	{
		if (input[index - 1] == '\n' && is_map_start(&input[index]))
			break ;
		index++;
	}
	return (index);
}

static int	valid_extension(char *path)
{
	int	path_len;

	path_len = ft_strlen(path);
	if (path_len < 5 || ft_strcmp(&path[path_len - 4], ".cub"))
		return (0);
	return (1);
}

static char	*get_file(char *argv[])
{
	char	buffer[2];
	char	*input;
	int		fd;

	input = NULL;
	buffer[1] = '\0';
	if (!valid_extension(argv[1]))
		return (NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (read(fd, buffer, 1) > 0)
	{
		if (buffer[0] == '\t')
		{
			if (input)
				free(input);
			close(fd);
			return (NULL);
		}
		input = ft_strjoin(input, buffer);
	}
	close(fd);
	return (input);
}

void	get_map(t_map *map, char *argv[])
{
	map->input = get_file(argv);
	if (!map->input)
		exit_parsing_error(map, OPENING_ERROR);
	map->map_start = get_map_start(map->input);
	map->map = ft_split(&map->input[map->map_start], '\n');
	map->types = ft_nsplit(map->input, '\n', map->map_start);
	verify_map(map);
}
