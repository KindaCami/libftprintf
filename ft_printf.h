#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_flags
{
    int plus; // '+'
    int dash; // '-'
    int hash; // '#'
    int space; // ' '
    int dot; // '.'
    int zero; // '0'
    int width; // ' '
    int precision; // '#'
} t_flags;

t_flags *init_flags(t_flags *flags);
int ft_printf(char const *str, ...);

#endif