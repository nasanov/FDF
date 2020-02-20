#include "fdf.h"

void	print_error(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}

int deal_key(int key, fdf *data)
{
    printf("%d\n", key);
    if (key == 53)
        exit(0);
    // if (key == 126)
    //     data->shift_y -= 10;
    // if (key == 125)
    //     data->shift_y += 10;
    // if (key == 123)
    //     data->shift_x -= 10;
    // if (key == 124)
    //     data->shift_x += 10;
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    draw(data);
    return 0;
}

int main(int argc, char *argv[])
{  
    fdf *data;
    if (argc != 2)
        print_error("usage: ./fdf file_name.fdf");
    data = (fdf*)malloc(sizeof(fdf));
    read_file(argv[1], data);
    data->mlx_ptr = mlx_init();                                                 // initializing a  window
    data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "fils de fer");   // drawing a window
    data->zoom = 30;
    draw(data);
    mlx_key_hook(data->win_ptr, deal_key, data);                                // for bonus part(key control)
    mlx_loop(data->mlx_ptr);                                                    // infinite loop which prevents window closing
}

//TODO norminette, naming