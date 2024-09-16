/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:54:22 by lalwafi           #+#    #+#             */
/*   Updated: 2024/09/16 19:54:45 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_lyall.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*copy;

	i = 0;
	copy = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!copy)
		return (NULL);
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
