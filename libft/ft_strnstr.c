/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasanov <nasanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 07:40:44 by nasanov           #+#    #+#             */
/*   Updated: 2019/09/27 10:11:25 by nasanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t n;

	i = 0;
	if (needle[i] == '\0')
		return ((char*)&haystack[i]);
	while (haystack[i] && i < len)
	{
		j = 0;
		n = i;
		while (haystack[n] == needle[j] && n < len)
		{
			if (needle[j + 1] == '\0')
				return ((char*)&haystack[i]);
			j++;
			n++;
		}
		i++;
	}
	return (0);
}

/*
**	char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
**	{
**		size_t i;
**		size_t j;
**		size_t n;
**
**	i = 0;
**	if (needle[i] == '\0')
**		return ((char*)&haystack[i]);
**	while (haystack[i] && i < len)
**	{
**		j = 0;  // ! if (no match) -> nullify first element of needle
**		n = i;  // ! remember position of the last used letter of haystack
**		while (haystack[n] == needle[j] && n < len)
**		{
**			if (needle[j + 1] == '\0')  // ! check if it's the last letter
**				return ((char*)&haystack[i]);
**			j++;	// ! 1) get address of the element -->
**			n++;	// ! --> (we have to return pointer to begining of char*)
**		}			// ! 2) type conversion to char*
**		i++;
**	}
**	return (0);
*/
