/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:52:06 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/10/20 12:23:42 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"
int main(int ac, char **av)
{
    cub3d_t *cub = NULL;
    if(ac != 2)
        return(0);
    cub = init_cub(av[1]);
    printf("%c\n",cub->map[1][1]);
    // for(int i = 0 ; cub->map[i] ; i++)
    //     printf("%s\n", cub->map[i]);
}