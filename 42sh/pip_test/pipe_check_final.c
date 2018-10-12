#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../shell.h"

int 		fd_in;
int 		p[2];
char		**ft_strarrdup(char **str)
{
	int		i;
	char	**f_str;

	i = -1;
	while (str[++i])
		i++;
	f_str = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (str[++i])
		f_str[i] = ft_strdup(str[i]);
	f_str[i] = NULL;
	return (f_str);
}

char		**ft_strjoinarr(char **str)
{
	int		i;
	char	*ret;
	char	*temp;
	char	**f_ret;

	f_ret = (char **)malloc(sizeof(char *) * 2);
	i = 0;
	ret = ft_strdup(str[i]);
	while (str[++i])
	{
		temp = ft_strdup(str[i]);
		ret = ft_strjoin(ret, " ");
		ret = ft_strjoin(ret, temp);
	}
	f_ret[0] = ft_strdup(ret);
	f_ret[1] = NULL;
	return (f_ret);
}

char		*single_string(char **array)
{
	int		i;
	char	*temp;
	char	*new;	

	temp = ft_strnew(1);
	i = 0;
	while (array[i])
	{
		new = ft_strjoin(temp, array[i]);
		free(temp);
		temp = ft_strjoin(new, " ");
		free(new);
		i++;
	}
	return (temp);
}

void		execve_pipe(char ***cmd)
{
	pid_t	pid;
	char			**main_command;
	extern char 	**environ;
	char		*str;
	int			val = 0;

	while (*cmd != NULL)
	{
		pipe(p);
		pid = fork();
		if (pid == 0)
		{
			dup2(fd_in, 0);
			if (*(cmd + 1) != NULL)
				dup2(p[1], 1);
			close(p[0]);
			main_command = ft_strjoinarr(*cmd);
			str = single_string(main_command);
			process(str, environ, &val, main_command);
			exit(EXIT_FAILURE);
		}
		else
		{
			close(p[1]);
			fd_in = p[0];
			cmd++;
		}
	}
	waitpid(pid, 0, 0);
}

int			exec_pipe(char **str, int len)
{
	char	***pipes;
	char	**temp_pipe;
	int		i;

	pipes = (char ***)malloc(sizeof(char **) * (len));
	i = -1;
	while (str[++i])
	{
		temp_pipe = ft_strsplit(str[i], ' ');
		pipes[i] = ft_strarrdup(temp_pipe);
	}
	pipes[i] = NULL;
	execve_pipe(pipes);
	//ft_freestrarr(temp_pipe);
	return (1);
}

int			pipe_parse(char *command)
{
	char	**temp_pipes;
	int		len;

	len = 0;
	fd_in = 0;
	temp_pipes = ft_strsplit(command, '|');
	len = -1;
	while (temp_pipes[++len])
		len++;
	exec_pipe(temp_pipes, len);
	return (1);
}

int main(void)
{
	char *command = "base64 /dev/urandom | head -c1000 | grep 42 | wc -l | sed -e s/1/Yes/g -e s/0/No/g";
	pipe_parse(command);
}
