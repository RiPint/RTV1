/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <jerollin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:02:35 by jerollin          #+#    #+#             */
/*   Updated: 2014/12/02 19:22:23 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(size_t n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		++len;
		n /= 10;
	}
	return (len);
}

char		*ft_zutoa(size_t n)
{
	char	*s;
	int		len;

	len = ft_int_len(n);
	s = ft_strnew(len);
	if (n == 0)
		s[0] = '0';
	while (n)
	{
		--len;
		s[len] = '0' + n % 10;
		n /= 10;
	}
	return (s);
}
