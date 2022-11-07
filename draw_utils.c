/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:07:20 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/07 11:04:53 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_pixel(t_data data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= 1920 || y < 0 || y >= 1080)
		return ;
	dst = data.addr + (y * data.line_length + x * (data.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_vars *vars, t_pixel start, t_pixel end)
{
	double	dx;
	double	dy;
	double	i;
	double	len;
	t_pixel	current;

	current = start;
	if (fabs(end.x - start.x) >= fabs(end.y - start.y))
		len = fabs(end.x - start.x);
	else
		len = fabs(end.y - start.y);
	if (len == 0)
		return ;
	dx = (end.x - start.x) / len;
	dy = (end.y - start.y) / len;
	current.x += 0.5;
	current.y += 0.5;
	i = 1;
	while (i <= len)
	{
		draw_pixel(vars->img, current.x, current.y,
			smouth_color(start, end, current));
		current.x += dx;
		current.y += dy;
		i++;
	}
}

void	draw_circle(t_vars *vars, t_pixel center, int radius, int width)
{
	int	x;
	int	y;
	int	dst;

	x = center.x - radius;
	while (x <= center.x + radius)
	{
		y = center.y - radius;
		while (y <= center.y + radius)
		{
			dst = sqrt(pow(x - center.x, 2) + pow(y - center.y, 2));
			if (dst <= radius && (width == 0 || dst > radius - width))
				draw_pixel(vars->img, x, y, center.color);
			y++;
		}
		x++;
	}
}
