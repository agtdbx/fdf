/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_render_fast_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 08:24:29 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/14 14:57:20 by aderouba         ###   ########.fr       */
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
		while (x >= 0)
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
	while (y >= 0)
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
	while (y >= 0)
	{
		x = vars->map.w - 1;
		while (x >= 0)
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
