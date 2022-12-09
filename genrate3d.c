#include "cub3d.h"

int direction(t_cubd* cub, int ray){

    //North
    if (cub->map[((int)(cub->rays[ray]->wallhity + 1)) / TILE_SIZE][(int)cub->rays[ray]->wallhitx / TILE_SIZE] == '0') 
        return (1);
    //west
    if (cub->map[(int)cub->rays[ray]->wallhity / TILE_SIZE][((int)(cub->rays[ray]->wallhitx + 1)) / TILE_SIZE]  == '0') 
        return (2);
    //South
    if (cub->map[((int)(cub->rays[ray]->wallhity - 1)) / TILE_SIZE][(int)cub->rays[ray]->wallhitx / TILE_SIZE]  == '0') 
        return (3);
    //Ew
    if (cub->map[(int)cub->rays[ray]->wallhity / TILE_SIZE][((int)(cub->rays[ray]->wallhitx - 1)) / TILE_SIZE]  == '0') 
        return (4);
    
    return (0);
}
void generate3d(t_cubd *cub)
{
	int	y;
	int	x;
	double i;
    int ray;
    int textureoffset_x;
    
    ray = 0;
	i = 0;
    x = 0;
    y = cub->rays[ray]->walltoppixel;
    while (ray < NUM_RAYS)
    {
        int j = 0;
        while (j < cub->rays[ray]->walltoppixel)
        {
            pixelput(cub, ray, j, 0x4B3D60);
            j++;
        }
        i = j;
        if(direction(cub, ray) == 2 || direction(cub, ray) == 4)
            textureoffset_x = (int)cub->rays[ray]->wallhity % TILE_SIZE;
        else
            textureoffset_x = (int)cub->rays[ray]->wallhitx % TILE_SIZE;
        while (i < cub->rays[ray]->wallbottompixel)
        {
		    int distancefromtop = i + (cub->rays[ray]->wallsheight / 2) - (WIN_HIGHT / 2);
            int textureoffset_y = distancefromtop * ((float)TILE_SIZE / cub->rays[ray]->wallsheight);
            if (direction(cub, ray) == 1)
                pixelput(cub, ray, i, pixelget(cub, textureoffset_x,textureoffset_y, 0));
            if (direction(cub, ray) == 3 )
                pixelput(cub, ray, i, pixelget(cub, textureoffset_x,textureoffset_y, 1));
            if (direction(cub, ray) == 2 )
                pixelput(cub, ray, i, pixelget(cub, textureoffset_x,textureoffset_y, 2));
            if (direction(cub, ray) == 4)
                pixelput(cub, ray, i, pixelget(cub, textureoffset_x,textureoffset_y, 3));
            i++;
        }
		j = cub->rays[ray]->wallbottompixel;
        while(j < WIN_HIGHT)
		{
            pixelput(cub, ray, j, 0x17062e);
			j++;
		}
        ray++;
    }

}
