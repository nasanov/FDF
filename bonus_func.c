/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasanov <nasanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 19:33:58 by nasanov           #+#    #+#             */
/*   Updated: 2020/02/21 19:37:53 by nasanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection(t_coord *a, t_coord *b)
{
	a->x = (a->x - a->y) * cos(0.7);
	a->y = (a->x + a->y) * sin(0.7) - a->z;
	b->x = (b->x - b->y) * cos(0.7);
	b->y = (b->x + b->y) * sin(0.7) - b->z;
}

void	shifting(t_coord *a, t_coord *b, t_fdf *data)
{
	a->x += data->shift_x;
	a->y += data->shift_y;
	b->x += data->shift_x;
	b->y += data->shift_y;
}

void	change_alt(t_coord *a, t_coord *b, t_fdf *data)
{
	a->z *= data->altitude;
	b->z *= data->altitude;
	data->color = (a->z || b->z) ?
	(data->alt_color + a->z * 3) : 0x663399;
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

void	draw_background(t_fdf *data)
{
	int		height;
	int		width;
	void	*img_ptr;

	height = 1000;
	width = 1000;
	img_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
	data->background_name, &width, &height);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img_ptr, 0, 0);
}
