/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hporta-c <hporta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 10:13:13 by hporta-c          #+#    #+#             */
/*   Updated: 2026/02/09 11:48:06 by hporta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "life.h"

int live_or_death(t_life **life) {
	int **tmp = calloc((*life)->height, sizeof(int*));
	if (!tmp)
		return 0;
	for (int i = 0; i < (*life)->height; ++i) {
		tmp[i] = calloc((*life)->width, sizeof(int));
		if (!tmp[i]) {
			free_grid(life, i);
			return 0;
		}
	}
	for (int i = 0; i < (*life)->height; ++i) {		
		for (int j = 0; j < (*life)->width; ++j) {
			int lifes = 0;
			for (int d_y = -1; d_y <= 1; ++d_y) {
				for (int d_x = -1; d_x <= 1; ++d_x) {
					if (d_x == 0 && d_y == 0)
						continue;
					int ni = i + d_y;
					int nj = j + d_x;
					if (ni >= 0 && ni < (*life)->height && nj >= 0 && nj < (*life)->width)
						if ((*life)->grid[ni][nj] == 1)
							lifes++;
					}
			}
			if ((*life)->grid[i][j] == 0) {
				if (lifes == 3)
					tmp[i][j] = 1;
			} else {
				if (lifes == 2 || lifes == 3)
					tmp[i][j] = 1;
				else
					tmp[i][j] = 0;
			}
		}
	}
	free_grid(life, (*life)->height);
	(*life)->grid = tmp;
	return 1;
}