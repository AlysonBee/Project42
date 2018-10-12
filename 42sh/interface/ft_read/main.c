/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 08:10:09 by angonyam          #+#    #+#             */
/*   Updated: 2017/11/19 15:52:24 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "line.h"

int		main(void)
{
	char	*term;
	struct termios	tattr;
	tcgetattr(STDIN_FILENO, &tattr);
	while (1)
	{
		ft_putstr("$>");
		default_mode();
		term = ft_read();
		if (strcmp(ft_strtrim(term), "exit") == 0)
			exit(1);
		tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);
		free(term);
	}
}







