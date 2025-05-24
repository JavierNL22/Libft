/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:14:21 by jnavalla          #+#    #+#             */
/*   Updated: 2025/01/28 13:14:32 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*object;

	if (lst)
	{
		object = *lst;
		while (object)
		{
			*lst = object->next;
			ft_lstdelone(object, del);
			object = *lst;
		}
	}
}
