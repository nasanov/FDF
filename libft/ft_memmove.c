/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasanov <nasanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:03:22 by nasanov           #+#    #+#             */
/*   Updated: 2019/10/09 20:38:40 by nasanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *pdst;
	char *psrc;

	pdst = (char*)dst;
	psrc = (char*)src;
	if (psrc < pdst)
	{
		while (len--)
			pdst[len] = psrc[len];
	}
	else
		ft_memcpy(pdst, psrc, len);
	return (dst);
}
