/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasanov <nasanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:30:35 by nasanov           #+#    #+#             */
/*   Updated: 2020/02/17 17:10:26 by nasanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_read_line(char **tab, char **line, int fd)
{
	char	*temp;
	int		count;

	count = 0;
	while (tab[fd][count] != '\0' && tab[fd][count] != '\n')
		count++;
	*line = ft_strsub(tab[fd], 0, count);
	if (tab[fd][count] == '\n')
	{
		temp = ft_strdup(&tab[fd][count + 1]);
		free(tab[fd]);
		tab[fd] = temp;
		if (tab[fd][0] == '\0')
			ft_strdel(&tab[fd]);
	}
	else
		ft_strdel(&tab[fd]);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	char		buffer[BUFF_SIZE + 1];
	int			bytes_read;
	char		*temp;
	static char	*tab[8192];

	if (fd < 0 || BUFF_SIZE <= 0 || line == NULL || read(fd, buffer, 0) < 0)
		return (-1);
	while ((bytes_read = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		if (!tab[fd])
			tab[fd] = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(tab[fd], buffer);
			free(tab[fd]);
			tab[fd] = temp;
		}
		if (ft_strchr(tab[fd], '\n'))
			break ;
	}
	if (tab[fd] == NULL && bytes_read == 0)
		return (0);
	return (ft_read_line(tab, line, fd));
}
