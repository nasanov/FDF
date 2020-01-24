/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordscount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasanov <nasanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:52:14 by nasanov           #+#    #+#             */
/*   Updated: 2019/10/08 15:52:21 by nasanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_wordscount(const char *s, char c)
{
	int		i;
	int		n;

	n = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			while (s[i] == c)
				i++;
		else if (s[i])
		{
			n++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (n);
}
