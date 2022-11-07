/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 01:43:28 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/11/06 02:05:41 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int calc_with(char **map)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while(map[i])
	{
		if(j < (int)ft_strlen(map[i]))
			j = (int)ft_strlen(map[i]);
		i++;
	}
	return(j);
}

int	calc_hight(char **map)
{
	return(lent_double_p(map));
}

t_tood	*get_info_of2d(cub3d_t *cub)
{
	t_tood *todmap;

	todmap = malloc(sizeof(t_tood));
	todmap->hight = calc_hight(cub->map);
	todmap->with = calc_with(cub->map);
	return(todmap);
}