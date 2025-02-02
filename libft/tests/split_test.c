#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

int main(void)
{
    char    **result;
    int i;

    i = 0;
    result = ft_split("Hola muy buenas tardes", ' ');

    while (result[i] != 0)
    {
        printf("%s\n", result[i]);
        free(result[i]);
        i++;
    }
    free(result);
    return (0);
}