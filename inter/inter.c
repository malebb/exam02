
#include <unistd.h>

unsigned int	in_str(char *str, char c)
{
	unsigned int	i;


	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

unsigned int 		already_seen(char *str, int i, char c)
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
	int		i;
	int		bl;

	bl = '\n';
	if (argc != 3)
	{
		write(1, &bl, 1);
		return (0);
	}
	i = 0;
	while (argv[1][i] != '\0')
	{
		if (in_str(argv[2], argv[1][i]) && !already_seen(argv[1], i, argv[1][i]))
			write(1, &argv[1][i], 1);
		i++;
	}
	write(1, &bl, 1);
	
	return (0);
}
