/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hporta-c <hporta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 08:31:29 by hporta-c          #+#    #+#             */
/*   Updated: 2026/02/09 11:34:21 by hporta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFE_H
# define LIFE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define UP 'w'
# define DOWN 's'
# define LEFT 'a'
# define RIGHT 'd'
# define DRAW 'x'

typedef struct s_life {
	int **grid;
	int width;
	int height;
	int iter;
	int p_x;
	int p_y;
}				t_life;

int live_or_death(t_life **life);
void free_grid(t_life **life, int height);

#endif