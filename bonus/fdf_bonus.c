/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:21:15 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/09 13:32:57 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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
	else
		key_iso(keycode, vars);
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (mousecode == 4)
		zoom_iso(vars, 1.1);
	if (mousecode == 5)
		zoom_iso(vars, 1.0 / 1.1);
	return (0);
}

// render function
int	render(t_vars *vars)
{
	draw_render_iso(vars);
	return (0);
}

// main
int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		return (1);
	vars = get_map_from_agr(&vars, argv);
	init_map_iso(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "FDF");
	vars.img.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	mlx_hook(vars.win, DestroyNotify, StructureNotifyMask, mlx_close, &vars);
	mlx_hook(vars.win, 2, 1L, &key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop_hook(vars.mlx, render, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
