#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

int main(void)
{
    char    *result;
    char    *result2;

    result = ft_strrchr("Hola Mun do!", ' ');
    result2 = strrchr("Hola Mun do!", ' ');

    printf("Resultado ft_strrchr: %s\n", result);
    printf("Resultado strrchr: %s\n", result2);
    return (0);
}