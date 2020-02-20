#include "fdf.h"

float   max(float x, float y)
{
    return ((x > y) ? x : y);
}

float   mod(float x)
{
    return (x < 0) ? -x : x;
}

void    isometric(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(0.8);
    *y = (*y + *x) * sin(0.8) - z;
    // *x = (*x - *y) * cos(0.2);
    // *y = (*y + *y) - z;
}

void    bresenham(float x1, float y1, float x2, float y2, fdf *data) // алгоритм для прорисовки линий (cоединяет двe точки на карте)
{
    float x_step;
    float y_step;
    int max_num;
    int z1;
    int z2;

    z1 = data->z_matrix[(int)y1][(int)x1];
    z2 = data->z_matrix[(int)y2][(int)x2];
    //----------zoom----------

    x1 *= data->zoom;
    y1 *= data->zoom;
    x2 *= data->zoom;
    y2 *= data->zoom;

    //----------color----------
    data->color = (z1 || z2) ? 0xFACE0F : 0xA991E5;
    
    //---------3D--------
    isometric(&x1, &y1, z1 * 1);  
    isometric(&x2, &y2, z2 * 1);  

    //------------shift---------
    x1 += 350;  // + data->shift_x;   
    y1 += 350;  // + data->shift_y;   
    x2 += 350;  // + data->shift_x;   
    y2 += 350;  // + data->shift_y;   

    x_step = x2 - x1;
    y_step = y2 - y1;
    max_num = max(mod(x_step), mod(y_step));
    x_step /= max_num;
    y_step /= max_num;
    while((int)(x1 - x2) || (int)(y1 - y2))
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x1, y1, data->color);
        x1 += x_step;
        y1 += y_step;
    }
}

void	print_menu(fdf data)
{
	char *menu;

	menu = "use up, down, left, right arrows to move picture";
	mlx_string_put(data.mlx_ptr, data.win_ptr, 10, 5, 0xFACE0F, menu);
}

void    draw(fdf *data)
{
    int x;
    int y;

    print_menu(*data);
    y = 0;
    while(y < data->height)
    {
        x = 0;
        while(x < data->width)
        {
            if (x < data->width - 1)
                bresenham(x, y, x + 1, y, data);
            if (y < data->height - 1)
                bresenham(x, y, x, y + 1, data);
            x++;
        }
        y++;
    }
}
