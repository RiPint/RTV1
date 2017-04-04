/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <jerollin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 15:26:29 by jerollin          #+#    #+#             */
/*   Updated: 2015/01/26 15:28:15 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_freetab(char **tab)
{
	int		i;

	if (!tab)
		return (0);
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (0);
}
