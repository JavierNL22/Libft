#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

int main(void)
{
    char    *result;

    result = ft_itoa(125125);

    printf("Resultado: %s\n", result);
    return (0);
}