/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasanov <nasanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:47:07 by nasanov           #+#    #+#             */
/*   Updated: 2019/10/09 20:41:25 by nasanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *restrict dst, \
const char *restrict src, size_t dstsize)
{
	size_t len_dst;
	size_t len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize <= len_dst)
		return (len_src + dstsize);
	else
		ft_strncat(dst, (char*)src, dstsize - len_dst - 1);
	return (len_dst + len_src);
}

/*
** int main()
** {
** 	char *a = "sdgsfgd1234234";
** 	char *b = "asdasffgd";
** 	size_t ll = ft_strlcat(a, b, 20);
** 	printf("%zu", ll);
** }
*/
