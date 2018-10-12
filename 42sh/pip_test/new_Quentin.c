#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
// Exec : ls | sort | cat -e
int main(void)
{
	int 	fd[2];
	pid_t 	ls_pid, wc_pid;
	pipe(fd);

	if((ls_pid = fork()) == 0)
	{
		dup2(fd[1], 1);
		//close(fd[0]);

		execl("/bin/ls", "ls", "-l", NULL);
		perror("exec ls failed");
		exit(1);
	}
	if ((wc_pid = fork()) == 0)
	{
		dup2(fd[0], 0);
		close(fd[1]);
		execl("/usr/bin/wc", "wc", NULL);
		perror("exec wc failed");
		exit(0);
	}
	wait(&wc_pid);
	return(1);
}
