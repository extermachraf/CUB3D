/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:52:06 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/11/17 00:14:49 by ael-kouc         ###   ########.fr       */
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

void    render_2d_map(cub3d_t *cub)
{
    int i;
    int j;

    i = 0;
    while(cub->map[i])
    {
        j = 0;
        while(cub->map[i][j])
        {
            if(cub->map[i][j] == '1')
                draw_car(cub, i, j);
            j++;
        }
        i++;
    }
}

void    draw(cub3d_t *cub)
{
    // cub->x_player = cub->x_player * TILE_SIZE + TILE_SIZE / 2;
    // cub->y_player = cub->y_player * TILE_SIZE + TILE_SIZE / 2;
    render_2d_map(cub);
    draw_player(cub);
    // draw_angl_view(cub);
    // cast_rays(cub);
    draw_rays(cub);
}

int main(int ac, char **av)
{
    cub3d_t *cub;
    int i = 0;

    if(ac != 2)
        return(0);
    init_globals();
    cub = malloc(sizeof(cub3d_t));
    cub = return_map(av[1], cub);
    check_map(cub);
    // printf("NO == %s\n", cub->NO);
    // printf("SO == %s\n", cub->SO);
    // printf("EA == %s\n", cub->EA);
    // printf("WE == %s\n", cub->WE);
    // //----------floooor----------------
    // printf("FLOR COLOR :\n");
    // for(int i = 0; i < 3 ; i++)
    //     printf("%d\n", cub->f_col[i]);
    // //---------ciel--------------------
    // printf("CIEL COLOR :\n");
    // for(int i = 0; i < 3 ; i++)
    //     printf("%d\n", cub->c_col[i]);
    // //----------map-------------------
    // printf("MAP:\n");
    // for(int i = 0 ; cub->map[i] ; i++)
    // //     printf("{%s}\n", cub->map[i]);
    // printf("%d\n", cub->x_player);
    // printf("%d\n", cub->y_player);
    // cub = init_cub(av[1]);
    cub->todmap = get_info_of2d(cub);
    cub->x_player = cub->x_player * TILE_SIZE + TILE_SIZE / 2;
    cub->y_player = cub->y_player * TILE_SIZE + TILE_SIZE / 2;
    cub->rays = malloc(sizeof(t_rays *) * NUM_RAYS);
    while(i < NUM_RAYS)
    {
        cub->rays[i] = malloc(sizeof(t_rays));
        i++;
    }
    cub->mlx = mlx_init();
    cub->win = mlx_new_window(cub->mlx,cub->todmap->with ,cub->todmap->hight, "CUB3D");
    cub->img = mlx_new_image(cub->mlx, cub->todmap->with, cub->todmap->hight);
    cub->add = (int*)mlx_get_data_addr(cub->img, &cub->b, &cub->l, &cub->e);
    draw(cub);
    mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
    mlx_hook(cub->win, 2, 0, manag, cub);
    mlx_loop_hook(cub->mlx, new_map, cub);
    // mlx_hook(cub->win, 17, 1L << 0, exit_mouse, &cub);
    mlx_loop(cub->mlx);
    // mlx_key_hook(nd.win, management, &cub);
}

//1 -player
//sur by walls
//espace
//player inside map
