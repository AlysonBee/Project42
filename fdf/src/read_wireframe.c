#include <unistd.h>
#include <fcntl.h>
#include "fdf.h"

char		**read_wireframe(char *filename)
{
	int			fd;
	ssize_t		size;
	char		*ret_content;
	char		temp_content[4096];
	char		*plc;

	fd = open(filename, O_RDONLY);
	if (!fd)
		error_and_exit("Error : filename");
	ret_content = (char*)malloc(sizeof(char));
	bzero(temp_content, sizeof(char));
	while ((size = read(fd, temp_content, 4096)))
	{
		temp_content[size] = '\0';
		plc = join(ret_content, temp_content);
		free(ret_content);
		ret_content = strdup(plc);
		free(plc);
	}
	close(fd);
	return (split(ret_content, '\n'));
}
