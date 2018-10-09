
#include "ftping.h"

void		print_summary(void)
{
	int				bias;

	printf("--- %s ping statistics ---\n", g_stats.hostname);
	if (g_stats.transm == g_stats.rec)
	{
		bias = 150;
		printf("%d packets transmitted, %d received",
		g_stats.transm, g_stats.rec);
		printf(", 0%% packet loss ");
	}
	else
	{
		bias = 1150;
		printf("%d packets transmitted, %d received",
		packet_loss_calculation(g_stats.starttime), g_stats.rec);
		printf(", 100%% packet loss ");
	}
	elapsed_time_calculation(g_stats.starttime, bias);
}

int			packet_loss_calculation(struct timeval starttime)
{
	struct timeval			current_time;
	long long			packet_loss;

	gettimeofday(&current_time, 0);
	packet_loss = (long long)current_time.tv_sec -
		(long long)starttime.tv_sec;
	return ((int)packet_loss);
}

int			elapsed_time_calculation(struct timeval starttime, int bias)
{
	struct timeval		current_time;
	long long			seconds;
	long long			miliseconds;

	gettimeofday(&current_time, 0);
	seconds = (long long)current_time.tv_sec -
		(long long)starttime.tv_sec;
	miliseconds = (long long)current_time.tv_sec -
		(long long)starttime.tv_usec;
	seconds = (seconds * 1000) + (miliseconds / 10000000) - bias;
	printf(" time %lld ms\n", seconds);
	return (1);
}
