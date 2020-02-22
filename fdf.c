/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasanov <nasanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 19:45:47 by nasanov           #+#    #+#             */
/*   Updated: 2020/02/21 20:46:57 by nasanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_error(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}

int		deal_key(int key, t_fdf *data)
{
	printf("%d\n", key);
	if (key == 53)
		exit(0);
	key_background(key, data);
	key_shift(key, data);
	key_alt_iso(key, data);
	data->zoom += (key == 69) ? 10 : 0;
	if (key == 78)
		data->zoom -= (data->zoom > 0) ? 10 : 0;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

void	initialize_data(t_fdf *data)
{
	data->shift_x = 350;
	data->shift_y = 350;
	data->zoom = 40;
	data->altitude = 5;
	data->is3d = 1;
	data->color = 0x000000;
	data->alt_color = 0x10ADED;
	data->menu_color = 0x000000;
	data->background_name = "./w_background.xpm";
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "fils de fer");
}

void	initialize_coords(t_coord *a, t_coord *b)
{
	a->x = 0;
	a->y = 0;
	b->x = 0;
	b->y = 0;
}

int		main(int argc, char *argv[])
{
	t_fdf *data;

	if (argc != 2)
		print_error("usage: ./fdf file_name.fdf");
	data = (t_fdf*)malloc(sizeof(t_fdf));
	read_file(argv[1], data);
	initialize_data(data);
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
}
