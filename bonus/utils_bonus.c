/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:01:39 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/09 10:50:14 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	free_vars(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->map.h)
	{
		free(vars->map.map[i]);
		i++;
	}
	free(vars->map.map);
	i = 0;
	while (i < vars->map.h)
	{
		free(vars->map.proj[i]);
		i++;
	}
	free(vars->map.proj);
}
