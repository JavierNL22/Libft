#include <string.h>
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
    char    *str;
    char    *str2;
    int     length;
    
    str = ft_strdup("aaaaaaaaaa");
    ft_strlcpy(str2, str, ft_strlen(str) + 1);
    length = ft_strlen(str);
    ft_bzero(str, 5);
    bzero(str2, 5);

    printf("Resultado ft_bzero: ");
    print_buffer(str, length);
    printf("Resultado bzero: ");
    print_buffer(str2, length);
    free(str);
    free(str2);
    return (0);
}