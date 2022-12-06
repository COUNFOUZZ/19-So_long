/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:45:25 by aabda             #+#    #+#             */
/*   Updated: 2022/12/06 11:53:31 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	red_cross(void)
{
	exit(0);
	return (0);
}

void	ft_img(t_game *g, char *path, int *width, int *height)
{
	g->img.path = path;
	g->img.img = mlx_xpm_file_to_image(g->mlx, g->img.path,
			width, height);
}

int	key_pressed(int keycode, t_game *g)
{
	ft_movement(keycode, g);
	system("clear");
	ft_print_map1(g);
	printf("coin collected : %d\n", g->player.coin_collected);
	ft_img(g, "./img/floor.xpm", &(g->img).img_width, &(g->img).img_height);
	mlx_clear_window(g->mlx, g->mlx_win);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.img, g->player.pos_x, g->player.pos_y);
	printf("\nKey pressed = [%d]\n", keycode);
	return (0);
}
