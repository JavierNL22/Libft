#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

int main(void)
{
    char    *s1;
    char    *s2;

    s1 = ft_strdup("Hola Mundo");
    s2 = ft_strdup("Holc Mundo");

    printf("Resultado ft_strncmp: %d\n", ft_strncmp(s1, s2, 5));
    printf("Resultado strncmp: %d\n", strncmp(s1, s2, 5));
    free(s1);
    free(s2);
    return (0);
}