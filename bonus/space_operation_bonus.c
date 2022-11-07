/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_operation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:37:56 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/07 16:37:52 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate(t_vars *vars, double x, double y)
{
	int	i;
	int	j;

	vars->x += x;
	vars->y += y;
	i = 0;
	while (i < vars->map_h)
	{
		j = 0;
		while (j < vars->map_w)
		{
			vars->proj[i][j].x += x;
			vars->proj[i][j].y += y;
			j++;
		}
		i++;
	}
	vars->redraw = 1;
}

void	zoom(t_vars *vars, double zoom, int x, int y)
{
	int		i;
	int		j;
	double	tmp_x;
	double	tmp_y;

	x = 1920 / 2 - x;
	y = 1080 / 2 - y;
	tmp_x = vars->x;
	tmp_y = vars->y;
	translate(vars, -tmp_x, -tmp_y);
	translate(vars, x, y);
	i = 0;
	while (i < vars->map_h)
	{
		j = 0;
		while (j < vars->map_w)
		{
			vars->proj[i][j].x /= vars->zoom;
			vars->proj[i][j].x *= vars->zoom + zoom;
			vars->proj[i][j].y /= vars->zoom;
			vars->proj[i][j].y *= vars->zoom + zoom;
			j++;
		}
		i++;
	}
	vars->zoom += zoom;
	translate(vars, -x, -y);
	translate(vars, tmp_x, tmp_y);
	vars->redraw = 1;
}
