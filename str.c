/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalaty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:13:18 by lkhalaty          #+#    #+#             */
/*   Updated: 2021/10/10 17:13:22 by lkhalaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_str_compare(char *s1, char *s2)
{
	int	len;
	int	i;

	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	len = ft_strlen(s1);
	i = 0;
	while (len > 0)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
		len--;
	}
	return (1);
}
