#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

char    funct(unsigned int i, char c)
{
    c = c + i;
    return (c);
}

int main(void)
{
    char    *result;

    result = ft_strmapi("1234", funct);
    printf("Resultado: %s\n", result);
    free(result);
    return (0);
}