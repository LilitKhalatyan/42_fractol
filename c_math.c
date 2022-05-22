/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_math.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalaty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:13:34 by lkhalaty          #+#    #+#             */
/*   Updated: 2021/10/10 17:13:37 by lkhalaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	ft_sum(t_complex a, t_complex b)
{
	t_complex	sum;

	sum.real = a.real + b.real;
	sum.magic = a.magic + b.magic;
	return (sum);
}

t_complex	ft_square(t_complex a)
{
	t_complex	square;

	square.real = a.real * a.real - a.magic * a.magic;
	square.magic = 2 * a.real * a.magic;
	return (square);
}

double	ft_len(t_complex x)
{
	double	len;

	len = x.real * x.real + x.magic * x.magic;
	return (len);
}
