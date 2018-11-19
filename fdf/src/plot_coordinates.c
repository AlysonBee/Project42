
#include "fdf.h"


t_fdf		**plot_coordinates(t_fdf **wireframe,
	t_grid grid)
{
	size_t		temp_x_pix;
	size_t		temp_y_pix;
	int			x;
	int			y;

	y = 0;
	temp_y_pix = grid.y_pixel_start;
	while (wireframe[y])
	{
		x = 0;
		temp_x_pix = grid.x_pixel_start;
		while (wireframe[y][x].w == 1)
		{
			if (wireframe[y][x].z > 0)
			{
				wireframe[y][x].pixel_x = temp_x_pix;
				wireframe[y][x].pixel_y = temp_y_pix -
					wireframe[y][x].z * 10;
			}
			else
			{
				wireframe[y][x].pixel_x = temp_x_pix;
				wireframe[y][x].pixel_y = temp_y_pix;
			}
			x++;
			temp_x_pix += grid.x_distance;
		}
		y++;
		temp_y_pix += grid.y_distance;
	}
	return (wireframe);
}
