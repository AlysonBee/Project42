/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 09:38:50 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/14 08:17:26 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <term.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../shell.h"
#include <termios.h>
#include <termcap.h>

char		*get_home(void)
{
	extern char		**environ;
	int				i;
	char			*ret;
	char			**temp;

	i = 0;
	while (environ[i])
	{
		temp = ft_strsplit(environ[i], '=');
		if (ft_strequ(temp[0], "HOME"))
		{
			ret = ft_strdup(temp[1]);
			free_2d_array((void**)temp);
			return (ret);
		}
		free_2d_array((void**)temp);
		i++;
	}
	return (NULL);
}

char		*reading(void)
{
	struct termios		tattr;
	char				*str;
	char				*env;
	char				*histdir;
	char				*path;

	env = getenv("TERM");
	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag &= ~(ICANON | ECHO);
	tattr.c_oflag &= ~(OPOST);
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	tattr.c_cc[VINTR] = 0;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);
	tgetent(NULL, env);
	path = get_home();
	histdir = ft_strjoin(path, "/.temp");
	free(path);
	return (histdir);
}

int				fputchar(int c)
{
	write(1, &c, 1);
	return (1);
}


int				main(void)
{
	int			fd;
	char		*plc;
	char		*buf;
	char		word[] = "Hello World";
	char		buffer[40 + 1];
	int			bytes;
	int			count;

	plc = reading();
	count = 0;
	while (1)
	{
		bytes = read(0, buffer, 7);
		buffer[bytes] = '\0';
		tputs(tgetstr("cl", NULL), 1, fputchar);
		//ft_putendl("Screen is clearerd");
		count++;
		ft_printf("Screen cleared %d times\n", count);

		//t_printf("%s key %d and length %d\n", buffer, buffer[0], ft_strlen(buffer));
		/*if (ft_strlen(buffer) == 1)
		{
			if (ft_isprint(buffer[0]))
				ft_putchar(buffer[0]);
		}
		else
		{
			tputs(tgetstr("ue", NULL), 1, fputchar);
			tputs(tgetstr("cr", NULL), 1, fputchar);
			tputs(tgetstr("us", NULL), 1, fputchar);
		}*/
	}
	//printf("Anything");
	/*tputs(tgetstr("cm", NULL), 1, fputchar);
	  printf("something\n");
	  tputs(tgetstr("cm", NULL), 1, fputchar);*/

	//tput
	return (0);
}

