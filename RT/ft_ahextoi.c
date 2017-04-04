/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ahextoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <jerollin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 18:02:40 by jerollin          #+#    #+#             */
/*   Updated: 2015/03/21 18:04:10 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_ahextocolor(char *ahex)
{
	char	*str;
	char	*tmp;
	int		c;
	int		res;

	str = ft_strdup(ahex);
	str[2] = '\0';
	tmp = ft_convert_base(str, "0123456789ABCDEF", "0123456789");
	c = ft_atoi(tmp);
	res = c << 16;
	free(str);
	free(tmp);
	str = ft_strdup(ahex + 2);
	str[2] = '\0';
	tmp = ft_convert_base(str, "0123456789ABCDEF", "0123456789");
	c = ft_atoi(tmp);
	res |= c << 8;
	free(str);
	free(tmp);
	str = ft_strdup(ahex + 4);
	tmp = ft_convert_base(str, "0123456789ABCDEF", "0123456789");
	res |= ft_atoi(tmp);
	free(str);
	free(tmp);
	return (res);
}
