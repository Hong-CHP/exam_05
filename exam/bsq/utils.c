/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hporta-c <hporta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:29:17 by hporta-c          #+#    #+#             */
/*   Updated: 2026/02/11 17:31:37 by hporta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int ft_strlen(char *str) {
	int len = 0;
	while (*str) {
		len++;
		str++;
	}
	return len;
}

char*	skip_whitespace(char *line, int nread) {
	char *tmp = malloc(sizeof(char) * (nread + 1));
	if (!tmp)
		return NULL;
	printf("%d\n", nread + 1);
	int k = 0;
	while (*line) {
		if (*line != ' ' && !(*line >= 9 && *line <= 12))
			tmp[k++] = *line;
		line++;
	}
	tmp[k] ='\0';
	return tmp;
}

int	check_param(t_map *map, char *line, int len) {
	printf("line is : %s, line_len is %d\n", line, len);
	if (len < 4)
		return 0;
	char *ptr = line;
	while (*ptr) {
		if (*ptr < 32 || *ptr > 126)
			return 0;
		ptr++;
	}
	char f_p = line[len - 3];
	char f_o = line[len - 2];
	char f_x = line[len - 1];
	if (f_p == f_o || f_p == f_x || f_o == f_x) 
		return 0;
	int rows = 0;
	for (int i = 0; i < len - 3; ++i) {
		if (line[i] < '0' || line[i] > '9')
			return 0;
		rows = rows * 10 + (line[i] - '0');
	}
	if (rows == 0)
		return 0;
	map->rows = rows;
	map->f_p = f_p;
	map->f_o = f_o;
	map->f_x = f_x;
	return rows;
}

char * ft_strdup(t_map* map, char *src, int len) {
	char *dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return NULL;
	int i = 0;
	while (i < len) {
		if (src[i] != map->f_p && src[i] != map->f_o && src[i] != map->f_x)
			return 0;
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

void free_grid(char ***grid, int rows) {
	if (!grid || !*grid)
		return ;
	while (rows >= 0) {
		if ((*grid)[rows]) {
			free((*grid)[rows]);
			 (*grid)[rows] = NULL;
		}
		rows--;
	}
	free(*grid);
	*grid = NULL;
}

void free_tab(int ***tab, int rows) {
	if (!tab || !*tab)
		return ;
	while (rows >= 0) {
		if ((*tab)[rows]) {
			free((*tab)[rows]);
			 (*tab)[rows] = NULL;
		}
		rows--;
	}
	free(*tab);
	*tab = NULL;
}

int min(int a, int b, int c) {
	int min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return min;
}