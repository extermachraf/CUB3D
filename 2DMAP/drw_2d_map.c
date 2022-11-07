/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drw_2d_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 02:08:04 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/11/07 10:38:31 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void pixelput(cub3d_t *cub, int x, int y, int color)
{
    cub->add[x + y * cub->todmap->with * 64] = color;
}

void    draw_car(cub3d_t *cub, int i, int j)
{
    int x = 0;
    int y = 0;
    while(y < 64)
    {
        x = 0;
        while(x < 64)
        {
            pixelput(cub, j * 64 + x , i * 64 + y, 0xFF);
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
        pixelput(cub, ((cub->x_player) * 64 + cos(i) * 5) + 32, ((cub->y_player) * 64 + sin(i) * 5) + 32, 0xff0000);
        i++;
    }
}

void    draw_angl_view(cub3d_t *cub)
{
    int i = 0;

    while (i < 80)
    {
        pixelput(cub, (cub->x_player * 64 - cos(cub->ang) * i) + 32, (cub->y_player * 64 - sin(cub->ang) * i) + 32, 0xff0000);
        i++;
    }
}

double normalizeangle(double rayangle)
{
    rayangle = remainder(rayangle, M_2_PI);
    if(rayangle < 0)
        rayangle += M_2_PI;
    return(rayangle);
}

void    cast_ray(double rayangle, int ray)
{
    rayangle = normalizeangle(rayangle);
}

void    draw_rays(cub3d_t *cub)
{
    double rayangle;
    int ray;
    int i;

    rayangle = cub->ang - (VIEW_ANGLE / 2);
    ray = 0;
    while(ray < NUM_RAYS)
    {
        // cast_ray(rayangle, ray);
        i = 0;
        while(i < 200)
        {
            pixelput(cub, (cub->x_player * 64 - cos(rayangle) * i) + 32, (cub->y_player * 64 - sin(rayangle) * i) + 32, 0xff0000);
            i++;
        }
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


int manag(int keycode, cub3d_t *cub)
{
    if (keycode == 53 || keycode == 12)
	{
		write(1, "exit\n", 5);
		exit(1);
	}
	else if (keycode == KEY_A)
    {
        cub->x_player -= 0.2;
    }
	else if (keycode == KEY_D)
    {
         cub->x_player += 0.2;
    }
    else if (keycode == KEY_DOWN || keycode == KEY_S)
    {
        cub->x_player += 0.3 * cos(cub->ang);
        cub->y_player += 0.3 * sin(cub->ang);
        
    }
    else if (keycode == KEY_UP || keycode == KEY_W)
    {
        cub->x_player -= 0.3 * cos(cub->ang);
        cub->y_player -= 0.3 * sin(cub->ang);
    }
    else if (keycode == KEY_LEFT)
    {
         cub->ang -= 0.2;
    }
    else if (keycode == KEY_RIGHT)
    {
         cub->ang += 0.2;
    }
	return (1);
}

int new_map(cub3d_t *cub)
{
    mlx_destroy_image(cub->mlx, cub->img);
    cub->img = mlx_new_image(cub->mlx, cub->todmap->with * 64, cub->todmap->hight * 64);
    cub->add = (int*)mlx_get_data_addr(cub->img, &cub->b, &cub->l, &cub->e);
    draw_2d_map(cub);
    mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
    return(0);
}