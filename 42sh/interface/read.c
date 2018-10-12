/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 09:38:50 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/15 18:00:36 by angonyam         ###   ########.fr       */
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

void clear_line(char *str, int count)
{
	int temp;

	tputs(tgetstr("sc", NULL), 1, fputchar);
	temp = count;
	while (--temp)
		tputs(tgetstr("le", NULL), 1, fputchar);
	tputs(tgetstr("cd", NULL), 1, fputchar); //Clear line and below
	ft_printf("%s", str);


char			*rewrite(char *str, char c, int count)
{
	char		*chr;
	int			i;

	if (str == NULL)
	{
		chr = (char *)ft_memalloc(sizeof(char) + 2);
		chr[0] = c;
		chr[1] = '\0';
	}
	else
	{
		chr = (char*)ft_memalloc(sizeof(char) * ft_strlen(str) + 2);
		i = 0;
		while (str[i])
		{
			chr[i] = str[i];
			i++;
		}
		chr[i] = c;
		i++;
		chr[i] = '\0';
	}
	clear_line(chr, count);
	free(str);
	return (chr);
}
// 'dc' is to delete a character at a positoin
// 'ei' is the string to leave insert mode
// 'im' is to enter insert mode

int				main(void)
{
	int			fd;
	char		*plc;
	char		*buf;	
	char		buffer[40 + 1];
	int			bytes;
	int			count;
	char		hello[] = "hello world";
	char		*test;


	test = NULL;
	plc = reading();
	count = 0; 
	while (1)
	{
		ft_bzero(buffer, 7);
		tputs(tgetstr("im", NULL), 1, fputchar);
		bytes = read(0, buffer, 7);
		char c = buffer[0];
		buffer[bytes] = '\0';
		if (ft_isprint(c))
			test = rewrite(test, c, count);
		tputs(tgetstr("im", NULL), 1, fputchar);
		if (buffer[0] == 127) {
			tputs(tgetstr("dm", NULL), 1, fputchar);
		}
		if (ft_strlen(buffer) == 3 && (buffer[2] == 68 &&
				count < ft_strlen(test)))
		{
			count++;
			tputs(tgetstr("le",	NULL), 1, fputchar);
		}
		else if (ft_strlen(buffer) == 3 && 
				buffer[2] == 67 && count > 0)
		{
			count--;
			tputs(tgetstr("nd", NULL), 1, fputchar);
		}
		/*		if (ft_strlen(buffer) == 3 && buffer[2] == 68)
				{
				tputs(tgoto(tgetstr("cm", NULL), 3, 5), 1, fputchar);
				}*/
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

