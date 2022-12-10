/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_pars2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:08:53 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/12/10 11:10:17 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	err_fre_lex_cub(t_lexer *lexer, t_cubd *cub)
{
	free(lexer->src);
	free(lexer);
	free(cub);
	exit_mssg("INVALID MAP !!\n");
}

void	exit_mssg(char *str)
{
	ft_putstr(str);
	exit(1);
}

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
	close(fd);
	return (map);
}
