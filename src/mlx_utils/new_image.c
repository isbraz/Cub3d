/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:46:21 by llopes-d          #+#    #+#             */
/*   Updated: 2024/03/29 15:30:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#include <unistd.h>

void	new_image(t_game *game, t_image *image, char *path)
{
	image->id = mlx_xpm_file_to_image(\
		game->mlx, \
		path, \
		&image->width, \
		&image->height \
	);
	if (!image->id)
	{
		write(1, "Error\nxpm error.\n", 18);
		ft_close(game);
	}
	image->addr = mlx_get_data_addr(\
		image->id, \
		&image->bits_per_pixel, \
		&image->line_length, \
		&image->endian \
	);
}
