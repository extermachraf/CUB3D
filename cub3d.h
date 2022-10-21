/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:09:58 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/10/21 00:31:17 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

///////////////////////////
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"
#include "./parsing/pars.h"
# include "./towd_map/towd_map.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
//////////////////////////
# define WITH 1200
# define HIGHT 750
# define BUFFER_SIZE 1
# define TILE_SIZE 32
# define MAP_ROWS 8
# define MAP_COLS 42
//////////////////////////
typedef struct cub3d_t
{
    void	*mlx;
	void	*win;
	void	*wall;
    int     x_player;
    int     y_player;
    char    direction;
    int     f_col[2];
    int     c_col[2];
    char    **map;
}   cub3d_t;

// typedef struct nd_t
// {
// 	void	*hero;
// 	void	*colec;
// 	void	*exi;
// }   nd_t;
/////////////////////////////////////
cub3d_t *init_cub(char *str);
#endif