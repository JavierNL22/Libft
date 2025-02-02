#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

int main(void)
{
    char    *str;
    char    *str2;
    str = ft_strdup("aaaaaaaaaa");
    ft_memcpy(str2, str, ft_strlen(str) + 1);
    ft_memset(str, 'c', 5);
    memset(str2, 'c', 5);

    printf("Resultado ft_memset: %s\n", str);
    printf("Resultado memset: %s\n", str2);
    free(str);
    return (0);
}