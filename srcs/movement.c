/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:54:56 by aabda             #+#    #+#             */
/*   Updated: 2023/01/12 22:01:29 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_exit_and_coin_collect(t_game *g)
{
	if (g->map.map[g->player.pos_y][g->player.pos_x] == 'C')
			g->player.coin_collected++;
	else if (g->map.map[g->player.pos_y][g->player.pos_x] == 'E'
	&& g->check.nbr_coin == g->player.coin_collected)
	{
		ft_free_tab(NULL, g->map.map);
		ft_destroy_all_img(g);
		exit(EXIT_SUCCESS);
	}
}

static void	ft_movement_y(char key, t_game *g)
{
	if (key == 'W')
	{
		g->player.pos_y--;
		g->player.move++;
		ft_exit_and_coin_collect(g);
		g->map.map[g->player.pos_y][g->player.pos_x] = 'P';
		g->map.map[g->player.pos_y + 1][g->player.pos_x] = \
		g->player.char_staged;
	}
	else if (key == 'S')
	{
		g->player.pos_y++;
		g->player.move++;
		ft_exit_and_coin_collect(g);
		g->map.map[g->player.pos_y][g->player.pos_x] = 'P';
		g->map.map[g->player.pos_y - 1][g->player.pos_x] = \
		g->player.char_staged;
	}
}

static void	ft_movement_x(char key, t_game *g)
{
	if (key == 'D')
	{
		g->player.pos_x++;
		g->player.move++;
		ft_exit_and_coin_collect(g);
		g->map.map[g->player.pos_y][g->player.pos_x] = 'P';
		g->map.map[g->player.pos_y][g->player.pos_x - 1] = \
		g->player.char_staged;
	}
	else if (key == 'A')
	{
		g->player.pos_x--;
		g->player.move++;
		ft_exit_and_coin_collect(g);
		g->map.map[g->player.pos_y][g->player.pos_x] = 'P';
		g->map.map[g->player.pos_y][g->player.pos_x + 1] = \
		g->player.char_staged;
	}
}

void	ft_movement(int keycode, t_game *g)
{
	if (g->player.move >= INT_MAX)
		g->player.move = 0;
	g->player.char_staged = '0';
	if (g->map.map[g->player.pos_y][g->player.pos_x] ==
		g->map.map[g->check.exit_pos_y][g->check.exit_pos_x])
			g->player.char_staged = 'E';
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
