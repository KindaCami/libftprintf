
#include "ft_printf.h"

static int  get_num(const char **s)
{
    int num;

    num = 0;
    while (**s >= '0' && **s <= '9')
    {
        num = num * 10 + (**s - '0');
        (*s)++;
    }
    return (num);
}

const  char *conversion_manager(const char *s, t_flags *flags)
{
    while (*s == '-' || *s == '+' || *s == ' ' || *s == '#' || *s == '0')
    {
        if (*s == '-')
            flags->dash = 1;
        else if (*s == '+')
            flags->plus = 1;
        else if (*s == ' ')
            flags->space = 1;
        else if (*s == '#')
            flags->hash = 1;
        else if (*s == '0')
            flags->zero = 1;
        s++;
    }
    if  (*s >= '0' && *s <= '9')
        flags->width = get_num(&s);
    if  (*s == '.')
    {
        flags->dot = 1;
        s++;
        flags->precision = get_num(&s);
    }
    return (s);
}

int ft_numbers_sign(int n, t_flags *flags)
{
    if (n < 0)
        return ('-');
    else if (flags->plus)
        return ('+');
    else if (flags->space)
        return (' ');
    return (0);
}

int ft_numlen(long n)
{
    int len;

    len = 0;
    if (n == 0)
        return (1);
    if (n < 0)
        n *= -1;
    while (n > 0)
    {
        n /= 10;
        len++;
    }
    return (len);
}

int ft_putnbr_unsigned(unsigned long n)
{
    int count;

    count = 0;
    if (n >= 10)
        count += ft_putnbr_unsigned(n / 10);
    count += ft_putnchar((n % 10) + '0', 1);
    return (count);
}