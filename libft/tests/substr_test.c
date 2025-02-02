#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

int main(void)
{
    char    *src;
    char    *result;

    src = "Hola mundo";
    result = ft_substr(src, 5, 5);

    printf("Resultado source: %s\n", src);
    printf("Resultado result: %s\n", result);
    free(result);
    return (0);
}