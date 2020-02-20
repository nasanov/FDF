/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasanov <nasanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 01:30:25 by nasanov           #+#    #+#             */
/*   Updated: 2019/10/09 20:40:54 by nasanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int i;

	i = 0;
	if (!(s1 && s2))
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		s1++;
		s2++;
	}
	if (s1[i] != s2[i])
		return (0);
	else
		return (1);
}

/*
** int main()
** {
** 	char *a = "hellp";
** 	char *b = "hell";
** 	printf("%d", ft_strequ(a, b));
** 	return (0);
** }
*/
