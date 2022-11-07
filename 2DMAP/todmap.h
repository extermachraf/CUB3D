/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   todmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 01:33:23 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/11/07 07:41:08 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TODMAP_H
#define TODMAP_H
#include "../cub3d.h"

# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_LEFT 123
# define KEY_RIGHT 124

t_tood	*get_info_of2d(cub3d_t *cub);
int		calc_with(char **map);
int		calc_hight(char **map);
void    draw_2d_map(cub3d_t *cub);
void    draw_car(cub3d_t *cub, int i, int j);
int     manag(int keycode, cub3d_t *cub);
int     new_map(cub3d_t *cub);
void    draw_rays(cub3d_t *cub);
#endif
