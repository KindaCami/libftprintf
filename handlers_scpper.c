#include "ft_printf.h"

int handle_char(t_flags *flags, va_list *args)
{
    char c;
    int total;

    c = (char)va_arg(*args, int);
    total = 0;
    if (flags->dash == 0)
        total += ft_putnchar(' ', flags->width - 1);
    total += write(1, &c, 1);
    if (flags->dash == 1)
        total += ft_putnchar(' ', flags->width - 1);
    return (total);
}

int handle_string(t_flags *flags, va_list *args)
{
    char    *str;
    int     s_len;
    int print_len;
    int count;

    str = va_arg(*args, char *);
    if (!str)
        str = "(null)";
    s_len = ft_strlen(str);
    print_len = s_len;
    if (flags->dot)
    {
        if (flags->precision < s_len)
            print_len = flags->precision;
        if (flags->precision < 0)
            print_len = s_len;
    }
    count = 0;
    if (!flags->dash && flags->width > print_len)
        count += ft_putnchar(' ', flags->width - print_len);
    count += write(1, str, print_len);
    if (flags->dash && flags->width > print_len)
        count += ft_putnchar(' ', flags->width - print_len);
    return (count);
}

int handle_pointer(t_flags *flags, va_list *args)
{
    unsigned long   ptr;
    int             p_len;
    int             total;

    ptr = (unsigned long)va_arg(*args, void *);
    p_len = ft_hexlen(ptr) + 2;
    total = 0;
    if (flags->dash == 0)
        total += ft_putnchar(' ', flags->width - p_len);
    total += write(1, "0x", 2);
    ft_puthex(ptr, 'x');
    total += (p_len - 2);
    if (flags->dash == 1)
        total += ft_putnchar(' ', flags->width - p_len);
    return (total);
}

int handle_percent(t_flags *flags)
{
    int total;

    total = 0;
    if (flags->dash == 0)
        total += ft_putnchar(' ', flags->width - 1);
    total += write(1, "%", 1);
    if (flags->dash == 1)
        total += ft_putnchar(' ', flags->width - 1);
    return (total);
}