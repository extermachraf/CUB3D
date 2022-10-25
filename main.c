/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:52:06 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/10/25 01:09:33 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"
int	exit_mouse(int key)
{
	if (key < 0)
	{
		write(1, "exit\n", 5);
		exit(1);
	}
	return (0);
}

void    init_globals()
{
    flag_no = 1;
    flag_so = 1;
    flag_we = 1;
    flag_ea = 1;
    flag_f = 1;
    flag_c = 1;
    take_the_map = 6;
}

int main(int ac, char **av)
{
    cub3d_t *cub;
    
    if(ac != 2)
        return(0);
    init_globals();
    cub = malloc(sizeof(cub3d_t));
    cub = return_map(av[1], cub);
    printf("NO == %s\n", cub->NO);
    printf("SO == %s\n", cub->SO);
    printf("EA == %s\n", cub->EA);
    printf("WE == %s\n", cub->WE);
    //----------floooor----------------
    printf("FLOR COLOR :\n");
    for(int i = 0; i < 3 ; i++)
        printf("%d\n", cub->f_col[i]);
    printf("CIEL COLOR :\n");
     for(int i = 0; i < 3 ; i++)
        printf("%d\n", cub->c_col[i]);
    // cub = init_cub(av[1]);
    // cub->mlx = mlx_init();
    // cub->win = mlx_new_window(cub->mlx,WITH ,HIGHT, "CUB3D");
    // draw_2d_map(cub);
    // mlx_hook(cub->win, 17, 1L << 0, exit_mouse, &cub);
    // mlx_loop(cub->mlx);
    // mlx_key_hook(nd.win, management, &cub);
}