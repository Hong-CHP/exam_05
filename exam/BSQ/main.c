/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hporta-c <hporta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:29:51 by hporta-c          #+#    #+#             */
/*   Updated: 2026/02/04 21:37:08 by hporta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int map_parse(t_map* map, char *filename) {
	FILE *file = fopen(filename, "r");
	if (!file)
		return 0;
	size_t n = 0;
	ssize_t nread;
	char *line = NULL;
	if ((nread = getline(&line, &n, file)) != -1) {
		char *tmp = skip_whitespace(line, nread);
		if (!tmp) {
			fclose(file);
			return 0;
		}
		int tmp_l = ft_strlen(tmp);
		if (!params_check(&map, tmp, tmp_l)) {
			free(tmp);
			fclose(file);
			return 0;
		}
		free(tmp);
	}
	else
		return 0;
	int rows = 0;
	char **grid = malloc(sizeof(char*) * (map->rows + 1));
	if (!grid) {
		fclose(file);
		return 0;
	}
	int cols = -1;
	while ((nread = getline(&line, &n, file)) != -1) {
		printf("%ld\n", nread);
		if (line[nread - 1] != '\n') {
			free_grid(&grid, &line, rows);
			fclose(file);
			return 0;
		}
		if (cols == -1)
			cols = nread - 1;
		else {
			if ((nread - 1) != cols) {
				free_grid(&grid, &line, rows);
				fclose(file);
				return 0;
			}
		}
		grid[rows] = malloc(cols + 1);
		if (!grid[rows]) {
			free_grid(&grid, &line, rows);
			fclose(file);
			return 0;
		}
		if (!ft_strlcpy(map, &grid[rows], line, cols)) {
			free_grid(&grid, &line, rows);
			fclose(file);
			return 0;
		}
		printf("line after copy is : %s| grid length is %d\n", grid[rows], ft_strlen(grid[rows]));
		rows++;
	}
	free(line);
	grid[map->rows] = NULL;
	if (rows != map->rows) {
		free_grid(&grid, &line, rows);
		fclose(file);
		return 0;
	}
	map->cols = cols;
	map->grid = grid;
	fclose(file);
	return 1;
}

static int min3(int a, int b, int c)
{
	int min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return min;
}

int fill_tab(t_map *map) {
	int rows = 0;
	int cols = map->cols;
	map->tab = malloc(sizeof(int*) * map->rows);
	if (!map->tab)
		return 0;
	while (rows < map->rows) {
		map->tab[rows] = calloc(sizeof(int), cols);
		for (int i = 0; i < cols; ++i) {
			if (!map->tab[rows]) {
				rows--;
				while (rows >= 0) {
					free (map->tab[rows]);
					map->tab[rows] = NULL;
					rows--;
				}
				return 0;
			}
			if (map->grid[rows][i] == map->f_o)
				map->tab[rows][i] = 0;
			else if (rows == 0 || i == 0)
				map->tab[rows][i] = 1;
			else {
				map->tab[rows][i] = 1 + min3(map->tab[rows - 1][i],
					map->tab[rows][i - 1],
					map->tab[rows - 1][i - 1]);
			}
		}
		rows++;
	}
	return 1;
}

t_map* init_map() {
	t_map *map = malloc(sizeof(t_map));
	if (!map)
		return NULL;
	map->cols = 0;
	map->rows = 0;
	map->f_p = 0;
	map->f_o = 0;
	map->f_x = 0;
	map->grid = NULL;
	map->tab = NULL;
	return map;
}

int main(int argv, char**argc)
{
	if (argv != 2)
		return 1;
	t_map *map = init_map();
	if (!map)
	{
		fprintf(stderr, "map error\n");
		return 1;
	}
	if (!map_parse(map, argc[1]))
	{
		fprintf(stderr, "map error\n");
		free(map);
		return 1;
	}
	if (!fill_tab(map)) {
		fprintf(stderr, "map error\n");
		free_grid(&map->grid, NULL, map->rows);
		free(map);
		return 1;	
	}
	for (int i = 0; i < map->rows; ++i) {
		for (int j = 0; j < map->cols; ++j)
			printf("%d", map->tab[i][j]);
		printf("\n");
	}
	printf("f_x = '%c' (%d)\n", map->f_x, map->f_x);
	find_square(&map);
	for (int i = 0; i < map->rows; ++i) {
		
		printf("%s", map->grid[i]);
		printf("\n");
	}
	free_tab(&map->tab, map->rows);
	free_grid(&map->grid, NULL, map->rows);
	free(map);
	return 0;
}