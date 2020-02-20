/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasanov <nasanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 02:06:56 by nasanov           #+#    #+#             */
/*   Updated: 2019/10/09 20:42:17 by nasanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!(s1 && s2))
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return (0);
		n--;
		s1++;
		s2++;
	}
	if (s1[i] != s2[i] && i < n)
		return (0);
	else
		return (1);
}

/*
** int main()
** {
** 	char *a = "hellp";
** 	char *b = "he1l";
** 	printf("%d", ft_strnequ(a, b, 2));
** 	return (0);
** }
*/
