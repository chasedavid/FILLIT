#include "libft.h" 

void checkpiece(t_list *link, char **map, int alpha)
{
	t_coord xy;
	char *piece;
	printf("------------- checkpiece() function -------------\n");
	printf("alpha: %c \n", alpha);
	printf("map[0]: %s \n", map[0]);
	printf("map[1]: %s \n", map[1]);
	printf("tetrimino piece:\n%s \n", link->content);

	if (link->content != 0)
	{
		//
		printf("------------- tettrim() function -------------\n");
		piece = tettrim_str(link->content);
		
		//replace 5 with mapsize
		xy = getnextxy(map, piece, 5);
		if (checkxy(map, piece, xy) == 1) 
			map = placexy(map, piece, link->alpha, xy);
		else
			printf("waaaah checkxy failed \n");
	}

}

