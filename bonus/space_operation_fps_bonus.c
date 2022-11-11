/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_operation_fps_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:01:40 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/10 12:08:52 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	translate_fps(t_vars *vars, double x, double y)
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
	calculate_projection_fps(vars);
	vars->map.redraw = 1;
}
