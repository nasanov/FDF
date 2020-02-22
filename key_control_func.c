/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasanov <nasanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 19:54:23 by nasanov           #+#    #+#             */
/*   Updated: 2020/02/21 20:51:47 by nasanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_background(int key, t_fdf *data)
{
	if (key == 43)
	{
		data->background_name = "./b_background.xpm";
		data->alt_color = 0x10ADED;
		data->color = 0xFFFFFF;
		data->menu_color = 0xFFFFFF;
	}
	if (key == 47)
	{
		data->background_name = "./w_background.xpm";
		data->alt_color = 0x000000;
		data->menu_color = 0x000000;
	}
	return (0);
}

int		key_shift(int key, t_fdf *data)
{
	data->shift_y -= (key == 126) ? 20 : 0;
	data->shift_y += (key == 125) ? 20 : 0;
	data->shift_x -= (key == 123) ? 20 : 0;
	data->shift_x += (key == 124) ? 20 : 0;
	return (0);
}

int		key_alt_iso(int key, t_fdf *data)
{
	if (key == 30)
		data->altitude += 1;
	if (key == 33)
		data->altitude -= 1;
	if (key == 18)
		data->alt_color = 0xBADA55;
	if (key == 19)
		data->alt_color = 0xB00B1E;
	if (key == 20)
		data->alt_color = 0xFACADE;
	if (key == 49)
		data->is3d = !data->is3d;
	return (0);
}
