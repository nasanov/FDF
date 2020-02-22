#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# include <stdbool.h>

typedef struct
{
	int     width;
	int     height;
	int     **z_matrix;
	int     zoom;
	int     color;
	int		alt_color;
	int		menu_color;
	char 	*background_name;	
	int		altitude;
	int     shift_x;
	int     shift_y;
	bool	is3d;
	void    *mlx_ptr;
	void    *win_ptr;
}           t_fdf;

typedef struct
{ 
	float	x;
	float	y;
	int 	z;
}			t_coord;

void        read_file(char *file_name, t_fdf *data);
void		bresenham(t_coord a, t_coord b, t_fdf *data);
void        draw(t_fdf *data);
float		max(float x, float y);
float		mod(float x);
void		initialize_coords(t_coord *a, t_coord *b);
void		projection(t_coord *a, t_coord *b);
void		shifting(t_coord *a, t_coord *b, t_fdf *data);
void		change_alt(t_coord *a, t_coord *b, t_fdf *data);
void		zooming(t_coord *a, t_coord *b, t_fdf *data);
void		draw_background(t_fdf *data);
int			key_background(int key, t_fdf *data);
int			key_shift(int key, t_fdf *data);
int			key_alt_iso(int key, t_fdf *data);

#endif
