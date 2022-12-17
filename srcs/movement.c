/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:54:56 by aabda             #+#    #+#             */
/*   Updated: 2022/12/17 16:43:50 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_save_last_pos(char key, t_game *g)
{
	if (key == 'W')
	{
		if (g->map.map[g->player.pos_y - 1][g->player.pos_x])
			g->player.char_staged = '0';
		if (g->map.map[g->player.pos_y][g->player.pos_x] == g->map.map[g->check.exit_pos_y][g->check.exit_pos_x])
			g->player.char_staged = 'E';
	}
	else if (key == 'S')
	{
		if (g->map.map[g->player.pos_y - 1][g->player.pos_x])
			g->player.char_staged = '0';
		if (g->map.map[g->player.pos_y][g->player.pos_x] == g->map.map[g->check.exit_pos_y][g->check.exit_pos_x])
			g->player.char_staged = 'E';
	}
	else if (key == 'D')
	{
		if (g->map.map[g->player.pos_y][g->player.pos_x + 1])
			g->player.char_staged = '0';
		if (g->map.map[g->player.pos_y][g->player.pos_x] == g->map.map[g->check.exit_pos_y][g->check.exit_pos_x])
			g->player.char_staged = 'E';
	}
	else if (key == 'A')
	{
		if (g->map.map[g->player.pos_y][g->player.pos_x - 1])
			g->player.char_staged = '0';
		if (g->map.map[g->player.pos_y][g->player.pos_x] == g->map.map[g->check.exit_pos_y][g->check.exit_pos_x])
			g->player.char_staged = 'E';
	}
}

static void	ft_exit_and_coin_collect(t_game *g)
{
	if (g->map.map[g->player.pos_y][g->player.pos_x] == 'E'
	&& g->check.nbr_coin == g->player.coin_collected)
	{
		ft_free_tab(NULL, g->map.map);
		exit(EXIT_SUCCESS);
	}
	else if (g->map.map[g->player.pos_y][g->player.pos_x] == 'C')
			g->player.coin_collected++;
}

static void	ft_movement_y(char key, t_game *g)
{
	if (key == 'W')
	{
		ft_save_last_pos('W', g);
		g->player.pos_y--;
		ft_exit_and_coin_collect(g);
		g->map.map[g->player.pos_y][g->player.pos_x] = 'P';
		g->map.map[g->player.pos_y + 1][g->player.pos_x] = g->player.char_staged;
		g->player.move++;
	}
	else if (key == 'S')
	{
		ft_save_last_pos('S', g);
		g->player.pos_y++;
		ft_exit_and_coin_collect(g);
		g->map.map[g->player.pos_y][g->player.pos_x] = 'P';
		g->map.map[g->player.pos_y - 1][g->player.pos_x] = g->player.char_staged;
		g->player.move++;
	}
}

static void	ft_movement_x(char key, t_game *g)
{
	if (key == 'D')
	{
		ft_save_last_pos('D', g);
		g->player.pos_x++;
		ft_exit_and_coin_collect(g);
		g->map.map[g->player.pos_y][g->player.pos_x] = 'P';
		g->map.map[g->player.pos_y][g->player.pos_x - 1] = g->player.char_staged;
		g->player.move++;
	}
	else if (key == 'A')
	{
		ft_save_last_pos('A', g);
		g->player.pos_x--;
		ft_exit_and_coin_collect(g);
		g->map.map[g->player.pos_y][g->player.pos_x] = 'P';
		g->map.map[g->player.pos_y][g->player.pos_x + 1] = g->player.char_staged;
		g->player.move++;
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
