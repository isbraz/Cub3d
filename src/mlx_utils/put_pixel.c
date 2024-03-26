/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:09:20 by user              #+#    #+#             */
/*   Updated: 2024/03/26 15:56:39 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	put_pixel_canva(t_image *image, int x, int y, int pixel)
{
	char	*dst;

	if (!pixel)
		return ;
	dst = image->addr + (y * image->line_length + x
			* (image->bits_per_pixel / 8));
	*(unsigned int *) dst = pixel;
}
