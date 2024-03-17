/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:25:55 by isbraz-d          #+#    #+#             */
/*   Updated: 2024/03/17 15:16:22 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	raycast(t_game *game)
{
	int		c;

	for (int x = 0; x < WIN_WIDTH; x++)
	{
		double cameraX = 2 * x / (double)WIN_HEIGHT - 1;
		double raydirY = game->player.delta[Y] + game->player.plane[Y] * cameraX;
		double raydirX = game->player.delta[X] + game->player.plane[X] * cameraX;
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
		{
			hit = 1;
			// Determine the texture to use based on the direction of the wall hit
     	   if (side == 0) // NS wall hit
        	{
            	if (raydirX > 0)
            		c = 0; // North
           		else
            		c = 1; // South
        	}
        	else // EW wall hit
        	{
            	if (raydirY > 0)
             		c = 2; // East
           		else
            		c = 3; // West
       		}
		} 	
      }

		//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
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
			
		double wallX; //where exactly the wall was hit
		if (side == 0)
			wallX = game->player.position[Y] + perpWallDist * raydirY;
		else
			wallX = game->player.position[X] + perpWallDist * raydirX;
		wallX -= floor((wallX));
		int texX = (int)(wallX * (double)(game->wall_textures[c].width));
		if(side == 0 && raydirX > 0)
			texX = game->wall_textures[0].width - texX - 1;
		if(side == 1 && raydirY < 0)
			texX = game->wall_textures[0].width - texX - 1;
		for (int y = drawStart; y < drawEnd; y++)
		{
			int d = y * 256 - WIN_HEIGHT * 128 + lineHeight * 128; //256 and 128 factors to avoid floats
			int texY = ((d * game->wall_textures->height) / lineHeight) / 256;
			if (texY <= -1 || texX <= -1)
				return ;
				int color = get_pixel_canva(&game->wall_textures[c], texX, texY);
			if (side == 1)
				color = (color >> 1) & 8355711;
			put_pixel_canva(&game->scene, x, y, color);
		}
	}
}
