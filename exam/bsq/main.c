/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hporta-c <hporta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:11:44 by hporta-c          #+#    #+#             */
/*   Updated: 2026/02/11 17:51:34 by hporta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	map_parse(t_map* map, char *filename) {
	(void)map;
	FILE *file = fopen(filename, "r");
	if (!file)
		return 0;
	char *line = NULL;
	ssize_t nread = 0;
	size_t len = 0;
	if ((nread = getline(&line, &len, file)) == -1) {
		fclose(file);
		return 0;
	}
	char *tmp = skip_whitespace(line, nread);
	if (!tmp) {
		free(line);
		fclose(file);
		return 0;
	}
	if (!check_param(map, tmp, ft_strlen(tmp))) {
		free(tmp);
		free(line);
		fclose(file);
		return 0;
	}
	free(tmp);
	int count_l = 0;
	int cols = -1;
	char **grid = malloc(sizeof(char *) * (map->rows + 1));
	if (!grid) {
		free(line);
		fclose(file);
		return 0;
	}
	while ((nread = getline(&line, &len, file)) != -1) {
		printf("nread is : %ld\n", nread);
		if (cols == -1)
			cols = nread - 1;
		else {
			if (count_l == map->rows - 1) {
				if (line[nread - 1] == '\0' && cols != nread) {
					free_grid(&grid, count_l - 1);
					free(line);
					fclose(file);
					return 0;
				}
			} else if (cols != nread - 1) {
				free_grid(&grid, count_l - 1);
				free(line);
				fclose(file);
				return 0;
			}
		}
		grid[count_l] = ft_strdup(map, line, cols);
		if (!grid[count_l]) {
			free_grid(&grid, count_l - 1);
			free(line);
			fclose(file);
			return 0;	
		}
		count_l++;
	}
	grid[count_l] = NULL;
	map->grid = grid;
	map->cols = cols;
	if (count_l != map->rows) {
		free_grid(&grid, count_l - 1);
		free(line);
		fclose(file);
		return 0;	
	}
	free(line);
	fclose(file);
	return 1;
}

void	init_map(t_map*	map) {
	map->rows = 0;
	map->cols = 0;
	map->f_p = 0;
	map->f_o = 0;
	map->f_x = 0;
	map->tab = NULL;
	map->grid = NULL;
}

int fill_map(t_map* map) {
	int** tab = malloc(sizeof(int *) * map->rows);
	if (!tab)
		return 0;
	for(int row = 0; row < map->rows; ++row) {
		tab[row] = malloc(sizeof(int) * map->cols);
		if (!tab[row]) {
			free_tab(&tab, row - 1);
			return 0;
		}
		for (int col = 0; col < map->cols; ++col) {
			if (row == 0 || col == 0)
				tab[row][col] = 1;
			else if (map->grid[row][col] == map->f_o)
				tab[row][col] = 0;
			else
				tab[row][col] = 1 + min(tab[row - 1][col], tab[row - 1][col - 1], tab[row][col - 1]);
		}
	}
	map->tab = tab;
	return 1;
}

int main(int argc, char **argv) {
	if (argc != 2)
		return 1;
	t_map* map = malloc(sizeof(t_map));
	if (!map){
		fprintf(stderr, "%s", "map error");
		return 1;
	}
	init_map(map);
	if (!map_parse(map, argv[1])) {
		fprintf(stderr, "%s", "map error");
		free(map);
		return 1;
	}
	if (!fill_map(map)) {
		free_grid(&map->grid, map->rows);
		free(map);
		return 1;
	}
	find_max_square(map);
	for(int row = 0; row < map->rows; ++row) {
		fprintf(stdout, "%s\n", map->grid[row]);
	}
	// fprintf(stdout, "%c", '\n');
	free_grid(&map->grid, map->rows - 1);
	free_tab(&map->tab, map->rows - 1);
	free(map);
	return 0;
}