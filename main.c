/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:52:06 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/10/21 16:51:51 by ael-kouc         ###   ########.fr       */
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

int render_rec(cub3d_t *cub, int size, int color, int x, int y)
{
    int i;
    int j;

    i = y;
    while(i < y + size)
    {
        j = x;
        while(j < x + size)
            mlx_pixel_put(cub->mlx, cub->win, j++, i, color);
        i++;
    }
    return(0);
}
int    draw_2d_map(cub3d_t *cub)
{
    int x;
    int y;

    y = 0;
    while(cub->map[y])
    {
        x = 0;
        while(cub->map[y][x])
        {
            if(cub->map[y][x] == '1')
                render_rec(cub, 32, 0xFFFF, x, y);
            else if(cub->map[y][x] == '0')
                render_rec(cub, 32, 0xFFFF, x, y);
            x++;
        }
        y++;
    }   
    return(0);
} 

int main(int ac, char **av)
{
    cub3d_t *cub = NULL;
    if(ac != 2)
        return(0);
    cub = init_cub(av[1]);
    cub->mlx = mlx_init();
    cub->win = mlx_new_window(cub->mlx,WITH ,HIGHT, "CUB3D");
    draw_2d_map(cub);
    mlx_hook(cub->win, 17, 1L << 0, exit_mouse, &cub);
    mlx_loop(cub->mlx);
    // mlx_key_hook(nd.win, management, &cub);
}