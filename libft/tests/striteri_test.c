#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

void    funct(unsigned int i, char *c)
{
    *c = *c + i;
}

int main(void)
{
    char    *result;

    result = ft_strdup("1234");
    ft_striteri(result, funct);
    printf("Resultado: %s\n", result);
    free(result);
    return (0);
}