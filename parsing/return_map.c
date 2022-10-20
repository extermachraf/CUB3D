/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:14:49 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/10/20 12:15:00 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


char	*line_map(int fd)
{
	char	*line;
	char	*map;
	char	*tmp;

	map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = map;
		map = ft_strjoin(map, line);
		free(tmp);
		free(line);
	}
	return (map);
}

char	**split_map(char *c)
{
	char	**spl_map;

	spl_map = ft_split(c, '\n');
	return (spl_map);
}

char	**return_map(char *av)
{
	char	*map;
	char	**spl_map;
	int		i;
	int		fd;

	i = 0;
	fd = open(av, O_RDONLY);
	map = line_map(fd);
	spl_map = split_map(map);
	close(fd);
	free(map);
	return (spl_map);
}

cub3d_t *init_cub(char *str)
{
    cub3d_t *cub;

    cub = malloc(sizeof(cub3d_t));
    cub->map = return_map(str);
    cub->x_player = 1;
    cub->y_player = 1;
    cub->direction = 'S';
    cub->f_col[0] = 220;
    cub->f_col[0] = 100;
    cub->f_col[0] = 0;
    cub->c_col[0] = 225;
    cub->c_col[0] = 30;
    cub->c_col[0] = 0;
    return(cub);
}