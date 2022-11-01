/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepierr <jdepierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:01:12 by jdepierr          #+#    #+#             */
/*   Updated: 2022/10/19 17:08:43 by jdepierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*to_clear;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		to_clear = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = to_clear;
	}
	*lst = NULL;
}
