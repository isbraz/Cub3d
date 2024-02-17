/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_canvas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:19:20 by user              #+#    #+#             */
/*   Updated: 2024/02/16 16:21:52 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	new_canvas(t_image *canvas, void *mlx)
{
	canvas->id = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGTH);
	canvas->addr = mlx_get_data_addr(canvas->id,
			&canvas->bits_per_pixel, &canvas->line_length,
			&canvas->endian);
}
