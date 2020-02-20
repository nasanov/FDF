/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasanov <nasanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:25:31 by nasanov           #+#    #+#             */
/*   Updated: 2019/10/09 20:37:53 by nasanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *p_src;
	char *p_dst;

	p_src = (char*)src;
	p_dst = (char*)dst;
	if (src == dst)
		return (dst);
	while (n--)
	{
		*p_dst = *p_src;
		p_dst++;
		p_src++;
	}
	return ((void *)dst);
}
