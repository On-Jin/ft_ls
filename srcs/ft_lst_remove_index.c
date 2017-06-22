/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 20:30:53 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/22 23:14:10 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list		*ft_lst_remove_index(t_list	**lst, size_t index)
{
	t_list	*past;
	t_list	*save;

	past = NULL;
	if (lst == NULL || *lst == NULL)
		return (NULL);
	while (*lst && index)
	{
		past = (*lst);
		lst = &(*lst)->next;
		index--;
	}
	if (!index && *lst)
	{
		save = *lst;
		if (!past)
			*lst = (*lst)->next;
		else
			past->next = (*lst)->next;
		return (save);
	}
	return (NULL);
}
