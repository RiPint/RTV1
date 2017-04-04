/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <jerollin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/09 20:30:09 by jerollin          #+#    #+#             */
/*   Updated: 2014/11/04 14:28:29 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int	len;

	len = ft_strlen(dest);
	ft_memcpy(&dest[len], src, n);
	dest[n + len] = '\0';
	return (dest);
}
