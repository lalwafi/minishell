/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:29:27 by lalwafi           #+#    #+#             */
/*   Updated: 2024/09/16 23:50:41 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_lyall.h"

void	ft_lstadd_back(t_values **lst, t_values *new)
{
	t_values	*last;

	last = ft_lstlast(*lst);
	if (*lst)
		last -> next = new;
	else
		*lst = new;
}

void	ft_lstadd_front(t_values **lst, t_values *new)
{
	new -> next = *lst;
	*lst = new;
}

void	ft_lstclear(t_values **lst, void (*del)(void *))
{
	t_values	*a;

	while (*lst)
	{
		a = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = a;
	}
	*lst = NULL;
}

void	ft_lstdelone(t_values *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}

void	ft_lstiter(t_values *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}

t_values	*ft_lstlast(t_values *lst)
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

t_values	*ft_lstmap(t_values *lst, void *(*f)(void *), void (*del)(void *))
{
	t_values	*result;
	t_values	*head;
	t_values	*a;

	if (!lst || !del || !f)
		return (NULL);
	result = ft_lstnew(f(lst->content));
	if (!result)
		return (NULL);
	lst = lst->next;
	head = result;
	while (lst)
	{
		a = ft_lstnew(f(lst->content));
		if (!a)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, a);
		lst = lst->next;
	}
	return (head);
}

t_values	*ft_lstnew(void *content)
{
	t_values	*a;

	a = (t_values *)malloc(sizeof(*a));
	if (!a)
		return (NULL);
	a -> content = content;
	a -> next = NULL;
	return (a);
}

int	ft_lstsize(t_values *lst)
{
	t_values	*current;
	int		count;

	count = 0;
	if (!lst)
		return (0);
	current = lst;
	while (current != NULL)
	{
		current = current -> next;
		count++;
	}
	return (count);
}

