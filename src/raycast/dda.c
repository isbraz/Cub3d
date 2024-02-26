#include <cub3d.h>

double	cast_ray(t_map map, double pos_x, double pos_y, double angle)
{
	// Step size for x and y directions
    double step_x = cos(angle);
    double step_y = sin(angle);
    
    // Initialize ray position
    double ray_x = pos_x;
    double ray_y = pos_y;

	//Perform DDA
	while (1)
	{
		if (map.map[(int)ray_y, (int)ray_x] == '1')
		{
			double distance = sqrt(pow(ray_x - pos_x, 2) + pow(ray_y - pos_y, 2));
			return (distance);
		}
		ray_x += step_x;
		ray_y += step_y;
	}
	return (0);
}
