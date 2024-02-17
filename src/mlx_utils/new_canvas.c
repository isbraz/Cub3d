/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_canvas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:19:20 by user              #+#    #+#             */
/*   Updated: 2024/02/17 16:14:40 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	new_canvas(t_image *canvas, void *mlx, int height, int width)
{
	canvas->id = mlx_new_image(mlx, width, height);
	canvas->addr = mlx_get_data_addr(canvas->id,
			&canvas->bits_per_pixel, &canvas->line_length,
			&canvas->endian);
}
