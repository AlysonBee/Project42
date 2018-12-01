

#include "matt_daemon.h"

int				main(void)
{
	int				fd_log;

	if ((fd_log = init_daemon_check()) == -1)
	{
		printf("Error : Matt Daemon is already being rescued\n");
		return (-1);
	}
	daemonize(fd_log);
	return (0);
}
