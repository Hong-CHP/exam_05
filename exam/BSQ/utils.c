/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hporta-c <hporta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:04:14 by hporta-c          #+#    #+#             */
/*   Updated: 2026/02/04 21:38:26 by hporta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int ft_strlen(char *str) {
	int len = 0;
	while (*str) {
		str++;
		len++;
	}
	return (len);
}

char* skip_whitespace(char *str, size_t len) {
	char *res = calloc(len + 1, sizeof(char));
	if (!res)
		return NULL;
	int k = 0;
	while (*str) {
		while (*str == ' ' || (*str >= 9 && *str <= 13))
			str++;
		if (*str == '\0')
			break;
		res[k] = *str;
		k++;
		str++;
	}
	res[k] = '\0';
	printf("%s\n", res);
	return res;
}

int get_rows(int *rows, int nb_len, char *line) {
	printf("line is : %s, nb_len is %d\n", line, nb_len);
	int k = 0;
	while(k < nb_len) {
		if (*line < '0' || *line > '9') {
			return 0;
		}
		(*rows) = (*rows) * 10 + (*line - '0');
		line++;
		k++;
	}
	return 1;
}

int params_check(t_map **map, char *line, size_t len) {
	if (len < 4)
		return 0;
	printf("len is %ld\n", len);
	char *p = line;
	int nb_len = len - 3;
	(*map)->f_p = line[len - 3];
	(*map)->f_o = line[len - 2];
	(*map)->f_x = line[len - 1];

	while(*p) {
		if (*p < 32 || *p > 126)
			return 0;
		p++;
	}
	if ((*map)->f_p == (*map)->f_o || (*map)->f_p == (*map)->f_x || (*map)->f_o == (*map)->f_x)
		return 0;
	if (!get_rows(&(*map)->rows, nb_len, line))
		return 0;
	printf("row is %d\n", (*map)->rows);
	return 1;
}

int	ft_strlcpy(t_map *map, char **dest, char *src, size_t len) {
	for (size_t i = 0; i < len; ++i) {
		if (src[i] != map->f_o && src[i] != map->f_p && src[i] != map->f_x)
			return 0;
		(*dest)[i] = src[i];
	}
	(*dest)[len] = '\0';
	return 1;
}

void	free_grid(char ***grid, char **line, int rows) {
	if (*grid == NULL || **grid == NULL) {
		if (line && *line) {
			free(*line);
			*line = NULL;
		}
		return ;
	}
	while (rows >= 0) {
		if ((*grid)[rows]) {
			free((*grid)[rows]);
			(*grid)[rows] = NULL;
		}
		rows--;
	}
	free(*grid);	
	*grid = NULL;
	if (line && *line) {
		free(*line);
		*line = NULL;
	}
}

void	free_tab(int ***tab, int rows) {
	if (*tab == NULL || **tab == NULL) {
		return ;
	}
	int i = 0;
	while (i < rows) {
		if ((*tab)[i]) {
			free((*tab)[i]);
			(*tab)[i] = NULL;
		}
		i++;
	}
	free(*tab);	
	*tab = NULL;
}
