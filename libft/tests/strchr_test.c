#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

int main(void)
{
    char    *result;
    char    *result2;

    result = ft_strchr("Hola Mundo!", ' ');
    result2 = strchr("Hola Mundo!", ' ');

    printf("Resultado ft_strchr: %s\n", result);
    printf("Resultado strchr: %s\n", result2);
    return (0);
}