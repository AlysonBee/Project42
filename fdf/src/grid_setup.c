







#include "fdf.h"

static size_t		y_distance_compute(t_fdf **wireframe)
{
	size_t	y;

	y = 0;
	while (wireframe[y])
		y++;
	return (y);
}

static size_t		x_distance_compute(t_fdf **wireframe)
{
	size_t	x;

	x = 0;
	while (wireframe[0][x].w == 1)
		x++;
	return (x);
}

t_grid		grid_setup(t_fdf **wireframe)
{
	t_grid 	grid;
	size_t	default_size;

	default_size = 800;
	grid.dist_x = x_distance_compute(wireframe);
	grid.dist_y = y_distance_compute(wireframe);
	if (grid.dist_y % 2 != 0)
		grid.dist_y++;
	if (grid.dist_x % 2 != 0)
		grid.dist_x++;
	/* replaced the hardcoded 800 with default size */
	grid.x_distance = (800 / grid.dist_x);
	grid.y_distance = (800 / grid.dist_y);
	grid.x_pixel_start = 400 - (grid.dist_x / 2) * grid.x_distance;
	grid.y_pixel_start = 400 - (grid.dist_y / 2) * grid.y_distance;
	return (grid);
}



