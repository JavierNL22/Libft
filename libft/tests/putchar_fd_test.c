#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft.h"

int main(void) {
    int fd;
    
    fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    ft_putchar_fd('A', fd);
    ft_putchar_fd('\n', fd);
    ft_putchar_fd('A', fd);

    close(fd);
    return 0;
}