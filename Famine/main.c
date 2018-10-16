
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include<stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <string.h>

#define USER_ID "Famine version 1.0 (c)oded by angonyam-ckatz"

void	error_and_exit(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}

void	map_file(unsigned char **content, size_t *size, char *filename)
{
	int			fd;
	struct stat		info;

	fd = open(filename, O_RDONLY);
	fstat(fd, &info);
	*size = info.st_size;
	*content = mmap(0, *size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
	if (*content == MAP_FAILED)
		error_and_exit("Error : mmap\n");
}

void	famine(unsigned char *content ,size_t size)
{
	FILE		*fp;

	fp = fopen("target", "ab+");
	fwrite(content, size, 1, fp);
	fwrite(USER_ID, strlen(USER_ID), 1, fp);
	fclose(fp);
	chmod("target", 0777);
}

int	main(int argc, char **argv)
{
	unsigned char	*content;
	size_t		size;

	if (argc != 2)
	{
		printf("Usage : %s <filename>\n", argv[0]);
		exit(1);
	}
	map_file(&content, &size, argv[1]);
	famine(content, size);
}
