/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:03:02 by user              #+#    #+#             */
/*   Updated: 2024/03/29 12:48:32 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "cub3D.h"

typedef struct s_game	t_game;

typedef struct s_image
{
	void		*id;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}	t_image;

void	new_canvas(t_image *canvas, void *mlx, int height, int width);
void	new_image(t_game *game, t_image *image, char *path);
void	put_pixel(t_image *image, int x, int y, int pixel);
int		mouse_listener(int x, int y, t_game *game);
int		get_pixel(t_image *image, int x, int y);
int		get_trgb(int t, int r, int g, int b);
int		key_listener(int key, t_game *game);
int		ft_close(t_game *game);
int		ft_loop(t_game *game);

#endif