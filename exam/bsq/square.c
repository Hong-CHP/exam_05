/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hporta-c <hporta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:11:32 by hporta-c          #+#    #+#             */
/*   Updated: 2026/02/11 17:51:00 by hporta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	find_max_square(t_map *map) {
	int max = 0;
	int max_height = 0;
	int max_width = 0;
	for(int row = 0; row < map->rows; ++row) {
		for (int col = 0; col < map->cols; ++col) {
			if (max < map->tab[row][col]) {
				max = map->tab[row][col];
				max_height = row;
				max_width = col;
			}
		}
	}
	if (max == 0)
		return ;
	int i = max_height;
	while (i > max_height - max) {
		int j = max_width;
		while (j > max_width - max) {
			if (map->grid[i][j] == map->f_p)
				map->grid[i][j] = map->f_x;
			j--;
		}
		i--;
	}
}