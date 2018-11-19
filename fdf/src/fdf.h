

#ifndef FDF_H
# define FDF_H
# include "../inc/lib.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

/*
** Making it explicitly clear that printf is used only
** for debugging purposes.
*/

# define DEBUG printf

typedef struct	s_line_equ
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
}				t_equ;

/*
** Info pertaining to each pixel point between lines.
*/

typedef struct	s_fdf
{
	double			x;
	double			y;
	double			z;
	double			w;
	int			pixel_x;
	int			pixel_y;
}				t_fdf;

/*
** Information needed to calculate grid plotting.
*/

typedef struct	s_grid_info
{
	size_t		x_distance;
	size_t		y_distance;
	size_t		x_pixel_start;
	size_t		y_pixel_start;
	size_t		dist_x;
	size_t		dist_y;
}				t_grid;

t_grid			grid_setup(t_fdf **wireframe);


/*
** MLX variables
*/

typedef struct	s_mlx
{
	void		*mlx;
	void		*window;
	int			push_x;
	int			push_y;
}				t_mlx;


/*
** convert the .fdf file into grid-readable info
*/

t_fdf			**assign_wireframe_value(char **file);

/*
** read the content of the file and turn it into a 
** 2d char array to be furhter processed by 
** assign_wireframe_value
*/

char			**read_wireframe(char *filename);

/*
** Main converstion function containing both
** assign_wireframe_value and read_wireframe
*/

t_fdf			**convert_wireframe_to_fdf(char *filename);

/*
** Main funciton used for creating the grid. This one
** was used for testing and needs cleaning.
*/

void			ft_wireframe(t_fdf **wireframe, char *filename);

/*
** Plot the coordinates of each pixel point.
*/

t_fdf		 	**plot_coordinates(t_fdf **wireframe, t_grid grid);

/*
** Line drawing function that's a lot harder than it 
** should be.
*/

void			draw_line(t_fdf **wireframe, char *filename);

#endif
