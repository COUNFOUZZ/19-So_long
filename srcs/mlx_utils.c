/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:45:25 by aabda             #+#    #+#             */
/*   Updated: 2022/12/05 21:46:31 by aabda            ###   ########.fr       */
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
	if (keycode == KEY_ESC)
		exit (0);
	else if (g->map.map[g->player.pos_y - 1][g->player.pos_x] != '1' && (keycode == KEY_W || keycode == KEY_UP))
	{
		g->player.pos_y--;
		g->map.map[g->player.pos_y][g->player.pos_x] = 'P';
		g->map.map[g->player.pos_y + 1][g->player.pos_x] = '0';
	}
	else if (g->map.map[g->player.pos_y + 1][g->player.pos_x] != '1' && (keycode == KEY_S || keycode == KEY_DOWN))
	{
		g->player.pos_y++;
		g->map.map[g->player.pos_y][g->player.pos_x] = 'P';
		g->map.map[g->player.pos_y - 1][g->player.pos_x] = '0';
	}
	else if (g->map.map[g->player.pos_y][g->player.pos_x + 1] != '1' && (keycode == KEY_D || keycode == KEY_RIGHT))
	{
		g->player.pos_x++;
		g->map.map[g->player.pos_y][g->player.pos_x] = 'P';
		g->map.map[g->player.pos_y][g->player.pos_x - 1] = '0';
	}
	else if (g->map.map[g->player.pos_y][g->player.pos_x - 1] != '1' && (keycode == KEY_A || keycode == KEY_LEFT))
	{
		g->player.pos_x--;
		g->map.map[g->player.pos_y][g->player.pos_x] = 'P';
		g->map.map[g->player.pos_y][g->player.pos_x + 1] = '0';
	}
	system("clear");
	ft_print_map1(g);
	ft_img(g, "./img/floor.xpm", &(g->img).img_width, &(g->img).img_height);
	mlx_clear_window(g->mlx, g->mlx_win);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.img, g->player.pos_x, g->player.pos_y);
	printf("\nKey pressed = [%d]\n", keycode);
	return (0);
}
