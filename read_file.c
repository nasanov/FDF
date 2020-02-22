/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasanov <nasanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 19:40:33 by nasanov           #+#    #+#             */
/*   Updated: 2020/02/21 19:42:36 by nasanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		row_count;

	fd = open(file_name, O_RDONLY, 0);
	row_count = 0;
	while (get_next_line(fd, &line))
	{
		row_count++;
		free(line);
	}
	close(fd);
	return (row_count);
}

int		get_width(char *file_name)
{
	char	*line;
	int		fd;
	int		col_count;

	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd, &line);
	col_count = ft_wordscount(line, ' ');
	free(line);
	close(fd);
	return (col_count);
}

void	filler(int *z_matrix_line, char *line)
{
	char	**arr;
	int		i;

	arr = ft_strsplit(line, ' ');
	i = 0;
	while (arr[i])
	{
		z_matrix_line[i] = ft_atoi(arr[i]);
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	read_file(char *file_name, t_fdf *data)
{
	char	*line;
	int		fd;
	int		i;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_matrix = (int**)malloc(sizeof(int*) * (data->height + 1));
	i = 0;
	while (i <= data->height)
	{
		data->z_matrix[i++] = (int*)malloc(sizeof(int) * data->width + 1);
	}
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		filler(data->z_matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
}
