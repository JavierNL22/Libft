#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

int main(void)
{
    char    *result;

    result = ft_strjoin("Hola ", "Mundo!");

    printf("Resultado result: %s\n", result);
    free(result);
    return (0);
}