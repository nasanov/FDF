/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasanov <nasanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 10:34:23 by nasanov           #+#    #+#             */
/*   Updated: 2019/10/09 20:37:18 by nasanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *ptr;

	ptr = (char *)malloc(size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}

/*
**	void	*ft_memalloc(size_t size)
**	{
**		char *a;
**
**		a = (char *)malloc(sizeof(size));
**		if (a == NULL)
**			return (NULL);
**		ft_bzero(a, size);
**		return ((void*)ptr);	//? Why do we need this here?
**	}
**
**	int		main()
**	{
**		printf("%p", ft_memalloc(6));
**		return (0);
**	}
*/
