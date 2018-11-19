

#include "fdf.h"

/*
**  DEBUG ****************************
*/ 

void			print_value(t_fdf **grid)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j].w == 1)
		{
			DEBUG("%1.lf %1.lf %1.lf %1.lf ", grid[i][j].x,
				grid[i][j].y, grid[i][j].z, grid[i][j].w);
			j++;
		}
		DEBUG("\n");
		i++;
	}
}

/**************************************/

t_fdf			*assign_row(char **values, int y)
{
	t_fdf		*wireframe_row;
	size_t		x;

	wireframe_row = (t_fdf *)malloc(sizeof(t_fdf) * 
			(arraylen(values) + 1));
	x = 0;
	while (values[x])
	{
		wireframe_row[x].x = (double)x;
		wireframe_row[x].y = (double)y;
		wireframe_row[x].z = (double)atoi(values[x]);
		DEBUG("z is %f\n", wireframe_row[x].z);
		wireframe_row[x].w = (double)1;
		x++;
	}
	return (wireframe_row);
}

t_fdf			**assign_wireframe_values(char **file)
{
	t_fdf		**wireframe_coordinates;
	size_t		array_length;
	size_t		i;
	char		**tmp;

	array_length = arraylen(file);
	wireframe_coordinates = (t_fdf **)malloc(sizeof(t_fdf *) * 
		(array_length + 1));
	wireframe_coordinates[array_length] = NULL;
	printf("here\n");
	i = 0;
	while (file[i])
	{
		tmp = split(file[i], ' ');
		wireframe_coordinates[i] = assign_row(tmp, i);
		free2d(tmp);
		i++;
	}
	free2d(file);
	return (wireframe_coordinates);
}

t_fdf			**convert_wireframe_to_fdf(char *filename)
{
	char	**content;
	t_fdf	**grid;

	content = read_wireframe(filename);
	grid = assign_wireframe_values(content);
	return (grid);
}


