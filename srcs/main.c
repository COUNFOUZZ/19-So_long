/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:31:17 by aabda             #+#    #+#             */
/*   Updated: 2022/12/19 19:09:44 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_print_map1(t_game *g)
{
	for (int i = 0; g->map.map[i]; i++)
	{
		for (int j = 0; g->map.map[i][j]; j++)
		{
			if (g->map.map[i][j] == 'P')
				printf(GREEN "%c" NORMAL, g->map.map[i][j]);
			else if (g->map.map[i][j] == 'C')
				printf(YELLOW "%c" NORMAL, g->map.map[i][j]);
			else if (g->map.map[i][j] == 'E')
				printf(PURPLE "%c" NORMAL, g->map.map[i][j]);
			else if (g->map.map[i][j] == '1')
				printf(RED "%c" NORMAL, g->map.map[i][j]);
			else
				printf(BLUE "%c" NORMAL, g->map.map[i][j]);
		}
	}
}

int	main(int argc, const char **argv)
{
	t_game	g;

	if (argc == 2)
	{
		ft_path_map("maps/", argv[1], &g);
		init_struct(&g);
		printf("\nMap_max_size:\n");
		printf("max_y = %d\tmax_x = %d\n", g.map.nl, g.map.lenline);
		// printf("%s", g.map.map[5]);
		// printf("%c\n", g.map.map[5][g.map.lenline - 2]);
		ft_print_map1(&g);
		// printf("size struct :%lu\n", sizeof(t_game*));
		mlx_hook(g.mlx_win, 17, 0, &red_cross, &g);
		mlx_hook(g.mlx_win, X_EVENT_KEY_PRESS, 0, &key_pressed, &g);
		mlx_loop(g.mlx);
		ft_free_tab(NULL, g.map.map);
		// system("leaks so_long");
	}
	else
		ft_error(-1, NULL, NULL, ERR_BAD_ARG);
	return (0);
}
