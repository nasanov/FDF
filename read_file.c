#include "fdf.h"

int get_height(char *file_name)
{
    char *line;
    int fd;
    int height;

    fd = open(file_name, O_RDONLY, 0);
    height = 0;
    while(get_next_line(fd, &line))         // counting amount of lines
    {
        height++;
        free(line);
    }
    close(fd);
    return (height);
}

int get_width(char *file_name)
{
    int width;
    int fd;
    char *line;

    fd = open(file_name, O_RDONLY, 0);
    get_next_line(fd, &line);
    width = ft_wordscount(line, ' ');       // counting amount of numbers in one line
    free(line);
    close(fd);
    return (width);
}

void    fill_matrix(int *z_line, char *line)
{
    char **nums;
    int i;

    nums = ft_strsplit(line, ' ');
    i = 0;
    while(nums[i])
    {
        z_line[i] = ft_atoi(nums[i]);               // splitting line into separate chars and converting them to ints -> line by line;
        free(nums[i]);
        i++;
    }
    free(nums);
}

void    read_file(char *file_name, t_fdf *data)
{
    int fd;
    char *line;
    int i;

    data->height = get_height(file_name);   // height of the file
    data->width = get_width(file_name);     // width of the file
    data->z_matrix =  (int**)malloc(sizeof(int*) * (data->height + 1));  // allocate memory for array of strings
    i = 0;
    while(i <= data->height)
    {
        data->z_matrix[i++] = (int*)malloc(sizeof(int) * data->width + 1);    //   allocating memory for each separate string
    }
    fd = open(file_name, O_RDONLY, 0);
    i = 0;
    while(get_next_line(fd, &line))
    {
        fill_matrix(data->z_matrix[i], line);   
        free(line);
        i++;
    }
    close(fd);
    
    // ? data->z_matrix[i] = NULL;  
    // ! НАХУЯ?
}
