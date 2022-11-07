/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:01:39 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/07 14:01:48 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_vars(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->map_h)
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
	i = 0;
	while (i < vars->map_h)
	{
		free(vars->proj[i]);
		i++;
	}
	free(vars->proj);
}
