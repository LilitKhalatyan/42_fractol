/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalaty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:12:31 by lkhalaty          #+#    #+#             */
/*   Updated: 2021/10/10 17:12:38 by lkhalaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_itr(t_complex c, t_data *data)
{
	int			itr;
	t_complex	it;

	itr = 0;
	it.real = data->c_r;
	it.magic = data->c_m;
	while (ft_len(c) <= 4.0 && itr < data->max_it)
	{
		c = ft_square(c);
		c = ft_sum(c, it);
		itr++;
	}
	return (itr);
}

void	julia(t_data *data)
{
	int			x;
	int			y;
	int			itr;
	t_complex	c;

	x = 0;
	while (x < data->width)
	{
		y = 0;
		while (y < data->hight)
		{
			c.real = x / data->zoom + data->x1;
			c.magic = y / data->zoom + data->y1;
			itr = julia_itr(c, data);
			if (itr < data->max_it)
				my_mlx_pixel_put(data, x, y, COLOUR * itr * (2 - sin(itr)));
			else
				my_mlx_pixel_put(data, x, y, 0);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void	julia_init(t_data *data)
{
	data->fractal = 0;
	data->hight = 600;
	data->width = 800;
	data->max_it = 50;
	data->zoom = 200;
	data->x1 = -2.0;
	data->y1 = -1.9;
	data->c_r = 0.285;
	data->c_m = 0.01;
}
