/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasanov <nasanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 01:04:26 by nasanov           #+#    #+#             */
/*   Updated: 2019/10/09 20:46:28 by nasanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		trim_str_len(char const *s)
{
	size_t		start;
	size_t		end;
	size_t		len;

	start = 0;
	while ((s[start] == '\n' || s[start] == '\t' || \
		s[start] == ' ') && s[start] != '\0')
		start++;
	end = ft_strlen(s) - 1;
	while ((s[end] == '\n' || s[end] == '\t' || \
		s[end] == ' ') && s[start] != '\0')
		end--;
	len = (end - start) + 1;
	return (len);
}

char			*ft_strtrim(char const *s)
{
	char		*ptr;
	size_t		i;
	size_t		len;

	if (s)
	{
		len = trim_str_len(s);
		ptr = (char*)malloc(len + 1);
		if (ptr == NULL)
			return (NULL);
		i = 0;
		while ((*s == ' ' || *s == '\t' || *s == '\n') && *s)
			s++;
		while (i < len)
		{
			ptr[i] = s[i];
			i++;
		}
		ptr[i] = '\0';
	}
	else
		return (NULL);
	return (ptr);
}

/*
**	26	start++;							// first char after spaces
**	29	s[end] == ' ') && s[start] != '\0')	//for full blank strings
**	32	}								// last char before spaces
**	33	len = (end - start) + 1;		// full trimed length
**	34	ptr = (char*)malloc(len + 1);	// memory allocation for string + \n
**	35	if (ptr == NULL)				// protection
**
**	int main()
**	{
**		printf("%s", ft_strtrim("   asd   "));
**		return (0);
**	}
*/
