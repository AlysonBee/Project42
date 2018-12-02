

#include <unistd.h>
#include <fcntl.h>
#include "matt_daemon.h"
#include <sys/stat.h>
#include <dirent.h>

int		check_lock_file(void)
{
	struct stat			info;
	DIR					*dp;
	struct dirent		*dir;

	if ((dp = opendir(".")) < 0)
		printf("Error opening directory\n");
	while ((dir = readdir(dp)))
	{
		if (strcmp(dir->d_name, "matt_daemon.lock") == 0)
		{
			closedir(dp);
			return (-1);
		}
	}
	closedir(dp);
	return (1);
}

int			init_daemon_check(void)
{
	int		fd_lock;
	int		fd_log;

	if (check_lock_file() == -1)
		return (-1);
	fd_lock = open("matt_daemon.lock", O_RDONLY | O_CREAT);
	close(fd_lock);
	fd_log = open("matt_daemon.log", O_RDWR | O_CREAT);
	return (fd_log);
}
