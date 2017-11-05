#include "libft.h"

int arr2dlenrow(char **array2d)
{
    int x;
    x = 0;

    int i;
    i = 0;
    while (i < 2)
    {
        printf("arr2dlenrow array2d[%i]: %s \n", i, array2d[i]);
        i++;
    }


    while (array2d[x] != 0)
    {
//      if (array2d[x] == 0)
//          return (x);
        printf("array2d[x]: %s\n", array2d[x]);
        x++;
    }
    return (x);
}

int arr2dlencol(char **array2d)
{
    int y;
    y = 0;


    int i;
    i = 0;
    while (i < 2)
    {
        printf("arr2dlencol array2d[%i]: %s \n", i, array2d[i]);
        i++;
    }



    while (array2d[0][y] != 0)
    {
        printf("array2d[0][y]: %c\n", array2d[0][y]);
        y++;
    }
    return (y);
}
