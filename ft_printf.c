
#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

// Funcion de activacion de la estructura
t_flags *init_flags(t_flags *flags)
{
    flags->plus = 0;
    flags->dash = 0;
    flags->hash = 0;
    flags->space = 0;
    flags->dot = 0;
    flags->zero = 0;
    flags->width = 0;
    flags->precision = -1;
    return (flags);
}

int ft_printf(char const *str, ...)
{
    va_list args;
    int total;

    va_start(args, str);
    
    while (*str)
    {
        if (*str == '%')
        {
            str++;
            //total += gestionar_conversion(*str, args);
        }
        else
        // total += write(1, str, 1);
        //str++;
    }
    va_end(args);
    return (total);
}


/* int main() {
    int dias = 7;
    float precio = 15.50;
    int total_char = printf("El producto cuesta %.2f y tarda %d días.\n", precio, dias);
    printf("El numero de char en la fase es %d \n", total_char);
}*/