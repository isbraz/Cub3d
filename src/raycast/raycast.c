/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:25:55 by isbraz-d          #+#    #+#             */
/*   Updated: 2024/03/20 14:40:38 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	init_calc(t_game *game, double cameraX)
{
	game->raycast.raydirY = game->player.delta[Y] + game->player.plane[Y] * cameraX;
	game->raycast.raydirX = game->player.delta[X] + game->player.plane[X] * cameraX;
	game->raycast.mapX = (int)game->player.position[X];
	game->raycast.mapY = (int)game->player.position[Y];
	game->raycast.deltaDistX = fabs(1 / game->raycast.raydirX);
	game->raycast.deltaDistY = fabs(1 / game->raycast.raydirY);
}

static void	draw_3Dwalls(t_game *game, int draw_start, int draw_end, int texX, int x)
{
	int d;
	int	texY;
	int	color;

	while (draw_start < draw_end)
	{
		d = draw_start * 256 - WIN_HEIGHT * 128 + game->raycast.lineHeight * 128;
		texY = ((d * game->wall_textures->height) / game->raycast.lineHeight) / 256;
		if (texY <= -1 || texX <= -1)
			return ;
		color = get_pixel_canva(&game->wall_textures[game->raycast.c], texX, texY);
		if (game->raycast.side == 1)
			color = (color >> 1) & 8355711;
		put_pixel_canva(&game->scene, x, draw_start, color);
		draw_start++;
	}
}

static void	set_texture(t_game *game)
{
	if (game->raycast.side == 0) // EW wall hit
    {
        if (game->raycast.raydirX > 0)
            game->raycast.c = WE; // West wall1
        else
            game->raycast.c = EA; // East wall2
    }
    else // NS wall hit
    {
        if (game->raycast.raydirY > 0)
            game->raycast.c = NO; // North wall3
        else
            game->raycast.c = SO; // South wall4
    }
}

static double	get_distance(t_game *game)
{
	double	perpWallDist;

	if(game->raycast.side == 0)
		perpWallDist = (game->raycast.sideDistX - game->raycast.deltaDistX);
	else
		perpWallDist = (game->raycast.sideDistY - game->raycast.deltaDistY);
	return (perpWallDist);
}

static double	perform_dda(t_game *game)
{
	game->raycast.hit = 0;	
	while (game->raycast.hit == 0)
	{
		if (game->raycast.sideDistX < game->raycast.sideDistY)
		{
			game->raycast.sideDistX += game->raycast.deltaDistX;
			game->raycast.mapX += game->raycast.stepX;
			game->raycast.side = 0;
		}
		else
		{
			game->raycast.sideDistY += game->raycast.deltaDistY;
			game->raycast.mapY += game->raycast.stepY;
			game->raycast.side = 1;
		}
		if (game->map.map[game->raycast.mapY][game->raycast.mapX] == '1')
		{
			game->raycast.hit = 1;
			set_texture(game);
		}
	}
	return (get_distance(game));
}

static void	do_steps(t_game *game)
{
	if (game->raycast.raydirX < 0)
	{
		game->raycast.stepX = -1;
		game->raycast.sideDistX = (game->player.position[X] - game->raycast.mapX) * game->raycast.deltaDistX;
	}
	else
	{
		game->raycast.stepX = 1;
		game->raycast.sideDistX = (game->raycast.mapX + 1.0 - game->player.position[X]) * game->raycast.deltaDistX;
	}
	if (game->raycast.raydirY < 0)
	{
		game->raycast.stepY = -1;
		game->raycast.sideDistY = (game->player.position[Y] - game->raycast.mapY) * game->raycast.deltaDistY;
	}
	else
	{
		game->raycast.stepY = 1;
		game->raycast.sideDistY = (game->raycast.mapY + 1.0 - game->player.position[Y]) * game->raycast.deltaDistY;
	}
}

void	create_walls(t_game *game, int x)
{
	int		drawStart;
	int		drawEnd;
	double	perpWallDist;
	double	wallX;
	int		texX;

	perpWallDist = perform_dda(game);
	game->raycast.lineHeight = (int)(WIN_HEIGHT / perpWallDist);
	drawStart = -game->raycast.lineHeight / 2 + WIN_HEIGHT / 2;
	if(drawStart < 0)
		drawStart = 0;
	drawEnd = game->raycast.lineHeight / 2 + WIN_HEIGHT / 2;
	if(drawEnd > WIN_HEIGHT)
		drawEnd = WIN_HEIGHT - 1;
	if (game->raycast.side == 0)
		wallX = game->player.position[Y] + perpWallDist * game->raycast.raydirY;
	else
		wallX = game->player.position[X] + perpWallDist * game->raycast.raydirX;
	wallX -= floor((wallX));
	texX = (int)(wallX * (double)(game->wall_textures[game->raycast.c].width));
	if(game->raycast.side == 0 && game->raycast.raydirX > 0)
		texX = game->wall_textures[0].width - texX - 1;
	if(game->raycast.side == 1 && game->raycast.raydirY < 0)
		texX = game->wall_textures[0].width - texX - 1;
	draw_3Dwalls(game, drawStart, drawEnd,texX, x);
}

void	raycast(t_game *game)
{
	int		x;
	double	cameraX;

	x = 0;
	while (x < WIN_WIDTH)
	{
		cameraX = 2 * x / (double)WIN_HEIGHT - 1;
		init_calc(game, cameraX);
		do_steps(game);
    	create_walls(game, x);
		x++;
	}
}
