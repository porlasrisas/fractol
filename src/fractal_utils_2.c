#include "fractol.h"

double  ft_atof(const char *str)
{
    double  sign;
    double  result;
    double  fraction;
    int     fraction_len;

    sign = 1.0;
    result = 0.0;
    fraction = 0.0;
    fraction_len = 0;
    // 1. Saltamos espacios
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    // 2. Miramos signo
    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign = -1.0;
        str++;
    }
    // 3. Parte entera
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10.0 + (*str - '0');
        str++;
    }
    // 4. Si hay punto decimal, leemos la parte fraccionaria
    if (*str == '.')
    {
        str++;
        while (*str >= '0' && *str <= '9')
        {
            fraction = fraction * 10.0 + (*str - '0');
            fraction_len++;
            str++;
        }
        // Dividimos la parte fraccionaria por 10^n
        while (fraction_len-- > 0)
            fraction /= 10.0;
        // Sumamos fracción al entero
        result += fraction;
    }
    return (result * sign);
}
