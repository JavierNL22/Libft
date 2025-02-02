#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft.h"

int main(void) {
    char    *str;
    int fd;

    fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    str = ft_strdup("hola mundo");
    //ft_putstr_fd(str, fd);
    //ft_putendl_fd(str, fd);
    ft_putnbr_fd(11223344, fd);

    close(fd);
    free(str);
    return 0;
}