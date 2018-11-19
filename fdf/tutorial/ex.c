#include <mlx.h>










int main()
{
	void *mlx = mlx_init();  // initialize mlx
	void* win = mlx_new_window (mlx, 800, 800, "L" ); // 


	mlx_pixel_put(mlx,win, 400, 400,0xff00ef);
	mlx_loop(mlx);
	return 0;
}
