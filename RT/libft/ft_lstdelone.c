/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <jerollin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:34:32 by jerollin          #+#    #+#             */
/*   Updated: 2014/11/12 12:02:43 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;

	if (!del || !alst)
		return ;
	if (!*alst)
		return ;
	lst = *alst;
	del(lst->content, lst->content_size);
	free(lst);
	*alst = NULL;
}
