/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <jerollin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 16:08:40 by jerollin          #+#    #+#             */
/*   Updated: 2015/02/08 16:08:52 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strclean(char *str, char *epur)
{
	int		i;

	i = -1;
	if (!str || !epur)
		return (str);
	while (str[++i])
		while (str[i] && ft_strchr(epur, str[i]))
			ft_memmove(str + i, str + 1 + i, ft_strlen(str + i));
	return (str);
}
