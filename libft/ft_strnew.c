/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasanov <nasanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 12:37:49 by nasanov           #+#    #+#             */
/*   Updated: 2019/10/07 19:48:42 by nasanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)malloc(size + 1);
	if (ptr == NULL)
		return (NULL);
	else
	{
		while (i <= size)
		{
			ptr[i] = '\0';
			i++;
		}
	}
	return (ptr);
}

/*
** ft_memset(a, '\0', size); // instead of while loop
** // ? why do we need void casting		(void *)
*/
