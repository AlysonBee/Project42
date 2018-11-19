

#include "fdf.h"

int				main(int argc, char **argv)
{
	t_fdf		**grid;
	t_grid		values;

	if (argc != 2)
	{
		DEBUG("Usage : ./ft_wireframe [file.fdf]\n");
		exit(1);
	}
	grid = convert_wireframe_to_fdf(argv[1]);
	values = grid_setup(grid);
	grid = plot_coordinates(grid, values);
	draw_line(grid, argv[1]); 
	return (0);
}
