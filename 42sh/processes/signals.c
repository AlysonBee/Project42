/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 03:22:08 by angonyam          #+#    #+#             */
/*   Updated: 2017/09/18 15:40:19 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "../libft/libft.h"

void		handler(int code)
{
	if (code == SIGINT)
		ft_putendl("Interrupted");
	else if (code == SIGQUIT)
		ft_putendl("Quit");
	else if (code == SIGKILL)
		ft_putendl("Process Killed");
	ft_putstr("exiting\n");
	exit(1);
}

void		quit_handler(void)
{
	if (signal(SIGINT, handler))
		;
	else if (signal(SIGQUIT, handler))
		;
	else if (signal(SIGKILL, handler))
		;
}
