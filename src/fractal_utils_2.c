/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:12:39 by guigonza          #+#    #+#             */
/*   Updated: 2025/04/07 19:36:53 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	parse_integer(const char **str)
{
	double	result;

	result = 0.0;
	while (**str >= '0' && **str <= '9')
	{
		result = result * 10.0 + (**str - '0');
		(*str)++;
	}
	return (result);
}

static double	parse_fraction(const char **str)
{
	double	fraction;
	int		fraction_len;

	fraction = 0.0;
	fraction_len = 0;
	if (*str && **str == '.')
	{
		(*str)++;
		while (**str >= '0' && **str <= '9')
		{
			fraction = fraction * 10.0 + (**str - '0');
			fraction_len++;
			(*str)++;
		}
		while (fraction_len-- > 0)
			fraction /= 10.0;
	}
	return (fraction);
}

double	ft_atof(const char *str)
{
	double	sign;
	double	result;

	sign = 1.0;
	result = 0.0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1.0;
		str++;
	}
	result = parse_integer(&str);
	result += parse_fraction(&str);
	return (result * sign);
}

void	draw_fractal(t_data *d, int (*t_iter_func)(double, double,
			struct s_data *))
{
	int	y;

	y = 0;
	while (y < d->height)
	{
		draw_line(d, y, t_iter_func);
		y++;
	}
}

int lorenz_iterations(double x, double y, t_data *data)
{
    int i = 0;

    // Inicializamos las variables del sistema Lorenz usando el struct
    data->lorenz_x = x;  // Inicializamos 'x'
    data->lorenz_y = y;  // Inicializamos 'y'
    data->lorenz_z = 0.0; // Inicializamos 'z' en 0

    // Parámetros del sistema Lorenz (ya configurados en el struct)
    double sigma = data->lorenz_sigma;
    double rho = data->lorenz_rho;
    double beta = data->lorenz_beta;

    // Iteración hasta el número máximo de iteraciones
    while (i < data->max_iter)
    {
        // Calculamos las derivadas del sistema Lorenz
        data->lorenz_dx = sigma * (data->lorenz_y - data->lorenz_x);    // dx
        data->lorenz_dy = data->lorenz_x * (rho - data->lorenz_z) - data->lorenz_y;  // dy
        data->lorenz_dz = data->lorenz_x * data->lorenz_y - beta * data->lorenz_z;   // dz

        // Actualizamos las variables usando el paso de tiempo
        data->lorenz_x += data->lorenz_dx * 0.01;
        data->lorenz_y += data->lorenz_dy * 0.02;
        data->lorenz_z += data->lorenz_dz * 0.03;

        // Guardamos los valores de 're' e 'im' para la visualización
        data->re = data->lorenz_x / 50.0;  // Escalamos 're' para la visualización
        data->im = data->lorenz_y / 50.0;  // Escalamos 'im' para la visualización

        // Aplicamos desplazamiento y zoom
        data->re = data->re * data->zoom + data->offset_x;
        data->im = data->im * data->zoom + data->offset_y;

        // Aseguramos que los valores estén dentro de la ventana (800x600)
        if (data->re < 0) data->re = 0;
        if (data->im < 0) data->im = 0;
        if (data->re > data->width) data->re = data->width;
        if (data->im > data->height) data->im = data->height;

        // Verificamos si el sistema se escapa (condición de escape)
        if (data->lorenz_x * data->lorenz_x + data->lorenz_y * data->lorenz_y + data->lorenz_z * data->lorenz_z > 1000)
            break;

        i++;  // Incrementamos el contador de iteraciones
    }

    return i;  // Devolvemos el número de iteraciones realizadas
}

