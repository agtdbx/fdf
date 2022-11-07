/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:08:56 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/07 13:58:11 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	calculate_projection(t_vars *vars)
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
			pt.x = (pt.x - vars->map_w / 2) * 20;
			pt.y = (pt.y - vars->map_h / 2) * 20;
			pt.z *= 2;
			vars->proj[y][x].x = (pt.x - pt.y) * cos(0.786);
			vars->proj[y][x].y = (pt.x + pt.y) * sin(0.7) - pt.z;
			vars->proj[y][x].x += vars->x;
			vars->proj[y][x].y += vars->y;
			vars->proj[y][x].color = create_rgb(255 + pt.z,
					255 + pt.z, 255 - pt.z);
			x++;
		}
		y++;
	}
}
