/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:08:52 by user              #+#    #+#             */
/*   Updated: 2024/03/29 11:24:46 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	get_pixel(t_image *image, int x, int y)
{
	return (*(unsigned int *)(image->addr + (y * image->line_length + x
			* (image->bits_per_pixel / 8))));
}
