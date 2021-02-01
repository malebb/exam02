
#include <unistd.h>

unsigned int	already_seen(char *str, char c, int i)
{
	unsigned int	j;

	j = 0;
	while (j < i)
	{
		if (str[j] == c)
			return (1);
		j++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	char	bl;
	int		i;
	int		j;

	bl = '\n';
	if (argc != 3)
	{
		write(1, &bl, 1);
		return (1);
	}
	i = 0;
	while (argv[1][i] != '\0')
	{
		if (!already_seen(argv[1], argv[1][i], i))
			write(1, &argv[1][i], 1);
		i++;
	}
	j = 0;
	while (argv[2][j] != '\0')
	{
		if (!already_seen(argv[1], argv[2][j], i) && !already_seen(argv[2], argv[2][j], j))
			write(1, &argv[2][j], 1);
		j++;
	}
	write(1, &bl, 1);
	return (0);
}
