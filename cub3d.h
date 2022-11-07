/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:09:58 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/11/07 08:56:22 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

///////////////////////////
#include "./get_next_line/get_next_line.h"
#include "./libftt/libft.h"
#include "./parsing/pars.h"
#include "./2DMAP/todmap.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
//////////////////////////
# define WITH 640
# define HIGHT 640
# define BUFFER_SIZE 1
# define TILE_SIZE 32
# define VIEW_ANGLE 1.0472
# define NUM_RAYS 30
# define INCR 0.0349066



//////////////////////////
// typedef struct cub3d_t
// {
//     void	*mlx;
// 	void	*win;
//     int     x_player;
//     int     y_player;
//     char    direction;
//     int     f_col[2];
//     int     c_col[2];
//     char    **map;
//     char    **info;
//     char    *NO;
//     char    *SO;
//     char    *EA;
//     char    *WE;
// }   cub3d_t;

// typedef struct nd_t
// {
// 	void	*hero;
// 	void	*colec;
// 	void	*exi;
// }   nd_t;
/////////////////////////////////////
cub3d_t *init_cub(char *str);
#endif