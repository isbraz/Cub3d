/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_canvas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:19:20 by user              #+#    #+#             */
/*   Updated: 2024/03/29 15:30:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	new_canvas(t_image *canvas, void *mlx, int height, int width)
{
	canvas->id = mlx_new_image(mlx, width, height);
	canvas->addr = mlx_get_data_addr(canvas->id,
			&canvas->bits_per_pixel, &canvas->line_length,
			&canvas->endian);
}
