# include <fcntl.h>   // Para open() TESTS
# include <stdio.h>

int main(void)
{
	int fd = open("read_error.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error abriendo el archivo");
        return (1);
    }

    char *line;
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}