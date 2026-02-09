/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hporta-c <hporta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 08:31:05 by hporta-c          #+#    #+#             */
/*   Updated: 2026/02/09 12:03:35 by hporta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"

void free_grid(t_life **life, int height) {
	int i = height - 1;
	if (!life || !*life)
		return ;
	while (i >= 0) {
		if ((*life)->grid[i]) {
			free((*life)->grid[i]);
			(*life)->grid[i] = NULL;	
		}
		i--;
	}
	free((*life)->grid);
	(*life)->grid = NULL;
}

t_life*	init_life(int width, int height, int iter) {
	t_life *life = malloc(sizeof(t_life));
	if (!life)
		return NULL;
	life->width = width + 2;
	life->height = height + 2;
	life->iter = iter;
	life->p_x = 1;
	life->p_y = 1;
	life->grid = calloc((life->height), sizeof(int *));
	if (!life->grid)
		return NULL;
	for (int i = 0; i < life->height; ++i) {
		life->grid[i] = calloc((life->width), sizeof(int));
		if (!life->grid[i]) {
			free_grid(&life, i);
			free(life);
			return NULL;
		}
	}
	return life;
}

int get_path(char c, t_life **life, int draw) {
	if (c == UP)
		(*life)->p_y--;
	else if (c == DOWN)
		(*life)->p_y++;
	else if (c == LEFT)
		(*life)->p_x--;
	else if (c == RIGHT)
		(*life)->p_x++;
	if (draw == 1) {
		if (((*life)->p_x > 0 && (*life)->p_x < (*life)->width - 1)
			 && ((*life)->p_y > 0 && (*life)->p_y < (*life)->height - 1)) {
				(*life)->grid[(*life)->p_y][(*life)->p_x] = 1;
			}
		else
			return 0;
	}
	return 1;
}

int main(int argv, char **argc) {
	char c = '\0';
	
	if (argv != 4)
		return 1;
	int width = atoi(argc[1]); 
	int height = atoi(argc[2]);
	int iter = atoi(argc[3]);
	if (width <= 0 || height <= 0 || iter < 0)
		return 1;
	t_life *life = init_life(width, height, iter);
	if (!life)
		return 1;
	int draw = 0;
	while (read(0, &c, 1) > 0) {
		if (c != 'w' && c != 's' && c != 'a' && c != 'd' && c != 'x' && c!= '\n') {
			free_grid(&life, life->height);
			free(life);
			return 1;
		}
		if (c == '\n')
			break ;
		if (c == DRAW && draw == 0)
			draw = 1;
		else if (c == DRAW && draw == 1)
			draw = 0;
		if (!get_path(c, &life, draw)) {
			free_grid(&life, life->height);
			free(life);
			return 0;
		}
			
	}
	for (int i = 0; i < life->iter; ++i) {
		live_or_death(&life);
	}
	for (int i = 1; i < life->height - 1; ++i) {
		int flag = 0;
		for (int j = 1; j < life->width - 1; ++j) {
			if (life->grid[i][j] == 1) {
				putchar('0');
				flag = 1;
			}
			if (life->grid[i][j] == 0 && flag == 1)
				putchar(' ');
		}
		putchar('\n');
	}
	free_grid(&life, life->height);
	free(life);
	return 0;
}