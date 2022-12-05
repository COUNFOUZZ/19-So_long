/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:31:17 by aabda             #+#    #+#             */
/*   Updated: 2022/12/05 10:09:01 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, const char **argv)
{
	t_game	g;

	if (argc == 2)
	{
		ft_path_map("maps/", argv[1], &g);
		init_struct(&g);
		ft_free_tab(g.argv, g.map.map);
		// system("leaks so_long");
	}
	else
		ft_error(-1, NULL, NULL, ERR_BAD_ARG);



	// mlx_hook(g.mlx_win, 17, 0, &red_cross, &g);
	// mlx_hook(g.mlx_win, X_EVENT_KEY_RELEASE, 0, &key_pressed, &g);
	// mlx_loop(g.mlx);
	return (0);
}
