/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:54:56 by aabda             #+#    #+#             */
/*   Updated: 2022/12/06 00:14:53 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_movement_y(char move, t_game *g)
{
	if (move == 'W')
	{
		g->player.pos_y--;
		g->map.map[g->player.pos_y][g->player.pos_x] = 'P';
		g->map.map[g->player.pos_y + 1][g->player.pos_x] = '0';
	}
	else if (move == 'S')
	{
		g->player.pos_y++;
		g->map.map[g->player.pos_y][g->player.pos_x] = 'P';
		g->map.map[g->player.pos_y - 1][g->player.pos_x] = '0';
	}
}

static void	ft_movement_x(char move, t_game *g)
{
	if (move == 'D')
	{
		g->player.pos_x++;
		g->map.map[g->player.pos_y][g->player.pos_x] = 'P';
		g->map.map[g->player.pos_y][g->player.pos_x - 1] = '0';
	}
	else if (move == 'A')
	{
		g->player.pos_x--;
		g->map.map[g->player.pos_y][g->player.pos_x] = 'P';
		g->map.map[g->player.pos_y][g->player.pos_x + 1] = '0';
	}
}

void	ft_movement(int keycode, t_game *g)
{
	if (keycode == KEY_ESC)
		exit (0);
	else if (g->map.map[g->player.pos_y - 1][g->player.pos_x] != '1'
			&& (keycode == KEY_W || keycode == KEY_UP))
		ft_movement_y('W', g);
	else if (g->map.map[g->player.pos_y + 1][g->player.pos_x] != '1'
			&& (keycode == KEY_S || keycode == KEY_DOWN))
		ft_movement_y('S', g);
	else if (g->map.map[g->player.pos_y][g->player.pos_x + 1] != '1'
			&& (keycode == KEY_D || keycode == KEY_RIGHT))
		ft_movement_x('D', g);
	else if (g->map.map[g->player.pos_y][g->player.pos_x - 1] != '1'
			&& (keycode == KEY_A || keycode == KEY_LEFT))
		ft_movement_x('A', g);
}
