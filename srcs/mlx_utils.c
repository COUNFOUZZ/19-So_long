/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:45:25 by aabda             #+#    #+#             */
/*   Updated: 2023/01/04 15:45:23 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_print_step(t_game *g, int start)
{
	if (g->w_width <= 288)
	{
		mlx_string_put(g->mlx, g->mlx_win, start, 15, 0xFFFFFF, "S:");
		mlx_string_put(g->mlx, g->mlx_win, start + 15, 15, 0x00FF00, ft_itoa(g->player.move));
	}
	else
	{
		if (g->player.move <= 1)
		{
			mlx_string_put(g->mlx, g->mlx_win, start, 15, 0xFFFFFF, "Step :");
			mlx_string_put(g->mlx, g->mlx_win, start + 50, 15, 0x00FF00, ft_itoa(g->player.move));
		}
		else
		{
			mlx_string_put(g->mlx, g->mlx_win, start, 15, 0xFFFFFF, "Steps :");
			mlx_string_put(g->mlx, g->mlx_win, start + 50, 15, 0x00FF00, ft_itoa(g->player.move));
		}
	}
}

static void	ft_print_coin_collected(t_game *g, int mid)
{
	if (g->w_width <= 288)
	{
		mlx_string_put(g->mlx, g->mlx_win, g->w_width / 2, 15, 0xFFFFFF, "C:");
		mlx_string_put(g->mlx, g->mlx_win, (g->w_width / 2) + 15, 15, 0xFFFF00, ft_itoa(g->player.coin_collected));
	}
	else
	{
		if (g->player.coin_collected <= 1)
		{
			mlx_string_put(g->mlx, g->mlx_win, mid, 15, 0xFFFFFF, "Coin collected :");
			mlx_string_put(g->mlx, g->mlx_win, mid + 120, 15, 0xFFFF00, ft_itoa(g->player.coin_collected));
		}
		else
		{
			mlx_string_put(g->mlx, g->mlx_win, mid, 15, 0xFFFFFF, "Coins collected :");
			mlx_string_put(g->mlx, g->mlx_win, mid + 125, 15, 0xFFFF00, ft_itoa(g->player.coin_collected));
		}
	}
}

void	ft_print_infos(t_game *g)
{
	int	start;
	int	mid;

	start = (g->w_width / g->w_width) + 4;
	mid = (g->w_width / 2) - 60;
	ft_print_step(g, start);
	ft_print_coin_collected(g, mid);
}

int	red_cross(void)
{
	exit(0);
	return (0);
}

int	key_pressed(int keycode, t_game *g)
{
	mlx_clear_window(g->mlx, g->mlx_win);
	ft_movement(keycode, g);
	ft_print_infos(g);
	ft_put_img_map(g);
	system("clear");
	ft_print_map1(g);
	printf("Coin collected : " YELLOW "%d\n" NORMAL, g->player.coin_collected);
	printf("Nbr_move : %d\n", g->player.move);
	return (0);
}
