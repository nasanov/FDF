/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasanov <nasanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:30:13 by nasanov           #+#    #+#             */
/*   Updated: 2019/10/09 20:42:40 by nasanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *ptr;

	ptr = 0;
	while (*s != '\0')
	{
		if (*s == c)
			ptr = (char *)s;
		s++;
	}
	if (ptr != 0)
		return (ptr);
	if (c == '\0')
		return ((char *)s);
	return (0);
}
