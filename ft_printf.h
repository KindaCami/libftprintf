
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_flags
{
    int plus;
    int dash;
    int hash;
    int space;
    int dot;
    int zero;
    int width;
    int precision;

}   t_flags;

t_flags *init_flags(t_flags *flags);
int     ft_putnbr_unsigned(unsigned long n);
int     ft_putnchar(char c, int n);
int     ft_printf(char const *str, ...);
int     ft_numbers_sign(int n, t_flags *flags);
int     ft_numlen(long n);
void    *ft_memset(void *s, int c, size_t n);
int     ft_putnchar(char c, int n);
int     print_int_aux(long n, char sign,int num_len,t_flags *flags);
const   char *conversion_manager(const char *s, t_flags *flags);
int     format_type_manager(char c, t_flags *flags, va_list *args);
int     handle_int(t_flags *flags, va_list *args);
int     handle_string(t_flags *flags, va_list *args);
size_t	ft_strlen(const char *s);
int     handle_char(t_flags *flags, va_list *args);
int     handle_unsigned(t_flags *flags, va_list *args);
void    ft_puthex(unsigned long n, char c);
int     ft_hexlen(unsigned long n);
int     handle_hex(t_flags *flags, va_list *args, char c);
int     handle_pointer(t_flags *flags, va_list *args);
int     handle_percent(t_flags *flags);

#endif