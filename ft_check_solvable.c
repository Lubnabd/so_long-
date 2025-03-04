/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_solvable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdelkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:42:04 by labdelkh          #+#    #+#             */
/*   Updated: 2025/02/14 11:42:13 by labdelkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player_position(t_cat *cat_game)
{
	int	i;
	int	j;

	i = 0;
	while (cat_game->map[i])
	{
		j = 0;
		while (cat_game->map[i][j])
		{
			if (cat_game->map[i][j] == 'P')
			{
				cat_game->pos_y = i;
				cat_game->pos_x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill_exit(t_cat *cat_game, int py, int px)
{
	if (py < 0 || px < 0 || py >= cat_game->y || px >= cat_game->x)
		return ;
	if (cat_game->cpy_map[py][px] == '1')
		return ;
	if (cat_game->cpy_map[py][px] == 'E')
		cat_game->did_win = 1;
	cat_game->cpy_map[py][px] = '1';
	flood_fill_exit(cat_game, py - 1, px);
	flood_fill_exit(cat_game, py + 1, px);
	flood_fill_exit(cat_game, py, px - 1);
	flood_fill_exit(cat_game, py, px + 1);
}

void	set_exit_to_1(t_cat *cat_game)
{
	int	i;
	int	j;

	i = 0;
	while (cat_game->cpy_map[i])
	{
		j = 0;
		while (cat_game->cpy_map[i][j])
		{
			if (cat_game->cpy_map[i][j] == 'E')
			{
				cat_game->cpy_map[i][j] = '1';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill_icecream(t_cat *cat_game, int py, int px)
{
	if (py < 0 || px < 0 || py >= cat_game->y || px >= cat_game->x)
		return ;
	if (cat_game->cpy_map[py][px] == '1')
		return ;
	if (cat_game->cpy_map[py][px] == 'C')
		cat_game->cpy_icecream_num--;
	cat_game->cpy_map[py][px] = '1';
	flood_fill_icecream(cat_game, py - 1, px);
	flood_fill_icecream(cat_game, py + 1, px);
	flood_fill_icecream(cat_game, py, px - 1);
	flood_fill_icecream(cat_game, py, px + 1);
}

void	check_solvable(t_cat *cat_game)
{
	cat_game->cpy_icecream_num = cat_game->icecream_num;
	flood_fill_exit(cat_game, cat_game->pos_y, cat_game->pos_x);
	if (!cat_game->did_win)
		exit_game(cat_game, 1, "exit is not reachable");
	free_map(cat_game->cpy_map);
	cpy_map(cat_game);
	set_exit_to_1(cat_game);
	flood_fill_icecream(cat_game, cat_game->pos_y, cat_game->pos_x);
	if (cat_game->cpy_icecream_num != 0)
		exit_game(cat_game, 1, "player can't reach all icecreams");
}
