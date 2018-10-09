
#include "ftping.h"

unsigned short	run_checksum(unsigned short *p, int len)
{
	unsigned int	total;

	total = 0;
	while (len > 1)
	{
		total += *p++;
		len -= 2;
	}
	if (len == 1)
		total += *(unsigned char *)p;
	total = (total >> 16) + (total & 0xffff);
	total += (total >> 16);
	return ((unsigned short)~total);
}

void			pack_msg(t_icmp *icmp_msg, int seq)
{
	icmp_msg->type = ICMP_ECHO;
	icmp_msg->code = 0;
	icmp_msg->checksum = 0;
	icmp_msg->id = getpid();
	icmp_msg->sequence = seq;
	gettimeofday(&icmp_msg->timestamp, 0);
	icmp_msg->checksum = run_checksum((unsigned short *)icmp_msg,
		sizeof(t_icmp));
	g_stats.transm++;
}
