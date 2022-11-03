/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:07:20 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/03 17:34:15 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_pixel(t_data data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= 1920 || y < 0 || y >= 1080)
		return ;
	dst = data.addr + (y * data.line_length + x * (data.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_line(t_vars *vars, t_pixel start, t_pixel end)
{
	int	dx;
	int	dy;
	int	i;
	int	len;

	if (abs(end.x - start.x) >= abs(end.y - start.y))
		len = abs(end.x - start.x);
	else
		len = abs(end.y - start.y);
	dx = (end.x - start.x) / len;
	dy = (end.y - start.y) / len;
	start.x += 0.5;
	start.y += 0.5;
	i = 1;
	while (i <= len)
	{
		draw_pixel(vars->img, start.x, start.y, 255);
		start.x += dx;
		start.y += dy;
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
