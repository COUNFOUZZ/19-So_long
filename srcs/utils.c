/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:11:34 by aabda             #+#    #+#             */
/*   Updated: 2023/01/03 17:13:54 by aabda            ###   ########.fr       */
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
	ft_init_img(g);
	ft_init_lenline_nl(g);
	g->w_height = g->map.nl * 32;
	g->w_width = (g->map.lenline - 1) * 32;
	g->mlx_win = mlx_new_window(g->mlx, g->w_width, g->w_height, GAME_TITLE);
	g->player.pos_x = 0;
	g->player.pos_y = 0;
	g->player.coin_collected = 0;
	g->player.move = 0;
	ft_parsing_map(g);
	g->check.head = NULL;
	g->check.nbr_coin = 0;
	g->check.nbr_player = 0;
	g->check.nbr_exit = 0;
	g->check.exit_pos_x = 0;
	g->check.exit_pos_y = 0;
	ft_check_map(g);
}

void	ft_check_ber_map(const char *argv)
{
	int	ext_ber;

	ext_ber = ft_strlen(argv) - 4;
	if (argv[ext_ber] != '.' || argv[ext_ber + 1] != 'b'
		|| argv[ext_ber + 2] != 'e' || argv[ext_ber + 3] != 'r')
		ft_error(-1, NULL, NULL, ERR_BAD_EXT);
}

void	ft_path_map(const char *dir, char *argv, t_game *g)
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
