/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <jerollin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:06:10 by jerollin          #+#    #+#             */
/*   Updated: 2014/11/25 14:50:38 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_putnbr(int n)
{
	char	*nbr;

	nbr = ft_itoa(n);
	ft_putstr(nbr);
	free(nbr);
}
