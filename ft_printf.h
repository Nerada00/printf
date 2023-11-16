#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *s, ...);
int		ft_putnbr(int nb);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_count(int nb);
int		ft_print_digit(unsigned long int nb, char *base);
int		ft_print_format(char spec, va_list ap);
size_t	ft_strlen(char *str);

#endif
