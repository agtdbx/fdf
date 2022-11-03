/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:21:15 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/03 17:36:28 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

// close function
int	mlx_close(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

// inputs functions
int	event_hook(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		mlx_close(vars);
	ft_printf("Keycode : %i\n", keycode);
	return (0);
}

// render function
int	render(t_vars *vars)
{
	t_pixel	start = {1920/2, 1080/2, create_rgb(255, 192, 203)};
	//t_pos	end = {200, 200};

	//draw_line(vars, start, end);
	draw_circle(vars, start, 100, 10);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

// main
int	main(void)
{
	t_vars	vars;

	// init mlx
	vars.mlx = mlx_init();
	// create window (width, height, name)
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "FDF");
	// create image
	vars.img.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
		&vars.img.line_length, &vars.img.endian);
	// set input functions
	mlx_hook(vars.win, DestroyNotify, StructureNotifyMask, mlx_close, &vars);
	mlx_key_hook(vars.win, event_hook, &vars);
	mlx_mouse_hook(vars.win, event_hook, &vars);
	// set render function
	mlx_loop_hook(vars.mlx, render, &vars);
	// start mlx loop
	mlx_loop(vars.mlx);

	return (0);
}
