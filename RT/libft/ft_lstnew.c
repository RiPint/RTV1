/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <jerollin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:23:55 by jerollin          #+#    #+#             */
/*   Updated: 2014/11/12 12:00:30 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void const *content, size_t content_size)
{
	t_list	*res;

	res = (t_list*)ft_malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->next = NULL;
	if (!content)
	{
		res->content = NULL;
		res->content_size = 0;
		return (res);
	}
	res->content = ft_malloc(content_size);
	if (!res->content)
	{
		res->content_size = 0;
		return (NULL);
	}
	ft_memcpy(res->content, content, content_size);
	res->content_size = content_size;
	return (res);
}
