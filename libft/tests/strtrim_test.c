#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

int main(void)
{
    char    *result;

    result = ft_strtrim("aaaaaaaaaaHolax Mundoeeeeeeeeeeee", "aex");

    printf("Resultado result: %s\n", result);
    free(result);
    return (0);
}