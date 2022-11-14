/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderouba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:37:43 by aderouba          #+#    #+#             */
/*   Updated: 2022/11/11 14:24:26 by aderouba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	draw_menu_iso(t_vars *vars, int text_color)
{
	mlx_string_put(vars->mlx, vars->win, 75, 50, text_color, "ISO MODE");
	mlx_string_put(vars->mlx, vars->win, 20, 75, text_color,
		"MOVE UP     -> W or UP");
	mlx_string_put(vars->mlx, vars->win, 20, 100, text_color,
		"MOVE DOWN   -> S or DOWN");
	mlx_string_put(vars->mlx, vars->win, 20, 125, text_color,
		"MOVE LEFT   -> A or LEFT");
	mlx_string_put(vars->mlx, vars->win, 20, 150, text_color,
		"MOVE RIGHT  -> D or RIGHT");
	mlx_string_put(vars->mlx, vars->win, 20, 175, text_color,
		"ROTATE X    -> U or I");
	mlx_string_put(vars->mlx, vars->win, 20, 200, text_color,
		"ROTATE Y    -> J or K");
	mlx_string_put(vars->mlx, vars->win, 20, 225, text_color,
		"ROTATE Z    -> N or M");
	mlx_string_put(vars->mlx, vars->win, 20, 250, text_color,
		"AUTO ROTATE -> P");
	mlx_string_put(vars->mlx, vars->win, 20, 275, text_color,
		"FPS MODE    -> SPACE");
}

void	draw_menu_fps(t_vars *vars, int text_color)
{
	mlx_string_put(vars->mlx, vars->win, 75, 50, text_color, "FPS MODE");
	mlx_string_put(vars->mlx, vars->win, 20, 75, text_color,
		"MOVE FRONT  -> W");
	mlx_string_put(vars->mlx, vars->win, 20, 100, text_color,
		"MOVE BACK   -> S");
	mlx_string_put(vars->mlx, vars->win, 20, 125, text_color,
		"MOVE LEFT   -> A");
	mlx_string_put(vars->mlx, vars->win, 20, 150, text_color,
		"MOVE RIGHT  -> D");
	mlx_string_put(vars->mlx, vars->win, 20, 175, text_color,
		"LOOK UP     -> UP");
	mlx_string_put(vars->mlx, vars->win, 20, 200, text_color,
		"LOOK DOWN   -> DOWN");
	mlx_string_put(vars->mlx, vars->win, 20, 225, text_color,
		"LOOK LEFT   -> LEFT");
	mlx_string_put(vars->mlx, vars->win, 20, 250, text_color,
		"LOOK RIGHT  -> RIGHT");
	mlx_string_put(vars->mlx, vars->win, 20, 275, text_color,
		"ISO MODE    -> SPACE");
}

void	draw_always(t_vars *vars, int text_color)
{
	mlx_string_put(vars->mlx, vars->win, 20, 300, text_color,
		"RESET       -> R");
	if (vars->draw_fast)
		mlx_string_put(vars->mlx, vars->win, 20, 325, text_color,
			"DRAW EXACT  -> F");
	else
		mlx_string_put(vars->mlx, vars->win, 20, 325, text_color,
			"DRAW FAST   -> F");
	mlx_string_put(vars->mlx, vars->win, 20, 350, text_color,
		"CLOSE MENU  -> TAB");
	mlx_string_put(vars->mlx, vars->win, 20, 375, text_color,
		"EXIT        -> ESCAPE");
}

void	draw_menu(t_vars *vars)
{
	t_pixel	pos;
	int		text_color;

	pos.x = 5;
	pos.y = 5;
	pos.color = create_rgb(30, 30, 30);
	draw_rect(vars, pos, 200, 400);
	pos.x = 10;
	pos.y = 10;
	pos.color = create_rgb(50, 50, 50);
	draw_rect(vars, pos, 190, 390);
	text_color = create_rgb(200, 200, 200);
	mlx_string_put(vars->mlx, vars->win, 90, 25, text_color, "MENU");
	if (vars->projection_mode == 0)
		draw_menu_iso(vars, text_color);
	else
		draw_menu_fps(vars, text_color);
	draw_always(vars, text_color);
}
