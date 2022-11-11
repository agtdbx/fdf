/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_render_fast_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 08:24:29 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/11 08:47:20 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	draw_render_fast_00hw(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->map.h)
	{
		x = 0;
		while (x < vars->map.w)
		{
			if (x < vars->map.w - 1)
				draw_line(vars, vars->map.proj[y][x],
					vars->map.proj[y][x + 1]);
			if (y < vars->map.h - 1)
				draw_line(vars, vars->map.proj[y][x],
					vars->map.proj[y + 1][x]);
			x++;
		}
		y++;
	}
}

void	draw_render_fast_0wh0(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->map.h)
	{
		x = vars->map.w - 1;
		while (x > 0)
		{
			if (x > 0)
				draw_line(vars, vars->map.proj[y][x],
					vars->map.proj[y][x - 1]);
			if (y < vars->map.h - 1)
				draw_line(vars, vars->map.proj[y][x],
					vars->map.proj[y + 1][x]);
			x--;
		}
		y++;
	}
}

void	draw_render_fast_h00w(t_vars *vars)
{
	int	x;
	int	y;

	y = vars->map.h - 1;
	while (y > 0)
	{
		x = 0;
		while (x < vars->map.w)
		{
			if (x < vars->map.w - 1)
				draw_line(vars, vars->map.proj[y][x],
					vars->map.proj[y][x + 1]);
			if (y > 0)
				draw_line(vars, vars->map.proj[y][x],
					vars->map.proj[y - 1][x]);
			x++;
		}
		y--;
	}
}

void	draw_render_fast_hw00(t_vars *vars)
{
	int	x;
	int	y;

	y = vars->map.h - 1;
	while (y > 0)
	{
		x = vars->map.w - 1;
		while (x > 0)
		{
			if (x > 0)
				draw_line(vars, vars->map.proj[y][x],
					vars->map.proj[y][x - 1]);
			if (y > 0)
				draw_line(vars, vars->map.proj[y][x],
					vars->map.proj[y - 1][x]);
			x--;
		}
		y--;
	}
}

void	draw_render_fast(t_vars *vars)
{
	int	y00;
	int	y0w;
	int	yh0;
	int	yhw;

	y00 = vars->map.proj[0][0].y;
	y0w = vars->map.proj[0][vars->map.w - 1].y;
	yh0 = vars->map.proj[vars->map.h - 1][0].y;
	yhw = vars->map.proj[vars->map.h - 1][vars->map.w - 1].y;
	if (y00 <= yhw && yh0 <= y0w)
		draw_render_fast_00hw(vars);
	else if (y00 <= yhw && yh0 > y0w)
		draw_render_fast_0wh0(vars);
	else if (y00 > yhw && yh0 <= y0w)
		draw_render_fast_h00w(vars);
	else if (y00 > yhw && yh0 > y0w)
		draw_render_fast_hw00(vars);
}
