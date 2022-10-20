/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:09:58 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/10/20 12:19:42 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"
#include "./parsing/pars.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#define BUFFER_SIZE 1
typedef struct cub3d_t
{
    int x_player;
    int y_player;
    char direction; 
    int f_col[2];
    int c_col[2];
    char **map;
}   cub3d_t;
cub3d_t *init_cub(char *str);
#endif