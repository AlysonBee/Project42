
#include <mlx.h>
#include "fdf.h"

static void		direction_bias(int *pixel_x, int *pixel_y, int *error, t_equ e)
{
	int		tmp_error;

	tmp_error = *error;
	if (tmp_error > -e.dx)
	{
		*error = *error - e.dy;
		*pixel_x = *pixel_x + e.sx;
	}
	if (tmp_error < e.dy)
	{
		*error = *error + e.dx;
		*pixel_y = *pixel_y + e.sy;
	}
}

static void		draw_pixel(t_fdf **wireframe, int x, int y, t_mlx *mlx)
{
	t_equ	e;
	int		error;
	int		tmp_err;
	int		x1;
	int		y1;

	x1 = wireframe[y + mlx->push_y][x + mlx->push_x].pixel_x;
	y1 = wireframe[y + mlx->push_y][x + mlx->push_x].pixel_y;
	e.dx = abs(x1 - wireframe[y][x].pixel_x);
	e.dy = abs(y1 - wireframe[y][x].pixel_y);
	e.sx = wireframe[y][x].pixel_x < x1 ? 1 : -1;
	e.sy = wireframe[y][x].pixel_y < y1 ? 1 : -1;
	error = (e.dx > e.dy ? e.dx : -e.dy) / 2;
	while (42)
	{
		mlx_pixel_put(mlx->mlx, mlx->window, wireframe[y][x].pixel_x, 
			wireframe[y][x].pixel_y, 0x00ff00);
		if (wireframe[y][x].pixel_x == x1 && wireframe[y][x].pixel_y == y1)
			break ;
		tmp_err = error;
		direction_bias(&wireframe[y][x].pixel_x, 
		&wireframe[y][x].pixel_y, &error, e);
	}
}

void		draw_line(t_fdf **wireframe, char *filename)
{
	int		x;
	int		y;
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, 2400, 2400, filename);
	y = 0;
	while (wireframe[y + 2])
	{
		x = 0;
		while (wireframe[y][x + 1].w == 1)
		{
			mlx.push_x = 1;
			mlx.push_y = 0;
			draw_pixel(wireframe, x, y, &mlx);
			mlx.push_x = 0;
			mlx.push_y = 1;
			draw_pixel(wireframe, x, y, &mlx);
			x++;
		}
		y++;
	}
	mlx_loop(mlx.mlx);
}
