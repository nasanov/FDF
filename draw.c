/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasanov <nasanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 19:42:48 by nasanov           #+#    #+#             */
/*   Updated: 2020/02/21 20:10:27 by nasanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(t_fdf *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 5,
	data->menu_color, "use arrow buttons to move picture");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 25,
	data->menu_color, "use +, - to zoom picture");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 45,
	data->menu_color, "use 'space' to change projection (3D to 2D)");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 65,
	data->menu_color, "use 1, 2, 3, 4 to change color");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 85,
	data->menu_color, "use [, ] to change altitude");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 105,
	data->menu_color, "use <, > to change background");
}

void	draw_line(t_coord a, t_coord b, t_fdf *data)
{
	float	x_step;
	float	y_step;
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
		mlx_pixel_put(data->mlx_ptr, data->win_ptr,
		a.x, a.y, data->color);
		a.x += x_step;
		a.y += y_step;
	}
}

void	draw(t_fdf *data)
{
	t_coord	a;
	t_coord	b;

	draw_background(data);
	print_menu(data);
	a.y = -1;
	while (++a.y < data->height)
	{
		a.x = -1;
		while (++a.x < data->width)
		{
			if (a.x < data->width - 1)
			{
				b.x = a.x + 1;
				b.y = a.y;
				draw_line(a, b, data);
			}
			if (a.y < data->height - 1)
			{
				b.x = a.x;
				b.y = a.y + 1;
				draw_line(a, b, data);
			}
		}
	}
}
