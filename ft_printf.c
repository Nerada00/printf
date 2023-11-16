#include "ft_printf.h"

int	ft_count_h(unsigned long int nb, unsigned long int b)
{
	int	i;

	i = 1;
	while (nb >= b)
	{
		nb = nb / b;
		i++;
	}
	return (i);
}

int	h(unsigned long int n, char *base)
{
	if (n < ft_strlen(base))
	{
		ft_putchar(base[n]);
	}
	if (n >= ft_strlen(base))
	{
		h(n / ft_strlen(base), base);
		h(n % ft_strlen(base), base);
	}
	return (ft_count_h(n, ft_strlen(base)));
}

int	ft_check(char c, va_list arg)
{
	void	*p;

	if (c == 's')
		return (ft_putstr((char *)va_arg(arg, char *)));
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	if (c == 'u')
		return (h(va_arg(arg, unsigned int), "0123456789"));
	if (c == 'x')
		return (h(va_arg(arg, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (h(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	if (c == 'p')
	{
		p = va_arg(arg, void *);
		if (!p)
			return (write(1, "(nil)", 5));
		return (ft_putstr("0x") + h((unsigned long int)p, "0123456789abcdef"));
	}
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	arg;

	va_start(arg, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
			count += ft_check(s[++i], arg);
		else
		{
			ft_putchar(s[i]);
			count++;
		}
		i++;
	}
	va_end(arg);
	return (count);
}

/*int	main(void)
{
	int	count;

	count = ft_printf("Bruh %s\n", "Cyril");
	printf("%d donc\n", count); //, fflush(stdout);
	count = ft_printf("char-> %c\n", 'a');
	printf("%d cavvvvvvvvrs\n", count); //, fflush(stdout);
	count = ft_printf("Nbr-> %d\n", -42);
	printf("%d chars\n", count); //, fflush(stdout);
	count = ft_printf("Hex-> %x\n", -1);
	printf("%d caaars\n", count); //, fflush(stdout);
	// REAL
	printf("\n\n");
	puts("REAL PRINTF");
	count = printf("Hello %s\n", "John");
	printf("%d donc\n", count); //, fflush(stdout);
	count = printf("Char-> %c\n", 'a');
	printf("%d cars\n", count); //, fflush(stdout);
	count = printf("Nbr-> %d\n", -42);
	printf("%d cars\n", count); //, fflush(stdout);
	count = printf("Hex-> %x\n", -1);
	printf("%d cars\n", count); //, fflush(stdout);
}*/
