/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <jerollin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 17:06:37 by jerollin          #+#    #+#             */
/*   Updated: 2015/02/05 17:12:30 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplitstr(char *s, char *c)
{
	char	*splitable;
	char	**tab;

	tab = NULL;
	splitable = ft_strfreplace(ft_strdup(s), c, "\177");
	if (splitable)
	{
		tab = ft_strsplit(splitable, '\177');
		ft_free(splitable);
	}
	return (tab);
}
