/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_vec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:10:48 by llopes-d          #+#    #+#             */
/*   Updated: 2024/03/15 14:10:48 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	rotate_vector(double vec[2], double dest[2], double degree)
{
	dest[X] = vec[X] * cos(degree * PI / 180) - vec[Y] * sin(degree * PI / 180);
	dest[Y] = vec[X] * sin(degree * PI / 180) + vec[Y] * cos(degree * PI / 180);
}
