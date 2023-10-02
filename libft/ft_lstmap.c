/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:15:54 by fracerba          #+#    #+#             */
/*   Updated: 2022/10/21 15:15:56 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	new = malloc(sizeof(t_list));
	temp = new;
	while (lst && lst -> content)
	{
		new -> content = malloc(sizeof(lst -> content));
		if (new -> content == 0)
			return (0);
		new -> content = ((*f)(lst -> content));
		new -> next = malloc(sizeof(t_list));
		if (new -> next == 0)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		lst = lst -> next;
		if (lst != 0)
			new = new -> next;
	}
	free(new -> next);
	new -> next = 0;
	return (temp);
}
