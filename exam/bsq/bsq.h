/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hporta-c <hporta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:11:47 by hporta-c          #+#    #+#             */
/*   Updated: 2026/02/11 17:31:48 by hporta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_map {
	int rows;	
	int cols;
	char f_p;
	char f_o;
	char f_x;
	int **tab;
	char **grid;
}				t_map;

char*	skip_whitespace(char *line, int nread);
int	check_param(t_map *map, char *line, int len);
int ft_strlen(char *str);
char * ft_strdup(t_map* map, char *src, int len);
void free_grid(char ***grid, int rows);
void free_tab(int ***tab, int rows);
int min(int a, int b, int c);
void	find_max_square(t_map *map);


#endif