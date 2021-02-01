
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int		w;
int		p;
char 	format;
int		c_print;

void	parse(const char *f, int *i)
{
	while (f[*i] >= '0' && f[*i] <= '9')
	{
		w *= 10;
		w += f[*i] - 48;
		*i = *i + 1;
	}
	if (f[*i] == '.')
	{
		p = 0;
		*i = *i + 1;
		while (f[*i] >= '0' && f[*i] <= '9')
		{
			p *= 10;
			p += f[*i] - 48;
			*i = *i + 1;
		}
	}
	format = f[*i];
}

void	init_parse(void)
{
	w = 0;
	p = -1;
}
void	ft_putchar(char c)
{
	write(1, &c, 1);
	c_print++;
}

int		ft_strlen(char *str)
{
	int		size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}

void	print_string(va_list arg)
{
	int		i;
	int		j;
	char	*str;

	str = va_arg(arg, char *);
	i = 0;
	if (p != -1)
	{
		while (i < w - p)
		{
			ft_putchar(' ');
			i++;
		}
		j = 0;
		while (j < p && str[j] != '\0')
		{
			ft_putchar(str[j]);
			j++;
		}
	}
	else
	{
		while (i < w - ft_strlen(str))
		{
			ft_putchar(' ');
			i++;
		}
		j = 0;
		while (str[j] != '\0')
		{
			ft_putchar(str[j]);
			j++;
		}
	}
}

int		ft_size_nb(int	nb)
{
	int		size;

	size = 1;
	while (nb >= 10)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

int		size_hexa(int nb)
{
	int		size;

	size = 1;
	while (nb >= 16)
	{
		nb /= 16;
		size++;
	}
	return (size);
}

void	ft_putnbr(long int nb)
{

	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + 48);
}

void	print_int(va_list arg)
{
	int			i;
	long int	nb;
	int			size_nb;
	int			neg;

	nb = (long int) va_arg(arg, int);
	if (nb < 0)
	{
		neg = 1;
		nb *= -1;
	}
	else
		neg = 0;
	size_nb = ft_size_nb(nb);
	i = 0;
	if (p != -1 && p > size_nb)
	{
		while (i < w - (size_nb + (p - size_nb) + neg))
		{
			ft_putchar(' ');
			i++;
		}
		if (neg)
			ft_putchar('-');
		i = 0;
		while (i < p - size_nb)
		{
			ft_putchar('0');
			i++;
		}
		ft_putnbr(nb);
	}
	else
	{
		if (neg)
			ft_putchar('-');
		while (i < w - (size_nb + neg))
		{
			ft_putchar(' ');
			i++;
		}
		ft_putnbr(nb);
	}
}

void	ft_putnbr_hexa(long long int nb, char *hexa)
{
	if (nb >= 16)
		ft_putnbr_hexa(nb / 16, "0123456789abcdef");
	ft_putchar(hexa[nb % 16]);
}

void	print_hexa(va_list arg)
{
	
	int		i;
	int		nb;
	int		size_nb;

	nb = va_arg(arg, long long int);
	size_nb = size_hexa(nb);
	i = 0;
	if (p != -1 && p > size_nb)
	{
		while (i < w - (size_nb + (p - size_nb)))
		{
			ft_putchar(' ');
			i++;
		}
		i = 0;
		while (i < p - size_nb)
		{
			ft_putchar('0');
			i++;
		}
		ft_putnbr_hexa(nb, "0123456789abcdef");
	}
	else
	{
		while (i < w - size_nb)
		{
			ft_putchar(' ');
			i++;
		}
		ft_putnbr_hexa(nb, "0123456789abcdef");
	}
}

void	print_arg(va_list arg)
{
	if (format == 's')
		print_string(arg);
	else if (format == 'd')
		print_int(arg);
	else if (format == 'x')
		print_hexa(arg);
}

int		ft_printf(const char *f, ...)
{
	int			i;
	va_list 	arg;

	i = 0;
	va_start(arg, f);
	c_print = 0;
	while (f[i] != '\0')
	{
		init_parse();
		if (f[i] == '%')
		{
			i++;
			parse(f, &i);
			print_arg(arg);
		}
		else
			ft_putchar(f[i]);
		i++;
	}
	va_end(arg);
	return (c_print);
}

int		main(void)
{
	ft_printf("return: %d \n", ft_printf("%10.5d", -456));
	return (0);
}

