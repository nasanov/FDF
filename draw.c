#include "fdf.h"

void	projection(t_coord *a, t_coord *b)
{
	a->x = (a->x - a->y) * cos(0.8);
	a->y = (a->x + a->y) * sin(0.8) - a->z;
	b->x = (b->x - b->y) * cos(0.8);
	b->y = (b->x + b->y) * sin(0.8) - b->z;
	// *x = (*x - *y) * cos(0.2);
	// *y = (*y + *y) - z;
}

void shifting(t_coord *a, t_coord *b, t_fdf *data)
{
	a->x += data->shift_x;
	a->y += data->shift_y;
	b->x += data->shift_x;
	b->y += data->shift_y;
}

// ! bonus + fifth change color on changing alt
void	change_alt(t_coord *a, t_coord *b, t_fdf *data)
{
	a->z *= data->altitude;
	b->z *= data->altitude;
	data->color = (a->z || b->z) ? (data->alt_color + a->z * 3) : 0x663399;
}

void	zooming(t_coord *a, t_coord *b, t_fdf *data)
{
	a->x *= data->zoom;
	a->y *= data->zoom;
	b->x *= data->zoom;
	b->y *= data->zoom;
	if (data->is3d)
	{
		projection(a, b);
	}
}

void	bresenham(t_coord a, t_coord b, t_fdf *data)
{
	float 	x_step;
	float 	y_step;
	int		maxx;

	a.z = data->z_matrix[(int)a.y][(int)a.x];
	b.z = data->z_matrix[(int)b.y][(int)b.x];	
	change_alt(&a, &b, data);
	zooming(&a, &b, data);
	shifting(&a, &b, data);
	x_step = b.x - a.x;
	y_step = b.y - a.y;
	maxx = max(mod(x_step), mod(y_step));
	x_step /= maxx;
	y_step /= maxx;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(data->mlx_ptr,  data->win_ptr,
		a.x, a.y, data->color);
		a.x += x_step;
		a.y += y_step;
	}
}

void    print_menu(t_fdf *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 5, data->menu_color, "use arrow buttons to move picture");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 25, data->menu_color, "use +, - to zoom picture");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 45, data->menu_color, "use 'space' to change projection (3D to 2D)");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 65, data->menu_color, "use 1, 2, 3, 4 to change color");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 85, data->menu_color, "use [], ] to change altitude");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 105, data->menu_color, "use <, > to change background");
}

void	drawBackground(t_fdf *data)
{
    int height = 1000;
    int width = 1000;
	void *img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, data->background_name, &width, &height);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img_ptr, 0, 0);
}

void	draw(t_fdf *data)
{
	t_coord	a;
	t_coord	b;
	initialize_coords(&a, &b);
	drawBackground(data);	
	print_menu(data);
	a.y = 0;
	while (a.y < data->height)
	{
		a.x = 0;
		while (a.x < data->width)
		{
			if (a.x < data->width - 1)
			{
				b.x = a.x + 1;
				b.y = a.y;
				bresenham(a, b, data);
			}
			if (a.y < data->height - 1)
			{
				b.x = a.x;
				b.y = a.y + 1;
				bresenham(a, b, data);
			}
			a.x++;
		}
		a.y++;
	}
}