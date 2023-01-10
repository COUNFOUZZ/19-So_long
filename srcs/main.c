/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:31:17 by aabda             #+#    #+#             */
/*   Updated: 2023/01/10 15:15:43 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_parse_argv(t_game *g, char *argv)
{
	if (ft_strncmp("maps/", argv, 5) == 0)
	{
		g->argv_malloc = 0;
		g->argv = argv;
		ft_check_ber_map(g->argv);
	}
	else
	{
		g->argv_malloc = 1;
		ft_path_map("maps/", argv, g);
	}
}

int	main(int argc, const char **argv)
{
	t_game	g;

	if (argc == 2)
	{
		ft_parse_argv(&g, (char *)argv[1]);
		init_struct(&g);
		ft_print_infos(&g);
		ft_put_img_map(&g);
		mlx_hook(g.mlx_win, 17, 0, &red_cross, &g);
		mlx_hook(g.mlx_win, X_EVENT_KEY_PRESS, 0, &key_pressed, &g);
		mlx_loop(g.mlx);
		ft_free_tab(NULL, g.map.map);
	}
	else
		ft_error(-1, NULL, NULL, ERR_BAD_ARG);
	return (0);
}
