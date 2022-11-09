/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:08:56 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/09 09:55:11 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	init_proj(t_vars *vars)
{
	int	x;
	int	y;

	vars->proj = malloc(sizeof(t_pixel *) * vars->map_h);
	if (vars->proj == NULL)
		return ;
	y = 0;
	while (y < vars->map_h)
	{
		vars->proj[y] = malloc(sizeof(t_pixel) * vars->map_w);
		if (vars->proj[y] == NULL)
		{
			free_vars(vars);
			exit(0);
		}
		x = 0;
		while (x < vars->map_w)
		{
			vars->proj[y][x].x = x * 10;
			vars->proj[y][x].y = y * 10;
			vars->proj[y][x].color = 255;
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
	while (y < vars->map_h)
	{
		x = 0;
		while (x < vars->map_w)
		{
			pt = vars->map[y][x];
			vars->proj[y][x].x = (pt.x - pt.y);
			vars->proj[y][x].y = (pt.x + pt.y) * sin(0.8) - pt.z;
			vars->proj[y][x].color = pt.color;
			x++;
		}
		y++;
	}
}
