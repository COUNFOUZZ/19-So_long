/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:54:07 by aabda             #+#    #+#             */
/*   Updated: 2022/12/05 09:58:53 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_check_wall(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	printf("%d\n", g->map.lenline);
	while (g->map.map[++i])
	{
		j = -1;
		while (++j < g->map.lenline - 1)
		{
			if (g->map.map[0][j] != '1'
				|| g->map.map[g->map.nl - 1][j] != '1'
				|| g->map.map[i][0] != '1'
				|| g->map.map[i][g->map.lenline - 2] != '1')
				ft_error(-1, NULL, g->map.map, ERR_MISSING_WALL);
		}
	}
}

static void	ft_err_check_map(t_game *g)
{
	ft_check_wall(g);
	if (g->check.nbr_player > 1)
		ft_error(-1, NULL, g->map.map, ERR_NBR_PLAYER1);
	else if (g->check.nbr_player < 1)
		ft_error(-1, NULL, g->map.map, ERR_NBR_PLAYER2);
	if (g->check.nbr_exit > 1)
		ft_error(-1, NULL, g->map.map, ERR_NBR_EXIT1);
	else if (g->check.nbr_exit < 1)
		ft_error(-1, NULL, g->map.map, ERR_NBR_EXIT2);
}

void	ft_check_map(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map.map[++i])
	{
		j = -1;
		while (g->map.map[i][++j])
		{
			if (g->map.map[i][j] == 'P')
			{
				g->check.nbr_player++;
				g->player.pos_y = i;
				g->player.pos_x = j;
			}
			else if (g->map.map[i][j] == 'E')
				g->check.nbr_exit++;
			else if (g->map.map[i][j] == 'C')
				g->check.nbr_coin++;
		}
		printf("%s", g->map.map[i]);
	}
	printf("x = %d\ty = %d\n", g->player.pos_x, g->player.pos_y);
	ft_err_check_map(g);
}
