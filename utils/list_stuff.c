/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:29:27 by lalwafi           #+#    #+#             */
/*   Updated: 2024/10/03 22:57:03 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_lyall.h"

int	ft_lstsize(t_values *lst)
{
	t_values	*current;
	int			count;

	count = 0;
	if (!lst)
		return (0);
	current = lst;
	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	return (count);
}

t_values	*ft_lstlast_values(t_values *lst)
{
	int	i;

	if (!lst)
		return (NULL);
	i = ft_lstsize(lst);
	while (i > 1)
	{
		lst = lst -> next;
		i--;
	}
	return (lst);
}

void	ft_lstadd_back_values(t_values **lst, t_values *new)
{
	t_values	*last;

	last = ft_lstlast_values(*lst);
	if (*lst)
		last -> next = new;
	else
		*lst = new;
}
