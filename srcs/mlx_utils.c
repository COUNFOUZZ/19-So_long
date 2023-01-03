/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:45:25 by aabda             #+#    #+#             */
/*   Updated: 2023/01/03 17:49:51 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	red_cross(void)
{
	exit(0);
	return (0);
}

int	key_pressed(int keycode, t_game *g)
{
	mlx_clear_window(g->mlx, g->mlx_win);
	ft_movement(keycode, g);
	ft_put_img_map(g);
	system("clear");
	ft_print_map1(g);
	printf("Coin collected : " YELLOW "%d\n" NORMAL, g->player.coin_collected);
	printf("Nbr_move : %d\n", g->player.move);
	return (0);
}
