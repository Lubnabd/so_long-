/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdelkh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:43:50 by labdelkh          #+#    #+#             */
/*   Updated: 2025/02/14 11:43:52 by labdelkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_args(int argc, char **argv)
{
	int	ext_len;

	if (argc != 2)
	{
		ft_printf("Error\nincorrect number of arguments\n");
		exit(1);
	}
	ext_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][ext_len - 4], ".ber", 4))
	{
		ft_printf("Error\ninvalid file extention, expected: .ber\n");
		exit(1);
	}
}

void	check_map_file(char *file_path)
{
	int		fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("ERROR\ncannot open file\n");
		exit(1);
	}
	close (fd);
}
