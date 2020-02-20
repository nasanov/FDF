/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasanov <nasanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 11:08:01 by nasanov           #+#    #+#             */
/*   Updated: 2019/10/08 19:47:37 by nasanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	struct s_list *n_lst;

	if ((n_lst = (struct s_list*)malloc(sizeof(struct s_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		n_lst->content = NULL;
		n_lst->content_size = 0;
		n_lst->next = NULL;
	}
	else
	{
		if ((n_lst->content = (struct s_list*)malloc(content_size)) == NULL)
		{
			free(n_lst);
			return (NULL);
		}
		else
		{
			ft_memcpy(n_lst->content, content, content_size);
			n_lst->content_size = content_size;
			n_lst->next = NULL;
		}
	}
	return (n_lst);
}

/*
**	//? do we need it to free my node
**
**void	printlists(struct s_list *n)
**{
**	while (n != NULL)
**	{
**		printf("%s\n", n->content);
**		n = n->next;
**	}
**}
**
**int		main(void)
**{
**	struct s_list *head = NULL;
**	struct s_list *second = NULL;
**	struct s_list *third = NULL;
**
**	head = (struct s_list*)malloc(sizeof(struct s_list));
**	second = (struct s_list*)malloc(sizeof(struct s_list));
**	third = (struct s_list*)malloc(sizeof(struct s_list));
**
**	head->content = "1123";
**	head->next = second;
**
**	second->content = "2345";
**	second->next = third;
**
**	third->content = "3123";
**	third->next = ft_lstnew("5asd", 5);
**
**	printlists(head);
**	return 0;
**}
*/
