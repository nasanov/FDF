#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>

typedef struct
{
    int     width;
    int     height;
    int     **z_matrix;
    int     zoom;
    int     color;
    int     shift_x;
    int     shift_y;
    void    *mlx_ptr;
    void    *win_ptr;
}           fdf;


void        read_file(char *file_name, fdf *data);
void        bresenham(float x, float y, float x1, float y1, fdf *data);
void        draw(fdf *data);

#endif
