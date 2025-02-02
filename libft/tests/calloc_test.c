#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

void    print_buffer(char *buffer, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (buffer[i] == '\0')
            printf(".");
        else
            printf("%c", buffer[i]);
        i++;
    }
    printf("\n");
}

int main(void)
{
    char    *result;
    char    *result2;

    result = ft_calloc(3, 5);
    result2 = calloc(3, 5);
    printf("Resultado ft_calloc: ");
    print_buffer(result, 3*12);
    printf("Resultado calloc: ");
    print_buffer(result2, 3*12);
    free(result);
    free(result2);
    return (0);
}
