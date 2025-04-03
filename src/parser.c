#include "fractol.h"

int parse_args(int ac, char **av, t_data *data)
{
    if (ac < 2)
    {
        ft_putstr_fd("Error! Correct usage: ./fractol mandelbrot\n", 2);
        ft_putstr_fd("                      ./fractol julia [re] [im]", 2);
        return(1);
    }
    if (!ft_strncmp(av[1], "mandelbrot", ft_strlen("mandelbrot")))
        data->iter_func = &mandelbrot_iterations;
    
    else if (!ft_strncmp(av[1], "julia", ft_strlen("julia")))
    {
        data->iter_func = &julia_iterations;
        data->julia_re = -0.7;
        data->julia_im = 0.27015;
        if (ac >= 4)
        {
            data->julia_re = ft_atof(av[2]);
            data->julia_im = ft_atof(av[3]);

        }
    }
    else
    {
        ft_putstr_fd("Error: fractal no reconocido\n", 2);
        ft_putstr_fd("Opciones: mandelbrot, julia\n", 2);
        return (1);
    }
    return (0);
}