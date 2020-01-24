/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasanov <nasanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 14:21:19 by nasanov           #+#    #+#             */
/*   Updated: 2019/10/04 12:11:04 by nasanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}

/*
** int main()
** {
** 	struct s_list *head = NULL;
** 	struct s_list *second = NULL;
** 	struct s_list *third = NULL;
**
** 	head = (struct s_list*)malloc(sizeof(struct s_list));
** 	second = (struct s_list*)malloc(sizeof(struct s_list));
** 	third = (struct s_list*)malloc(sizeof(struct s_list));
**
** 	head->content = 1;
** 	head->next = second;
**
** 	second->content = 2;
** 	second->next = third;
**
** 	third->content = 3;
** 	third->next = NULL;
**
** 	ft_lstdelone(&second, del);
**
** 	printlists(head);
** 	return 0;
** }
*/
