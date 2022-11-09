/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:42:22 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/09 10:49:37 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	combine_color(int color1, int color2, float percent1, float percent2)
{
	t_color	c;
	t_color	c1;
	t_color	c2;
	int		a;

	a = color1 >> 24;
	color1 -= (a << 24);
	c1.r = color1 >> 16;
	color1 -= (c1.r << 16);
	c1.g = color1 >> 8;
	color1 -= (c1.g << 8);
	c1.b = color1;
	a = color2 >> 24;
	color2 -= (a << 24);
	c2.r = color2 >> 16;
	color2 -= (c2.r << 16);
	c2.g = color2 >> 8;
	color2 -= (c2.g << 8);
	c2.b = color2;
	c.r = (int)(c1.r * percent1) + (int)(c2.r * percent2);
	c.g = (int)(c1.g * percent1) + (int)(c2.g * percent2);
	c.b = (int)(c1.b * percent1) + (int)(c2.b * percent2);
	return (create_rgb(c.r, c.g, c.b));
}

int	smouth_color(t_pixel start, t_pixel end, t_pixel current)
{
	float	dist_max;
	float	dist_start;
	float	dist_end;
	float	percent_start;
	float	percent_end;

	dist_start = sqrt(pow(current.x - start.x, 2)
			+ pow(current.y - start.y, 2));
	dist_end = sqrt(pow(current.x - end.x, 2) + pow(current.y - end.y, 2));
	dist_max = dist_start + dist_end;
	percent_start = dist_end / dist_max;
	percent_end = dist_start / dist_max;
	return (combine_color(start.color, end.color, percent_start, percent_end));
}
