


#include "woodpacker.h"

void	help(void)
{
	printf("Usage : ./woody <filename>\n");
	exit(1);
}

int	is_valid_elf(unsigned char *content)
{
	if (content[0] == 0x7f && strcmp((char *)&content[1], "ELF") == 0)
		return (1);
	return (-1);	
}

int	main(int argc, char **argv)
{
	unsigned char 	*content;
	size_t		size;

	if (argc != 2)
		help();
	map_file(&content, &size, argv[1]);
	if (is_valid_elf(content) == -1)
	{
		munmap(content, size);
		help();
	}
		
}
