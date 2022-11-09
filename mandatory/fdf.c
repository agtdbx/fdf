/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:21:15 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/09 10:36:55 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// close function
int	mlx_close(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free_vars(vars);
	free(vars->mlx);
	exit(0);
}

// inputs functions
int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		mlx_close(vars);
	return (0);
}

// render function
int	render(t_vars *vars)
{
	int	x;
	int	y;

	if (vars->map.redraw)
	{
		clear_screen(vars);
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
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	}
	return (0);
}

// main
int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		return (1);
	vars = get_map_from_agr(&vars, argv);
	vars.map.x = 1920 / 2;
	vars.map.y = 1080 / 2;
	vars.map.zoom = 20.0;
	vars.map.redraw = 1;
	init_proj(&vars);
	calculate_projection(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "FDF");
	vars.img.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	mlx_hook(vars.win, DestroyNotify, StructureNotifyMask, mlx_close, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop_hook(vars.mlx, render, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
