/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   todmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 01:33:23 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/12/10 11:03:31 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TODMAP_H
# define TODMAP_H
# include "../cub3d.h"

# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_LEFT 123
# define KEY_RIGHT 124

int		manag(int keycode, t_cubd *cub);
t_tood	*get_info_of2d(t_cubd *cub);
int		new_map(t_cubd *cub);
void	draw_rays(t_cubd *cub);
void	pixelput(t_cubd *cub, int x, int y, int color);
int		map_has_wall(t_cubd *cub, double x, double y);
void	draw(t_cubd *cub);
void	generate3d(t_cubd *cub);
void	norm_key_up(t_cubd *cub, double posx, double posy);
void	norm_key_down(t_cubd *cub, double posx, double posy);
void	norm_key_a(t_cubd *cub, double posx, double posy);
void	norm_key_d(t_cubd *cub, double posx, double posy);
double	calculate_distance(t_cubd *cub, double x, double y);
#endif
