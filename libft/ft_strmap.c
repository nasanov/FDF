/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasanov <nasanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 10:49:57 by nasanov           #+#    #+#             */
/*   Updated: 2019/10/07 20:21:34 by nasanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = 0;
	str = NULL;
	if (s && f)
	{
		len = ft_strlen(s);
		if (!(str = (char *)malloc(len + 1)))
			return (NULL);
		while (i < len)
		{
			str[i] = f(s[i]);
			i++;
		}
		str[len] = '\0';
	}
	return (str);
}

/*
** char    char_toupper(char c)
** {
**         if (c >= 'a' && c <= 'z')
**                 return (c - 32);
**         return (c);
** }
**
**	int             main(int argc, char **argv)
**	{
**	        char    *res;
**
**	        if (argc == 2)
**	        {
**	                res = ft_strmap(argv[1], ft_toupper);
**	                ft_putendl(res);
**	        }
**	        return (0);
**	}
**
**
**	//?	How to write a test for strmap + ft_toupper?
*/
