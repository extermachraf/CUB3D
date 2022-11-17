/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drw_2d_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 02:08:04 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/11/17 00:14:25 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void pixelput(cub3d_t *cub, int x,int y, int color)
{
    if(x >= 0 && x <= cub->todmap->with && y >= 0 && y <= cub->todmap->hight)
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

void    draw_player(cub3d_t *cub)
{
    int i = 0;

    while (i < 360)
    {
        pixelput(cub, ((cub->x_player) + cos(i) * 2), ((cub->y_player) + sin(i) * 2), 0xff0000);
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


int manag(int keycode, cub3d_t * cub)
{
    double posx;
    double posy;
    
    if (keycode == 53 || keycode == 12)
	{
		write(1, "exit\n", 5);
		exit(1);
	}
	else if (keycode == KEY_D)
    {
        posx = cub->x_player - 11  * cos(cub->ang + 1.5708);
        posy = cub->y_player - 11  * sin(cub->ang + 1.5708);
        if(map_has_wall(cub, posx, posy))
        {
            cub->x_player = posx;
            cub->y_player = posy;
        }
    }
	else if (keycode == KEY_A)
    {
        posx = cub->x_player + 11  * cos(cub->ang + 1.5708);
        posy = cub->y_player + 11  * sin(cub->ang + 1.5708);
        if(map_has_wall(cub, posx, posy) && map_has_wall(cub, cub->x_player, posy)
            && map_has_wall(cub, posx, cub->y_player))
        {
            cub->x_player = posx;
            cub->y_player = posy;
        }
    }
    else if ((keycode == KEY_DOWN || keycode == KEY_S))
    {
        posx = cub->x_player + 11 * cos(cub->ang);
        posy = cub->y_player + 11 * sin(cub->ang);
        if(map_has_wall(cub, posx, posy) && map_has_wall(cub, cub->x_player, posy)
            && map_has_wall(cub, posx, cub->y_player))
        {
            cub->x_player = posx;
            cub->y_player = posy;
        }
    }
    else if ((keycode == KEY_UP || keycode == KEY_W))
    {
        posx = cub->x_player - 11 * cos(cub->ang);
        posy = cub->y_player - 11 * sin(cub->ang);
        if(map_has_wall(cub, posx, posy) && map_has_wall(cub, cub->x_player, posy)
            && map_has_wall(cub, posx, cub->y_player))
        {
            cub->x_player = posx;
            cub->y_player = posy;
        }
    }
    else if (keycode == KEY_LEFT)
    {
        cub->ang -= 0.25;
    }
    else if (keycode == KEY_RIGHT)
    {
        cub->ang += 0.25;
    }
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


/////////////////////////////////////////////////////
//////////////CHECK_IF_WALL//////////////////////////
/////////////////////////////////////////////////////



//===========>
char mapHasWallAt(cub3d_t *cub, float x, float y) {
    if (x < 0 || x > cub->todmap->with || y < 0 || y > cub->todmap->hight)
        return('1');
    int mapGridIndexX = floor(x / TILE_SIZE);
    int mapGridIndexY = floor(y / TILE_SIZE);
    return(cub->map[mapGridIndexY][mapGridIndexX]) != '0';
}
int map_has_wall(cub3d_t *cub, double x, double y)
{
    int x_check;
    int y_check;
    if (x < 0 || x > cub->todmap->with || y < 0 || y > cub->todmap->hight)
        return(0);
    x_check = (int)floor(x / TILE_SIZE);
    y_check = (int)floor(y / TILE_SIZE);
    if (cub->map[y_check][x_check] != '1')
        return(1);
    return(0);
}


/////////////////////////////////////////////////////
//////////DRAW_RAYS///////////////////////////////////
/////////////////////////////////////////////////////



//==============>
double calculate_distance(cub3d_t *cub,double x,double y){
    return (sqrt(pow(cub->x_player - x, 2) + pow(cub->y_player - y, 2)));
}

double  ray_distance(cub3d_t *cub, double rayangle, int ray)
{
    
    int i = 0;
    double x_check;
    double y_check;
    while(i >= 0 && i < WIN_WITH && i < WIN_HIGHT)
    {
        x_check = cub->x_player - cos(rayangle) * i;
        y_check = cub->y_player - sin(rayangle) * i;
        if (!map_has_wall(cub,  x_check, y_check) ||  !map_has_wall(cub, x_check, cub->y_player - sin(rayangle) * (i - 1))
            || !map_has_wall(cub, cub->x_player  - cos(rayangle) * (i - 1), y_check))
        {
            cub->rays[ray]->distance = distanceBetweenPoints(cub->x_player, cub->y_player, x_check, y_check);
            cub->rays[ray]->wallHitx = x_check;
            cub->rays[ray]->wallHity = y_check;
            cub->rays[ray]->rayangle = rayangle;
            break;
        }
        else
        {
            pixelput(cub, (cub->x_player  - cos(rayangle) * i) , (cub->y_player  - sin(rayangle) * i), 0xff0000);
            i++;
        }
    }
    return calculate_distance(cub,(cub->x_player  - cos(rayangle) * i) ,(cub->y_player - sin(rayangle) * i));
}
void    draw_rays(cub3d_t *cub)
{
    double rayangle;
    int ray;

    rayangle = cub->ang - (FOV_ANGLE / 2);
    ray = 0;

    while(ray < NUM_RAYS)
    {
        double p = ray_distance(cub,rayangle, ray);
        rayangle += VIEW_ANGLE / NUM_RAYS;
        ray++;
    }
}