
#include "ft_printf.h"

t_flags *init_flags(t_flags *flags)
{
    ft_memset(flags, 0, sizeof(t_flags));
    flags->precision = -1;
    return (flags);
}

int format_type_manager(char c, t_flags *flags, va_list *args)
{
    if (c == 'd' || c == 'i')
        return (handle_int(flags, args));
    else if (c == 's')
        return (handle_string(flags, args));
    else if (c == 'c')
        return (handle_char(flags, args));
    else if (c == 'u')
        return (handle_unsigned(flags, args));
    else if (c == 'x' || c == 'X')
        return (handle_hex(flags, args, c));
    else if (c == 'p')
        return (handle_pointer(flags, args));
    else if (c == '%')
        return (handle_percent(flags));
    return (0);
}

int ft_printf(char const *str, ...)
{
    va_list args;
    t_flags flags;
    int     count;

    count = 0;
    va_start(args, str);
    while (*str)
    {
        if (*str == '%')
        {
            str++;
            if (!*str)
                break ;
            init_flags(&flags);
            str = conversion_manager(str, &flags);
            if  (*str)
                count += format_type_manager(*str, &flags, &args);
        }
        else
            count += write(1, str, 1);
        str++;
    }
    va_end(args);
    return (count);
}