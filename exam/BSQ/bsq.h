/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hporta-c <hporta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:30:05 by hporta-c          #+#    #+#             */
/*   Updated: 2026/02/04 21:35:02 by hporta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BQD_H
#define BQD_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_map {
	char f_p;
	char f_o;
	char f_x;
	int rows;
	int cols;
	char **grid;
	int **tab;
}				t_map;


int ft_strlen(char *str);
char* skip_whitespace(char *str, size_t len);
int params_check(t_map **map, char *line, size_t len);
int	ft_strlcpy(t_map *map, char **dest, char *src, size_t len);
void	free_grid(char ***grid, char **line, int rows);
void	free_tab(int ***tab, int rows);
void find_square(t_map **map);

#endif