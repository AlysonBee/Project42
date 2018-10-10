

#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*new;
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	new = (char *)malloc(sizeof(char) * (len + 1));
	len = 0;
	while (str[len])
	{
		new[len] = str[len];
		len++;
	}
	new[len] = '\0';
	return (new);
}
