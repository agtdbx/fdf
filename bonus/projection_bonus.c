/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:08:56 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/14 10:38:16 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	init_proj(t_vars *vars)
{
	int	x;
	int	y;

	vars->map.proj = malloc(sizeof(t_pixel *) * vars->map.h);
	if (vars->map.proj == NULL)
		return ;
	y = 0;
	while (y < vars->map.h)
	{
		vars->map.proj[y] = malloc(sizeof(t_pixel) * vars->map.w);
		if (vars->map.proj[y] == NULL)
		{
			free_vars(vars);
			exit(0);
		}
		x = 0;
		while (x < vars->map.w)
		{
			vars->map.proj[y][x].x = x * 10;
			vars->map.proj[y][x].y = y * 10;
			vars->map.proj[y][x].color = 255;
			x++;
		}
		y++;
	}
}

void	calculate_projection_iso(t_vars *vars)
{
	int		x;
	int		y;
	t_point	pt;

	y = 0;
	while (y < vars->map.h)
	{
		x = 0;
		while (x < vars->map.w)
		{
			pt = vars->map.map[y][x];
			vars->map.proj[y][x].x = (pt.x - pt.y);
			vars->map.proj[y][x].y = (pt.x + pt.y) * SIN8 - pt.z;
			vars->map.proj[y][x].color = pt.color;
			x++;
		}
		y++;
	}
}

void	calculate_projection_fps(t_vars *vars)
{
	int		x;
	int		y;
	t_point	pt;

	y = 0;
	while (y < vars->map.h)
	{
		x = 0;
		while (x < vars->map.w)
		{
			pt = vars->map.map[y][x];
			vars->map.proj[y][x].x = pt.x;
			vars->map.proj[y][x].y = vars->map.y - pt.z;
			vars->map.proj[y][x].color = pt.color;
			x++;
		}
		y++;
	}
}
