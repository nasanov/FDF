/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasanov <nasanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:08:52 by nasanov           #+#    #+#             */
/*   Updated: 2019/10/08 15:39:53 by nasanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_numlen(n, 10);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		str[0] = '-';
	else
		str[0] = '0';
	while (n != 0)
	{
		if (n < 0)
			str[--len] = ((n % 10 * -1) + '0');
		else
			str[--len] = ((n % 10) + '0');
		n /= 10;
	}
	return (str);
}

/*
** int		numlen(long n, int base)
** {
** 	int		len;
**
** 	if (n == 0)
** 		return (1);
** 	if (n < 0)
** 		len = 1;			// ? for minus sign
** 	else
** 		len = 0;
** 	while (n != 0)
** 	{
** 		n /= base;	// ? counting how many digits we have by diviing by 10
** 		len++;
** 	}
** 	return (len);
** }
**
** char		*ft_itoa(int n)
** {
** 	char	*str;
** 	int		len;
**
** 	len = numlen(n, 10);				// ? len of int
** 	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
** 		return (NULL);		// ? seg fault protection
** 	str[len] = '\0';			// last symbol
** 	if (n < 0)
** 		str[0] = '-';			// first symbol
** 	else
** 		str[0] = '0';
** 	while (n != 0)
** 	{
** 		if (n < 0)
** 			str[--len] = ((n % 10 * -1) + '0');
** 		else
** 			str[--len] = ((n % 10) + '0');
** 		n /= 10;
** 	}
** 	return (str);
** }
*/
