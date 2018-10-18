

#include "traceroute.h"

unsigned short  checksum(char *buffer, int nwords)
{
        unsigned short  *buf;
        unsigned long   sum;

        buf = (unsigned short *)buffer;
        sum = 0;
        while (nwords > 0)
        {
                sum += *buf++;
                nwords--;
        }
        sum = (sum >> 16) + (sum & 0xffff);
        sum += (sum >> 16);
        return (~sum);
}

void    *pack_msg(int i, char *ip, unsigned char buff[])
{
        struct ip               *iphdr;
        struct icmphdr          *icmp;

        iphdr = (struct ip *)buff;
        iphdr->ip_hl = 5;
        iphdr->ip_v = 4;
        iphdr->ip_tos = 0;
        iphdr->ip_len = sizeof(struct ip) + sizeof(struct icmphdr);
        iphdr->ip_id = getpid();
        iphdr->ip_off = 0;
        iphdr->ip_ttl = i;
        iphdr->ip_p = IPPROTO_ICMP;
        inet_pton(AF_INET, ip, &(iphdr->ip_dst));
        iphdr->ip_sum = checksum(buff, 9);
        icmp = (struct icmphdr *)(buff + sizeof(struct ip));
        icmp->type = ICMP_ECHO;
        icmp->code = 0;
        icmp->checksum = 0;
        icmp->un.echo.id = 0;
        icmp->un.echo.sequence = i + 1;
        icmp->checksum = checksum((buff + 20), 4);
        return (buff);
}


