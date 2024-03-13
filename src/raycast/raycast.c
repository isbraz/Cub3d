/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:25:55 by isbraz-d          #+#    #+#             */
/*   Updated: 2024/03/13 12:41:14 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void draw_line(t_game *game, int x0, int y0, int x1, int y1, int color) 
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    while (x0 != x1 || y0 != y1)
    { 
		// if (get_pixel_canva(&game->scene, x0, y0) != get_trgb(0, 230, 230, 230) && \
		// 	get_pixel_canva(&game->scene, x0, y0) != get_trgb(0, 255, 50, 50))
		// 	break;
		if (x0 > WIN_WIDTH || y0 > WIN_HEIGHT)
			break;
        put_pixel_canva(&game->scene, x0, y0, color);
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void	raycast(t_game *game)
{
	double	planeX = game->player.planeX;
	double	planeY = game->player.planeY;

	for (int x = 0; x < WIN_WIDTH; x++)
	{
		double cameraX = 2 * x / (double)WIN_WIDTH - 1;
		double raydirX = game->player.pdx + planeX * cameraX;
		double raydirY = game->player.pdy + planeY * cameraX;
		//which box of the map we're in
		int mapX = (int)game->player.position[X];
		int mapY = (int)game->player.position[Y];
		
		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;
		
		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / raydirX);
		double deltaDistY = fabs(1 / raydirY);
		double perpWallDist;
		
		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
    	int stepY;

    	int hit = 0; //was there a wall hit?
    	int side; //was a NS or a EW wall hit?
		      //calculate step and initial sideDist
      if (raydirX < 0)
      {
        stepX = -1;
        sideDistX = (game->player.position[X] - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - game->player.position[X]) * deltaDistX;
      }
      if (raydirY < 0)
      {
        stepY = -1;
        sideDistY = (game->player.position[Y] - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - game->player.position[Y]) * deltaDistY;
      }
      //perform DDA
      while (hit == 0)
      {
        //jump to next map square, either in x-direction, or in y-direction
        if (sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
		if (game->map.map[mapY][mapX] == '1') 
			hit = 1;
      }
	  
		//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!) ***
    	if(side == 0)
			perpWallDist = (sideDistX - deltaDistX);
    	else
			perpWallDist = (sideDistY - deltaDistY);
		
		//Calculate height of line to draw on screen
		int lineHeight = (int)(WIN_HEIGHT / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
      	if(drawStart < 0)
			drawStart = 0;
      	int drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
      	if(drawEnd > WIN_HEIGHT)
			drawEnd = WIN_HEIGHT - 1;
			
		draw_line(game, x, drawStart, x, drawEnd, get_trgb(0, 255, 0, 0));
	}
}