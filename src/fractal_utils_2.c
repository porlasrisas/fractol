/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:12:39 by guigonza          #+#    #+#             */
/*   Updated: 2025/04/08 15:34:13 by guigonza         ###   ########.fr       */
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

int	ft_is_valid_float(char *s)
{
	int	i;
	int	dots;

	i = 0;
	dots = 0;
	if (!s || !s[0])
		return (0);
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if (s[i] == '.')
		{
			dots++;
			if (dots > 1)
				return (0);
		}
		else if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}
