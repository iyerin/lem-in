/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <iyerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:57:25 by iyerin            #+#    #+#             */
/*   Updated: 2018/10/27 16:40:12 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

// t_list	*ft_create_elem(void *data)
// {
// 	t_list *new;

// 	new = (t_list*)malloc(sizeof(t_list));
// 	if (new != 0)
// 	{
// 		new->next = 0;
// 		new->data = data;
// 	}
// 	return (new);
// }



// void	ft_list_push_back(t_list **begin_list, void *data)
// {
// 	t_list *last;

// 	last = *begin_list;
// 	if (!last)
// 	{
// 		last = ft_create_elem(data);
// 	}
// 	else
// 	{
// 		while (last->next != 0)
// 		{
// 			last = last->next;
// 		}
// 		last->next = ft_create_elem(data);
// 	}
// }