/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <jerollin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 17:09:41 by jerollin          #+#    #+#             */
/*   Updated: 2015/01/12 18:34:01 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_tablen(void **tab)
{
	size_t	len;

	len = 0;
	if (!tab)
		return (0);
	while (tab[len])
		++len;
	return (len);
}