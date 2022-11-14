/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:21:15 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/14 10:55:50 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	mlx_close(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free_vars(vars);
	free(vars->mlx);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		mlx_close(vars);
	else if (keycode == XK_Tab)
	{
		vars->draw_menu = !vars->draw_menu;
		vars->map.redraw = 1;
	}
	else if (keycode == 32)
	{
		vars->projection_mode = !vars->projection_mode;
		if (vars->projection_mode == 0)
			reset_iso(vars);
		else
			reset_fps(vars);
	}
	else if (keycode == XK_f)
	{
		vars->draw_fast = !vars->draw_fast;
		vars->map.redraw = 1;
	}
	else if (vars->projection_mode == 0)
		key_iso(keycode, vars);
	else
		key_fps(keycode, vars);
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (vars->projection_mode == 0)
	{
		if (mousecode == 4)
			zoom_iso(vars, 1.1);
		else if (mousecode == 5)
			zoom_iso(vars, 1.0 / 1.1);
	}
	return (0);
}

int	render(t_vars *vars)
{
	t_pixel	p;

	if (vars->map.autorotation && vars->projection_mode == 0)
		rotate_iso(vars, 1.0, 'z');
	if (vars->map.redraw)
	{
		p.x = 0;
		p.y = 0;
		p.color = 0;
		vars->map.redraw = 0;
		draw_rect(vars, p, 1920, 1080);
		if (vars->draw_fast)
			draw_render_fast(vars);
		else
			draw_render_exact(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
		if (vars->draw_menu)
			draw_menu(vars);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		return (1);
	vars = get_map_from_agr(&vars, argv);
	vars.draw_menu = 0;
	vars.projection_mode = 0;
	vars.draw_fast = 1;
	vars.map.proj = NULL;
	vars.map.alt = 1.0;
	init_map_iso(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "FDF");
	vars.img.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	mlx_hook(vars.win, DestroyNotify, StructureNotifyMask, mlx_close, &vars);
	mlx_hook(vars.win, KeyPress, KeyPressMask, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop_hook(vars.mlx, render, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
