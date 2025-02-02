#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

int main(void)
{
    char    *src;
    char    *dst;
    char    *src2;
    char    *dst2;
    size_t  result;
    size_t  result2;

    dst = ft_strdup("Hola ");
    src = "mundo!";
    src2 = ft_strdup(src);
    dst2 = ft_strdup(dst);
    result = ft_strlcat(dst, src, 9);
    result2 = strlcat(dst2, src2, 9);

    printf("Resultado ft_strlcat: %s, %s, %ld\n", src, dst, result);
    printf("Resultado strlcat: %s, %s, %ld\n", src2, dst2, result2);
    free(dst);
    free(src2);
    free(dst2);
    return (0);
}