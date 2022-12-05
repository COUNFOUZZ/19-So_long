/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:11:34 by aabda             #+#    #+#             */
/*   Updated: 2022/12/05 10:31:18 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error(int res, char *tab1, char **tab2, const char *error)
{
	if (res < 0)
	{
		if (tab1)
			ft_free_tab(tab1, NULL);
		if (tab2)
			ft_free_tab(NULL, tab2);
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(error, 2);
		exit(EXIT_FAILURE);
	}
}

void	ft_free_tab(char *tab1, char **tab2)
{
	int	i;

	i = -1;
	if (tab1)
		free(tab1);
	if (tab2)
	{
		while (tab2[++i])
			free(tab2[i]);
		free(tab2);
	}
}

void	init_struct(t_game *g)
{
	g->mlx = mlx_init();
	g->mlx_win = mlx_new_window(g->mlx, WIN_WIDTH, WIN_HEIGHT, GAME_TITLE);
	g->player.pos_x = 0;
	g->player.pos_y = 0;
	ft_init_lenline_nl(g);
	ft_parsing_map(g);
	g->check.nbr_coin = 0;
	g->check.nbr_player = 0;
	g->check.nbr_exit = 0;
	ft_check_map(g);
}

static void	ft_check_ber_map(const char *argv)
{
	int	ext_ber;

	ext_ber = ft_strlen(argv) - 4;
	if (argv[ext_ber] != '.' || argv[ext_ber + 1] != 'b'
		|| argv[ext_ber + 2] != 'e' || argv[ext_ber + 3] != 'r')
		ft_error(-1, NULL, NULL, ERR_BAD_EXT);
}

void	ft_path_map(const char *dir, const char *argv, t_game *g)
{
	int		i;
	int		j;

	if (!dir || !argv)
		return ;
	ft_check_ber_map(argv);
	i = -1;
	g->argv = malloc(sizeof(char) * ft_strlen(dir) + ft_strlen(argv) + 1);
	if (!g->argv)
		return ;
	while (dir[++i])
		g->argv[i] = dir[i];
	j = -1;
	while (argv[++j])
	{
		g->argv[i] = argv[j];
		i++;
	}
}


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
	int	move;

	move = 10;
	if (keycode == KEY_ESC)
		exit (0);
	else if (keycode == KEY_W || keycode == KEY_UP)
		g->player.pos_y = g->player.pos_y - move;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		g->player.pos_y = g->player.pos_y + move;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		g->player.pos_x = g->player.pos_x + move;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		g->player.pos_x = g->player.pos_x - move;
	ft_img(g, "./img/floor.xpm", &(g->img).img_width, &(g->img).img_height);
	mlx_clear_window(g->mlx, g->mlx_win);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.img, g->player.pos_x, g->player.pos_y);
	printf("\nKey pressed = [%d]\n", keycode);
	return (0);
}
