/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:32:09 by aabda             #+#    #+#             */
/*   Updated: 2022/12/26 23:13:14 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_add_back(t_game *g, int x, int y)
{
	t_pos_coin	*new_coin;
	t_pos_coin	*current;

	new_coin = malloc(sizeof(t_pos_coin));
	if (!new_coin)
		return ;
	new_coin->x = x;
	new_coin->y = y;
	new_coin->next = NULL;
	if (!g->check.head)
		g->check.head = new_coin;
	else
	{
		current = g->check.head;
		while (current->next)
			current = current->next;
		current->next = new_coin;
	}
}

void	ft_print_list(t_game *g)
{
	t_pos_coin	*current;

	current = g->check.head;
	while (current)
	{
		printf("[%p] - coin_y = %d\tcoin_x = %d\tnext = [%p]\n", current, current->y, current->x, current->next);
		current = current->next;
	}
}
