/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerollin <jerollin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:02:50 by jerollin          #+#    #+#             */
/*   Updated: 2015/02/04 14:51:19 by jerollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <termios.h>
#include <unistd.h>

void	ft_switch_icanon(void)
{
	struct termios	tattr;

	tcgetattr(0, &tattr);
	tattr.c_lflag ^= ECHO;
	tattr.c_lflag ^= ICANON;
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &tattr);
}
