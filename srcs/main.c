/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:31:17 by aabda             #+#    #+#             */
/*   Updated: 2022/12/06 11:03:05 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_print_map1(t_game *g)
{
	for (int i = 0; g->map.map[i]; i++)
			printf("[%p] - %s", g->map.map[i], g->map.map[i]);
	printf("\n");
}

int	main(int argc, const char **argv)
{
	t_game	g;

	if (argc == 2)
	{
		ft_path_map("maps/", argv[1], &g);
		init_struct(&g);
		printf("max_y = %d\tmax_x = %d\n", g.map.nl, g.map.lenline);
		// printf("%s", g.map.map[5]);
		// printf("%c\n", g.map.map[5][g.map.lenline - 2]);
		mlx_hook(g.mlx_win, 17, 0, &red_cross, &g);
		mlx_hook(g.mlx_win, X_EVENT_KEY_RELEASE, 0, &key_pressed, &g);
		mlx_loop(g.mlx);
		ft_free_tab(NULL, g.map.map);
		// system("leaks so_long");
	}
	else
		ft_error(-1, NULL, NULL, ERR_BAD_ARG);



	return (0);
}
