/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:07:20 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/11 08:47:37 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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
	i = 0;
	while (++i <= len)
	{
		draw_pixel(vars->img, current.x, current.y,
			smouth_color(start, end, current));
		current.x += dx;
		current.y += dy;
	}
}

void	draw_rect(t_vars *vars, t_pixel pos, int width, int height)
{
	t_pixel	pa;
	t_pixel	pb;
	int		y;

	y = 0;
	pa.x = pos.x;
	pa.color = pos.color;
	pb.x = pos.x + width;
	pb.color = pos.color;
	while (y < height)
	{
		pa.y = pos.y + y;
		pb.y = pos.y + y;
		draw_line(vars, pa, pb);
		y++;
	}
}

void	draw_part_polygon(t_vars *vars, t_pixel origin,
	t_pixel start, t_pixel end)
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
	i = 0;
	while (++i <= len)
	{
		draw_line(vars, origin, current);
		current.x += dx;
		current.y += dy;
	}
}

void	draw_polygon(t_vars *vars, t_pixel *lst, int nb_point, int color)
{
	int		i;
	t_pixel	origin;

	origin = lst[0];
	origin.color = color;
	i = 1;
	while (i < nb_point)
	{
		lst[i - 1].color = color;
		lst[i].color = color;
		draw_part_polygon(vars, origin, lst[i - 1], lst[i]);
		i++;
	}
	draw_line(vars, origin, lst[i - 1]);
}
