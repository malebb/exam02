
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

unsigned int	init_line(char **line)
{
	if (!(*line = malloc(sizeof(char) * (1))))
		return (0);
	line[0][0] = '\0';
	return (1);
}

int		ft_strlen(char *str)
{
	int		size;

	size = 0;
	while (str[size] != '\0')
	{
		size++;
	}
	return (size);
}

void	ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
}

unsigned int	add_line(char **line, char *buf)
{
	int		size_line;
	char	*new_line;

	size_line = ft_strlen(*line);
	if (!(new_line = malloc(sizeof(char) * (size_line + 2))))
		return (0);
	ft_strcpy(new_line, *line);
	new_line[size_line] = buf[0];
	new_line[size_line + 1] = '\0';
	free(*line);
	*line = new_line;
	return (1);
}

int		get_next_line(char **line)
{
	char	buf[1];
	int		char_read;

	if (!init_line(line))
		return (-1);
	while ((char_read = read(0, buf, 1)))
	{
		if (char_read == -1)
			return (-1);
		if (buf[0] == '\n')
			return (1);
		if (!add_line(line, buf))
			return (-1);
	}
	return (0);
}
/*
int		main(void)
{
	char	*line;
	int		ret;

	open("file.txt", O_RDONLY);
	while ((ret = get_next_line(&line)) == 1)
	{
		printf("l = %s\n", line);
		free(line);
	}
	free(line);
	printf("ret = %d\n", ret);
	return (0);
}
*/
