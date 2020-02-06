/*
man /usr/share/man/man3/mlx.1

#include <mlx.h>

FUNCTION PROTOTYPES:
	void *mlx_init();

FUNCTIONS:
mlx_new_window : manage windows;
mlx_pixel_put: 	 draw inside window			should we use it?
mlx_new_image:    manipulate images;
mlx_loop:		 handle keyboard or mouse events

LINKING MiniLib on MacOS
	-lmlx -framework OpenGL -framework AppKit

man /usr/share/man/man3/mlx_new_window.1

FUNCTION PROTOTYPES:
	void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
	int mlx_clear_window(void *mlx_ptr, void *win_ptr);
	int mlx_destroy_window(void *mlx_ptr, void *win_ptr);

man /usr/share/man/man3/mlx_pixel_put.1

man /usr/share/man/man3/mlx_loop.1
int mlx_loop (void *mlx_ptr);
int mlx_key_hook (void *win_ptr, int (*function_ptr)(), void *param);           function pointers for smooth running of our program
int mlx_mouse_hook (void *win_ptr, int (*function_ptr)(), void *param);
int mlx_expose_hook (void *win_ptr, int (*function_ptr)(), void *param);
int mlx_loop_hook (void *win_ptr, int (*function_ptr)(), void *param);

main.c
*/
#include "./minilibx_macos/mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int counter = 0;

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int deal_key(int key, void *param/*, void *mlx_ptr, void *win_ptr*/)          // keyboard click => write X
{
    if (counter <= 25)
    {
        ft_putchar('A' + counter);
    }
    counter++;
    /*
    void *mlx_ptr;
    void *win_ptr;
    mlx_pixel_put(mlx_ptr, win_ptr, 150, 150, 0xFEFEFE);
    */
    return 0;
}

int main()
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "mlx_lib test");

    char *filename;
    int height = 1000;
    int width = 1000;
    filename = "./lady.xpm";
    
    static char *xpm_data[] = {
    "16 16 10 1",
    "  c black",
    ". c navy",
    "X c blue",
    "o c #008000",
    "O c green",
    "+ c cyan",
    "@ c #800000",
    "# c red",
    "$ c white",
    "% c None",
    "%%%%%%%%%%%%%%%%",
    "%%%@ %%%%%%. %%%",
    "%%@$# %%%%.+X %%",
    "%@$$## %%.++XX %",
    "@$$$### .+++XXX ",
    "@###@@@ .XXX... ",
    "%@##@@ o .XX.. %",
    "%%@#@ o$O .X. %%",
    "%%%@ o$$OO . %%%",
    "%%%%o$$$OOO %%%%",
    "%%%%oOOOooo %%%%",
    "%%%%%oOOoo %%%%%",
    "%%%%%%oOo %%%%%%",
    "%%%%%%%o %%%%%%%",
    "%%%%%%%%%%%%%%%%",
    "%%%%%%%%%%%%%%%%"
    };

    void *img_ptr = mlx_xpm_to_image (mlx_ptr, xpm_data, &width, &height);
    void *img_ptr2 = mlx_new_image(mlx_ptr, 500, 500); 
    void *img_ptr3 = mlx_xpm_file_to_image(mlx_ptr, filename, &width, &height);

    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr3, 100, 100);
    // mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr3, 300, 300);
    // mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr3, 500, 500);
    // mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr3, 700, 700);
    //mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr2, 500, 500);

        
    int i = 6999;
    int colors[] = {0xFEFEFE, 0xFF2D00, 0x1ABC9C, 0x3498DB, 0x8E44AD, 0xF1C40F, 0xD35400, 0x00FFFF};
    char *strings[8] = {"hello", "world", "42", "silicon", "valley", "witcher", "programming", "web development"};

	int k = 0;
	while (i != 0)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, rand() % 1000, rand() % 1000, colors[rand() % 8]);
        i--;
    }

    int j = 250;
    while(j != 0)
    {
        mlx_string_put(mlx_ptr, win_ptr, rand() % 1000, rand() % 1000, colors[rand() % 8], strings[rand() % 8]);
        j--;
    }

    int x = -50;
    while(x < 1000)
    {
        mlx_string_put(mlx_ptr, win_ptr, x, 100,  0xFFFFFF /* colors[rand() % 8] */ ,   ".");
        mlx_string_put(mlx_ptr, win_ptr, x, 300,  0xFFFFFF /* colors[rand() % 8] */ ,   ".");
        mlx_string_put(mlx_ptr, win_ptr, x, 500,  0xFFFFFF /* colors[rand() % 8] */ ,   ".");
        mlx_string_put(mlx_ptr, win_ptr, x, 700,  0xFFFFFF /* colors[rand() % 8] */ ,   ".");
        mlx_string_put(mlx_ptr, win_ptr, x, 900,  0xFFFFFF /* colors[rand() % 8] */ ,   ".");
        mlx_string_put(mlx_ptr, win_ptr, x, 1100, 0xFFFFFF /* colors[rand() % 8] */ ,  ".");

        mlx_string_put(mlx_ptr, win_ptr, x, 0,    0xFFFFFF /* colors[rand() % 8] */ ,   ".");
        mlx_string_put(mlx_ptr, win_ptr, x, 200,  0xFFFFFF /* colors[rand() % 8] */ ,  ".");
        mlx_string_put(mlx_ptr, win_ptr, x, 400,  0xFFFFFF /* colors[rand() % 8] */ ,  ".");
        mlx_string_put(mlx_ptr, win_ptr, x, 600,  0xFFFFFF /* colors[rand() % 8] */ ,  ".");
        mlx_string_put(mlx_ptr, win_ptr, x, 800,  0xFFFFFF /* colors[rand() % 8] */ ,  ".");
        mlx_string_put(mlx_ptr, win_ptr, x, 1000, 0xFFFFFF /* colors[rand() % 8] */ ,  ".");

        mlx_string_put(mlx_ptr, win_ptr, 100, x,  0xFFFFFF /* colors[rand() % 8] */ ,   ".");
        mlx_string_put(mlx_ptr, win_ptr, 300, x,  0xFFFFFF /* colors[rand() % 8] */ ,   ".");
        mlx_string_put(mlx_ptr, win_ptr, 500, x,  0xFFFFFF /* colors[rand() % 8] */ ,   ".");
        mlx_string_put(mlx_ptr, win_ptr, 700, x,  0xFFFFFF /* colors[rand() % 8] */ ,   ".");
        mlx_string_put(mlx_ptr, win_ptr, 900, x,  0xFFFFFF /* colors[rand() % 8] */ ,   ".");
        mlx_string_put(mlx_ptr, win_ptr, 1100, x, 0xFFFFFF /* colors[rand() % 8] */ ,  ".");

        mlx_string_put(mlx_ptr, win_ptr, 0,   x,  0xFFFFFF /* colors[rand() % 8] */ ,  ".");
        mlx_string_put(mlx_ptr, win_ptr, 200, x,  0xFFFFFF /* colors[rand() % 8] */ ,  ".");
        mlx_string_put(mlx_ptr, win_ptr, 400, x,  0xFFFFFF /* colors[rand() % 8] */ ,  ".");
        mlx_string_put(mlx_ptr, win_ptr, 600, x,  0xFFFFFF /* colors[rand() % 8] */ ,  ".");
        mlx_string_put(mlx_ptr, win_ptr, 800, x,  0xFFFFFF /* colors[rand() % 8] */ ,  ".");
        mlx_string_put(mlx_ptr, win_ptr, 1000, x, 0xFFFFFF /* colors[rand() % 8] */ ,  ".");
        x++;     
    }

    mlx_key_hook(win_ptr, deal_key, (void *)0);
    mlx_loop(mlx_ptr);
}
/*
RUN: 
	gcc -I /usr/local/include main.c -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
	./a.out
*/
