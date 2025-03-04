/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdelkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:43:40 by labdelkh          #+#    #+#             */
/*   Updated: 2025/02/14 11:43:41 by labdelkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_rows(t_cat *cat_game)
{
	cat_game->x = ft_strlen(cat_game->map[0]);
	while (cat_game->map[cat_game->y])
	{
		if ((int)ft_strlen(cat_game->map[cat_game->y]) != cat_game->x)
			exit_game(cat_game, 1, "map line are not equal");
		cat_game->y++;
	}
}

void	validate_shape(t_cat *cat_game)
{
	if (cat_game->x == cat_game->y)
		exit_game(cat_game, 1, "map is not recatangular");
}

void	validate_borders(t_cat *cat_game)
{
	int		i;

	i = 0;
	while (cat_game->map[0][i])
	{
		if (cat_game->map[0][i] != '1')
			exit_game(cat_game, 1, "invalid top map border");
		i++;
	}
	i = 0;
	while (cat_game->map[cat_game->y - 1][i])
	{
		if (cat_game->map[cat_game->y - 1][i] != '1')
			exit_game(cat_game, 1, "invalid bottom map border");
		i++;
	}
	i = 1;
	while (i < cat_game->y - 1)
	{
		if (cat_game->map[i][0] != '1'
		|| cat_game->map[i][cat_game->x - 1] != '1')
			exit_game(cat_game, 1, "invalid side map borders");
		i++;
	}
}

void	validate_elements(t_cat *cat_game)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (cat_game->map[i])
	{
		j = 0;
		while (cat_game->map[i][j])
		{
			c = cat_game->map[i][j];
			if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
				exit_game(cat_game, 1, "invalid map element");
			if (c == 'P')
				cat_game->players_num++;
			if (c == 'C')
				cat_game->icecream_num++;
			if (c == 'E')
				cat_game->exit_num++;
			j++;
		}
		i++;
	}
}

void	validate_map(t_cat *cat_game)
{
	validate_rows(cat_game);
	validate_shape(cat_game);
	validate_borders(cat_game);
	validate_elements(cat_game);
	if (cat_game->players_num != 1)
		exit_game(cat_game, 1, "invalid number of players");
	if (cat_game->icecream_num < 1)
		exit_game(cat_game, 1, "no icecreams");
	if (cat_game->exit_num != 1)
		exit_game(cat_game, 1, "invalid number of exits");
}
