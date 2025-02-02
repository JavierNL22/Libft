#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

void del(void *content)
{
    free(content);
}

void print_content(void *content)
{
    printf("%s\n", (char *)content);
}

void *duplicate_content(void *content)
{
    char    *new_content = ft_substr(content, 5, 2);
    if (!new_content)
        return (NULL);
    return (new_content);
}

int main(void)
{
    t_list *list = ft_lstnew(ft_strdup("Nodo 1"));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("Nodo 2")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("Nodo 3")));

    printf("Lista:\n");
    ft_lstiter(list, print_content);
    
    t_list *node2 = list->next;
    list->next = node2->next;
    ft_lstdelone(node2, del);
    
    printf("Lista tras eliminar segundo nodo:\n");
    ft_lstiter(list, print_content);
    
    t_list *new_list = ft_lstmap(list, duplicate_content, del);
    printf("Nueva lista tras ft_lstmap:\n");
    ft_lstiter(new_list, print_content);
    
    ft_lstclear(&list, del);
    ft_lstclear(&new_list, del);
    
    printf("Listas borradas:\n");
    ft_lstiter(new_list, print_content);
    ft_lstiter(list, print_content);
    return 0;
}
