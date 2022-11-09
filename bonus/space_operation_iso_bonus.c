/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_operation_iso_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:37:56 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/09 16:12:02 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	first_translate_iso(t_vars *vars, double x, double y)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->map.h)
	{
		j = 0;
		while (j < vars->map.w)
		{
			vars->map.map[i][j].x += x;
			vars->map.map[i][j].y += y;
			j++;
		}
		i++;
	}
	calculate_projection_iso(vars);
	vars->map.redraw = 1;
}

void	translate_iso(t_vars *vars, double x, double y)
{
	int	i;
	int	j;

	vars->map.x += x;
	vars->map.y += y;
	i = -1;
	while (++i < vars->map.h)
	{
		j = -1;
		while (++j < vars->map.w)
		{
			if (x != 0.0)
			{
				vars->map.map[i][j].x += x;
				vars->map.map[i][j].y -= x;
			}
			if (y != 0.0)
			{
				vars->map.map[i][j].x += y;
				vars->map.map[i][j].y += y;
			}
		}
	}
	calculate_projection_iso(vars);
	vars->map.redraw = 1;
}

void	first_zoom(t_vars *vars)
{
	int		i;
	int		j;
	double	zoooooooooom;

	zoooooooooom = 1080.0 / vars->map.w;
	i = 0;
	while (i < vars->map.h)
	{
		j = 0;
		while (j < vars->map.w)
		{
			vars->map.map[i][j].x *= zoooooooooom;
			vars->map.map[i][j].y *= zoooooooooom;
			vars->map.map[i][j].z *= zoooooooooom / 10;
			j++;
		}
		i++;
	}
	vars->map.zoom = zoooooooooom;
}

void	zoom_iso(t_vars *vars, double zoom)
{
	int		i;
	int		j;
	double	tmp_x;
	double	tmp_y;

	tmp_x = vars->map.x;
	tmp_y = vars->map.y;
	translate_iso(vars, -tmp_x, -tmp_y);
	i = 0;
	while (i < vars->map.h)
	{
		j = 0;
		while (j < vars->map.w)
		{
			vars->map.map[i][j].x *= zoom;
			vars->map.map[i][j].y *= zoom;
			vars->map.map[i][j].z *= zoom;
			j++;
		}
		i++;
	}
	translate_iso(vars, tmp_x, tmp_y);
	calculate_projection_iso(vars);
	vars->map.zoom *= zoom;
	vars->map.redraw = 1;
}
