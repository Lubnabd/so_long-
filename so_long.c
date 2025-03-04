/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdelkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:42:55 by labdelkh          #+#    #+#             */
/*   Updated: 2025/02/14 11:42:57 by labdelkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_cat	*cat_game;

	validate_args(argc, argv);
	check_map_file(argv[1]);
	cat_game = (t_cat *)malloc(sizeof(t_cat));
	if (!cat_game)
	{
		ft_printf("Error\nmemory allocation failed\n");
		exit (1);
	}
	set_game_def(cat_game);
	read_map(cat_game, argv[1]);
	validate_map(cat_game);
	cpy_map(cat_game);
	set_player_position(cat_game);
	check_solvable(cat_game);
	init_game(cat_game);
	mlx_hook(cat_game->win_mlx, 17, 0, close_window, cat_game);
	mlx_key_hook(cat_game->win_mlx, handle_keys, cat_game);
	mlx_loop(cat_game->mlx);
}
