/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_bonus6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <jerollin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 15:40:23 by jerollin          #+#    #+#             */
/*   Updated: 2015/01/31 13:18:46 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

char	*ft_makecolor(char **str)
{
	*str = ft_strdup(*str);
	*str = ft_strreplace(*str, "{red}", C_RED);
	*str = ft_strreplace(*str, "{green}", C_GREEN);
	*str = ft_strreplace(*str, "{blue}", C_BLUE);
	*str = ft_strreplace(*str, "{magenta}", C_MAGENTA);
	*str = ft_strreplace(*str, "{yellow}", C_YELLOW);
	*str = ft_strreplace(*str, "{pink}", C_PINK);
	*str = ft_strreplace(*str, "{cyan}", C_CYAN);
	*str = ft_strreplace(*str, "{white}", C_WHITE);
	*str = ft_strreplace(*str, "{gray}", C_GRAY);
	*str = ft_strreplace(*str, "{blink}", C_BLINK);
	*str = ft_strreplace(*str, "{eoc}", C_EOC);
	return (*str);
}

char	*ft_tild(t_printf *info, int *lenght)
{
	int		len;
	char	*space;

	space = localeconv()->decimal_point;
	len = ft_strlen(info->value) - ft_len_untill(info->value, '.');
	if (info->tild && ft_strchr("fF", info->type) && info->type)
		while (len > 3)
		{
			if (len + ft_len_untill(info->value, '.') != ft_strlen(info->value))
				info->value = ft_strinsert(info->value,
					space, len + ft_len_untill(info->value, '.'));
			len -= 3;
			(*lenght) += 1;
		}
	len = ft_len_untill(info->value, '.');
	if (info->tild && ft_strchr("duifF", info->type) && info->type)
		while (len > 3)
		{
			info->value = ft_strinsert(info->value, space, len - 3);
			len -= 3;
			(*lenght) += 1;
		}
	if (info->intero && ++(*lenght))
		info->value = ft_strjoinnchar(info->value, -1, info->type);
	return (info->value);
}
