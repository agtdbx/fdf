/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:08:56 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/09 15:07:13 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	calculate_projection(t_vars *vars)
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
			pt.x = (pt.x - vars->map.w / 2) * vars->map.zoom;
			pt.y = (pt.y - vars->map.h / 2) * vars->map.zoom;
			pt.z *= vars->map.zoom / 10.0;
			vars->map.proj[y][x].x = (pt.x - pt.y);
			vars->map.proj[y][x].y = (pt.x + pt.y) * sin(0.8) - pt.z;
			vars->map.proj[y][x].x += vars->map.x;
			vars->map.proj[y][x].y += vars->map.y;
			vars->map.proj[y][x].color = create_rgb(255 + pt.z,
					255 + pt.z, 255 - pt.z);
			x++;
		}
		y++;
	}
}
