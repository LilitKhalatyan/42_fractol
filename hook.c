/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalaty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:13:56 by lkhalaty          #+#    #+#             */
/*   Updated: 2021/10/10 17:13:58 by lkhalaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_julia(int x, int y, t_data *data)
{
	if (data->fractal == 0)
	{
		data->c_r = (x * 2) / (double)data->width;
		data->c_m = (y * 2 - 800) / (double)data->width;
		draw_win(data);
	}
	return (0);
}

void	zoom_in(int x, int y, t_data *data)
{
	data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom * 1.3));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom * 1.3));
	data->zoom *= 1.3;
	data->max_it++;
}

void	zoom_out(int x, int y, t_data *data)
{
	data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom / 1.3));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom / 1.3));
	data->zoom /= 1.3;
	data->max_it--;
}

int	zoom(int button, int x, int y, t_data *data)
{
	if (button == 5)
		zoom_in(x, y, data);
	else if (button == 4)
		zoom_out(x, y, data);
	draw_win(data);
	return (0);
}

void	draw_win(t_data *data)
{
	if (data->fractal == 0)
		julia(data);
	else if (data->fractal == 1)
		mandelbrot(data);
}
