#include "fractol.h"

void map_pixel_to_complex(t_data *data, int x, int y, double *re, double *im)
{
    double  range_re;
    double  range_im;

    range_re = 4.0;
    range_im = 3.0;

    *re = ((double)x /(double)data->width) * range_re - (range_re / 2.0);
    *im = ((double)y /(double)data->height) * range_im - (range_re / 2.0);
    *re /= data->zoom;
    *im /= data->zoom;
    *re += data->offset_x;
    *im += data->offset_y;

}

int mandelbrot_iterations(double cr, double ci, t_data *data)
{
    double zr;
	double zi;
	double zr2;
	double zi2;
	int    i;

    zr = 0.0;
	zi = 0.0;
	i = 0;
    while(i < data->max_iter)
    {
        zr2 = zr * zr;
        zi2 = zi * zi;
        if (zr2 + zi2 > 4)
            break ;
        zi = (2.0 * zr * zi) + ci;
        zr = zr2 - zi2 + cr;
        i++;
    }
    return (i);
}
int julia_iterations(double x, double y, t_data *data)
{
    double zr;
    double zi;
    double zr2;
    double zi2;
    int i;

    i = 0;
    zr = x;
    zi = y;
    while(i < data->max_iter)
    {
        zr2 = zr * zr;
        zi2 = zi * zi;
        if (zr2  + zi2 > 4)
            break ;
        zi = 2.0 * zr * zi  + data->julia_im;
        zr = zr2 - zi2 + data->julia_re;
        i++;
    }
    return (i);
}
int calculate_color(int i, int max_iter)
{
    double t;
	int    r;
	int    g;
	int    b;

    if (i == max_iter)
        return (0x00000000);
    	t = (double)i / (double)max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((b << 16) | (g << 8) | r);
}

void   draw_line(t_data *d, int y,
int (*iteration_func)(double, double, t_data *d))
{
    int		x;
	double	re;
	double	im;
	int		iter;

    x = 0;
    while(x < d->width)
    {
        map_pixel_to_complex(d, x, y, &re, &im);
        iter = iteration_func(re, im, d);
        put_pixel(d, x, y, calculate_color(iter, d->max_iter));
        x++;
    }
}

void draw_fractal(t_data *d, t_iter_func iteration_func)
{
    int y;

    y = 0;
    while(y < d->height)
    {
        draw_line(d, y, iteration_func);
        y++;
    }
}