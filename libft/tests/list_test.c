#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

int main(void)
{
    char *data = "Hola mundo!";
    t_list *node = ft_lstnew((void *)data);

    printf("Contenido nodo: %s\n", (char *)node->content);

    data = "add front";
    t_list *nodefront = ft_lstnew(data);
    ft_lstadd_front(&node, nodefront);

    printf("Contenido nodofront: %s\n", (char *)nodefront->content);

    printf("lstsize: %d\n", ft_lstsize(nodefront));

    data = "add back";
    t_list *nodeback = ft_lstnew(data);
    ft_lstadd_back(&nodefront, nodeback);

    printf("Contenido nodoback: %s\n", (char *)nodeback->content);

    printf("lstsize: %d\n", ft_lstsize(nodefront));

    printf("content nodo final: %s\n", (char *)ft_lstlast(nodefront)->content);

    return (0);
}