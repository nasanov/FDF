/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasanov <nasanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 10:38:41 by nasanov           #+#    #+#             */
/*   Updated: 2019/12/26 17:52:41 by nasanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**memgiver(char const *str, char c)
{
	char	**res;
	int		letters;
	int		i;
	int		j;

	if (!(res = (char **)malloc(sizeof(char*) * (ft_wordscount(str, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		letters = 0;
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i] != '\0')
		{
			letters++;
			i++;
		}
		if (letters > 0)
			if ((res[j++] = (char *)malloc(sizeof(char) * letters + 1)) == NULL)
				return (NULL);
	}
	res[j] = 0;
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**newstr;
	int		len;
	int		i;
	int		j;
	int		k;

	if (s == NULL)
		return (NULL);
	newstr = memgiver(s, c);
	len = ft_wordscount(s, c);
	if (newstr == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (k < len)
	{
		while (s[i] == c && s[i])
			i++;
		j = 0;
		while (s[i] != c && s[i])
			newstr[k][j++] = s[i++];
		newstr[k][j] = '\0';
		k++;
	}
	return (newstr);
}
