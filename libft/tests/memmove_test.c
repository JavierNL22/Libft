#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

int main(void)
{
    char    *src;
    char    *dest;
    char    *src2;
    char    *dest2;
    
    src = ft_strdup("Hola mundo!");
    src2 = ft_strdup(src); 
    dest = src + 3;
    dest2 = src2 + 3;
    ft_memmove(dest, src, 5);
    memmove(dest2, src2, 5);

    printf("Resultado ft_memove: %s, %s\n", src, dest);
    printf("Resultado memmove: %s, %s\n", src2, dest2);
    free(src);
    free(src2);
    return (0);
}