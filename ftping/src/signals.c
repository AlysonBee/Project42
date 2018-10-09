
#include "ftping.h"

void	sleeper(int time)
{
	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, 0);
	start.tv_sec += time;
	gettimeofday(&end, 0);
	while (start.tv_sec != end.tv_sec)
		gettimeofday(&end, 0);
}

void	signalhandler(int signumber)
{
	if (signumber == SIGINT)
	{
		g_stats.loop = 0;
		write(1, "\n", 1);
		print_summary();
		exit(1);
	}
}
