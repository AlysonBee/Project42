
#include "shell.h"
#include "../line.h"

void		free_2d_array(void **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void		print_an_array(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		ft_printf("evn %s\n", array[i]);
		i++;
	}
}

int			ev_size(char **array)
{
	int		i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char		**ft_arraydup(char **array)
{
	int		i;
	char	**new;

	new = (char**)malloc(sizeof(char*) * ev_size(array) + 1);
	i = 0;
	while (array[i])
	{
		new[i] = ft_strdup(array[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}


void		shell(char *args, char **ev)
{
	char	**new;
	int		val;

	val = 0;
	new = ft_strsplit(args, ' ');
	if (ft_strcmp(new[0], "cd") == 0)
	{
		if (new[1] == NULL)
			ev = ft_cd(ev, NULL, &val);
		else
			ev = ft_cd(ev, "-", &val);
	}
	else if (ft_strstr(args, "exit"))
		exit(1);
	print_an_array(ev);
	free_2d_array((void**)new);
}



int 		main(int argc, char **argv, char **envp)
{
	char **env;
	char *term;
	char *str;

	env = ft_arraydup(envp);
	while (1)
	{
		ft_putstr("> ");
		term = ft_read();
		if (ft_strlen(term) == 0)
			continue ;
		shell(term, env);
		if (ft_strcmp("exit", term) == 0)
			break ;
		free(term);
	}
}
