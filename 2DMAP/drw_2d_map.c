/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drw_2d_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 02:08:04 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/11/12 17:15:01 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void pixelput(cub3d_t *cub, int x,int y, int color)
{
    // if(x >= 0 && x <= cub->todmap->with && y >= 0 && y <= cub->todmap->hight)
    printf("x === %d ; y === %d\n", x, y);
        cub->add[x + y * cub->todmap->with] = color;
}

void    draw_car(cub3d_t *cub, int i, int j)
{
    int x = 0;
    int y = 0;
    while(y < TILE_SIZE)
    {
        x = 0;
        while(x < TILE_SIZE)
        {
            pixelput(cub, j * TILE_SIZE + x , i * TILE_SIZE + y, 0xFF);
            x++;
        }
        y++;
    }
}

void    draw_walls(cub3d_t *cub)
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

void    draw_player(cub3d_t *cub)
{
    int i = 0;

    while (i < 360)
    {
        pixelput(cub, ((cub->x_player) + cos(i) * 5), ((cub->y_player) + sin(i) * 5), 0xff0000);
        i++;
    }
}

void    draw_angl_view(cub3d_t *cub)
{
    int i = 0;

    while (i < 30)
    {
        pixelput(cub, (cub->x_player - cos(cub->ang) * i), (cub->y_player - sin(cub->ang) * i), 0xff0000);
        i++;
    }
}

// double normalizeangle(double rayangle)
// {
//     rayangle = remainder(rayangle, M_2_PI);
//     if(rayangle < 0)
//         rayangle += M_2_PI;
//     return(rayangle);
// }

double calculate_distance(cub3d_t *cub,double x,double y){
    return (sqrt(pow(cub->x_player - x, 2) + pow(cub->y_player - y, 2)));
}
double  ray_distance(cub3d_t *cub,double rayangle)
{
    int i = 0;
    while(i >= 0 && i < WIN_WITH && i < WIN_HIGHT)
    {
        if (cub->map[(int)(((cub->y_player * TILE_SIZE - sin(rayangle) * i) + TILE_SIZE/2)/ TILE_SIZE)][(int)(((cub->x_player * TILE_SIZE - cos(rayangle) * i) + TILE_SIZE/2) / TILE_SIZE)] == '1')
            break;
        else
        {
            pixelput(cub, (cub->x_player * TILE_SIZE - cos(rayangle) * i) + TILE_SIZE/2, (cub->y_player * TILE_SIZE - sin(rayangle) * i) + TILE_SIZE/2, 0xff0000);
            i++;
        }
    }
    return calculate_distance(cub,(cub->x_player * TILE_SIZE - cos(rayangle) * i) + TILE_SIZE/2,(cub->y_player * TILE_SIZE - sin(rayangle) * i) + TILE_SIZE/2);    
}
void    draw_rays(cub3d_t *cub)
{
    double rayangle;
    int ray;
    int i;

    rayangle = cub->ang - (FOV_ANGLE / 2);
    ray = 0;

    while(ray < NUM_RAYS)
    {
        // cast_ray(rayangle, ray);
        i = 0;
        cub->rays[ray].distance=ray_distance(cub,rayangle);
        rayangle += VIEW_ANGLE / NUM_RAYS;
        ray++;
    }
}

void    draw_2d_map(cub3d_t *cub)
{
    draw_walls(cub);
    draw_player(cub);
    draw_angl_view(cub);
    draw_rays(cub);
}

int map_has_wall(cub3d_t *cub, double x, double y)
{
    double x_check;
    double y_check;

    x_check = floor(x);
    y_check = floor(y);
    if(cub->map[(int)y_check][(int)x_check] != '0')
        return(1);
    return(0);
}

int manag(int keycode, cub3d_t *cub)
{
    printf("amgle === %f",cub->ang);
    if (keycode == 53 || keycode == 12)
	{
		write(1, "exit\n", 5);
		exit(1);
	}
	// else if (keycode == KEY_D)
    // {
    //     cub->x_player -= 5  * cos(cub->ang + 1.5708);
    //     cub->y_player -= 5  * sin(cub->ang + 1.5708);
    // }
	// else if (keycode == KEY_A)
    // {
    //     cub->x_player += 5  * cos(cub->ang + 1.5708);
    //     cub->y_player += 5  * sin(cub->ang + 1.5708);
    // }
    // else if ((keycode == KEY_DOWN || keycode == KEY_S))
    // {
    //     cub->x_player += 5 * cos(cub->ang);
    //     cub->y_player += 5 * sin(cub->ang);
    // }
    else if ((keycode == KEY_UP || keycode == KEY_W))
    {
        cub->y_player = cub->x_player - 5 * sin(cub->ang);
        cub->x_player = cub->y_player - 5 * cos(cub->ang);
    }
    // else if (keycode == KEY_LEFT)
    // {
    //      cub->ang -= 0.2;
    // }
    // else if (keycode == KEY_RIGHT)
    // {
    //      cub->ang += 0.2;
    // }
	return (1);
}

int new_map(cub3d_t *cub)
{
    mlx_destroy_image(cub->mlx, cub->img);
    cub->img = mlx_new_image(cub->mlx, cub->todmap->with, cub->todmap->hight);
    cub->add = (int*)mlx_get_data_addr(cub->img, &cub->b, &cub->l, &cub->e);
    draw(cub);
    mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
    return(0);
}