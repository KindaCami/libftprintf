
/*#include "ft_printf.h"
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

int conversion_manager(const char *s, t_flags *flags)
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


}

int ft_printf(char const *str, ...)
{
    va_list args;
    int total

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
}*/

#include "ft_printf.h" 

int main() 
{
    int n = 42;
    char *s = "42";

    printf("--- 1. ANCHO (Width) ---\n");
    printf("Sin ancho: [%d]\n", n);
    printf("Ancho 10 : [%10d] (Reserva 10 espacios, alinea a la derecha)\n", n);

    printf("\n--- 2. FLAGS BASICOS ---\n");
    printf("Flag '-' : [%-10d] (Alinea a la izquierda dentro de los 10 espacios)\n", n);
    printf("Flag '0' : [%010d] (Rellena con ceros en lugar de espacios)\n", n);
    printf("Flag '+' : [%+d] (Fuerza a mostrar el signo +)\n", n);
    printf("Flag ' ' : [% d] (Deja un espacio si el numero es positivo)\n", n);

    printf("\n--- 3. PRECISION ---\n");
    printf("Entero .5: [%.5d] (Minimo 5 digitos, rellena con ceros)\n", n);
    printf("String .1: [%.1s] (Maximo 1 caracter)\n", s);

    printf("\n--- 4. COMBINACIONES ---\n");
    printf("Mezcla   : [%+10.5d] (Signo +, ancho 10, precision 5)\n", n);

    return 0;
}