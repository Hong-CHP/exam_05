/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hporta-c <hporta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:59:10 by hporta-c          #+#    #+#             */
/*   Updated: 2026/02/04 21:35:20 by hporta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "bsq.h"

void	find_square(t_map **map)
{
	int	max;
	int	max_i;
	int	max_j;
	int	i;
	int	j;

	max = 0;
	max_i = 0;
	max_j = 0;

	i = 0;
	while (i < (*map)->rows)
	{
		j = 0;
		while (j < (*map)->cols)
		{
			if ((*map)->tab[i][j] > max)
			{
				max = (*map)->tab[i][j];
				max_i = i;
				max_j = j;
			}
			j++;
		}
		i++;
	}

	/* 填充最大正方形 */
	i = max_i;
	while (i > max_i - max)
	{
		j = max_j;
		while (j > max_j - max)
		{
			(*map)->grid[i][j] = (*map)->f_x;
			j--;
		}
		i--;
	}
}
