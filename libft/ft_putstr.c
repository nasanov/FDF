/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasanov <nasanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:59:53 by nasanov           #+#    #+#             */
/*   Updated: 2019/09/29 16:57:46 by nasanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			ft_putchar(s[i]);
			i++;
		}
	}
}

/*
**	void	ft_putstr(char const *s)
** 	{
** 		size_t	i;
**
** 		i = 0;
** 	//?	if (s)									Segmentation Fault Protection?
** 		{
** 			while (s[i] != '\0')
** 			{
** 				ft_putchar(s[i]);
** 				i++;
** 			}
** 		}
**	{
*/
