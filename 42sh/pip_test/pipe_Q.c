// Exec : ls | sort | cat -e
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

int 		fd_in;
int 		p[2];

void		print_arr(char **str)
{
	int 	i;
	i = -1;
	while(str[++i])
		printf("%s\n", str[i]);
}

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
void	execve_pipe(char ***cmd)
{
	pid_t 	pid;
	char 	**main_command;

	while(*cmd != NULL)
	{
		pipe(p);
		pid = fork();
		if (pid == 0)
		{
			dup2(fd_in, 0);
			if(*(cmd + 1) != NULL)
				dup2(p[1], 1);
			close(p[0]);
			main_command = ft_strjoinarr(*cmd);
			execvp(main_command[0], main_command); // Fix
			exit(1);
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
int 	exec_pipe(char **str, int len)
{
	char 	***pipes;
	char	**temp_pipe;
	int 	i;

	pipes = (char ***)malloc(sizeof(char **) * len);
	i = -1;
	while(str[++i])
	{
		temp_pipe = ft_strsplit(str[i], ' ');
		pipes[i] = ft_strarrdup(temp_pipe);
	}
	pipes[i] = NULL;
	execve_pipe(pipes);
	//Free temp_pipes over here
	return(1);
}
int 	pipe_parse(char *command)
{
	printf("Command is : %s\n", command);
	char 	**temp_command;
	int 	l;

	fd_in = 0;
	temp_command = ft_strsplit(command, '|');
	l = -1;
	print_arr(temp_command);
	while(temp_command[++l])
		l++;
	exec_pipe(temp_command, l);
	return(1);
}
int main()
{
	char *command;
	command = strdup("ls | sort | cat -e");
	pipe_parse(command);
}
