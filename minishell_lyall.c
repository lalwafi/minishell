/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_lyall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:27:37 by lalwafi           #+#    #+#             */
/*   Updated: 2024/09/13 22:09:05 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_lyall.h"

void	initialize_shell(t_shell *shell)
{
	shell->input = NULL;
	shell->fd = -1;
	shell->child = -1;
	shell->lastpid = -1;
	shell->str = NULL;
	shell->environment = NULL;
}

char *key_time(char *env)
{
	int	i;
	char	*key;
	i = 0;
	while(env[i] != '=')
		i++;
	key = malloc(sizeof(char) * (i + 1));
	i = -1;
	while(env[++i] != '=')
		key[i] = env[i];
	key[i] = '\0';
	return (key);
}

void	make_values_node(char *key, char *envline, t_shell *shell)
{
	t_values	*temp;

	temp = malloc(sizeof(t_values));
	temp->envstr = ft_strdup(envline);
	temp->key = ft_strdup(key);
	temp->value = getenv(temp->key);
	temp->next = NULL;
	ft_lstadd_back_values(&shell->environment->vals, temp);
}

void	get_env(t_shell *shell, char **env)
{
	int	i;
	char	*key;

	i = -1;
	shell->environment = malloc(sizeof(t_environment));
	shell->environment->exit = 0;
	shell->environment->cwd = getcwd(NULL, 0);
	shell->environment->owd = getcwd(NULL, 0);
	shell->environment->path = NULL;
	shell->environment->environ = NULL;
	shell->environment->vals = NULL;
	// change shlvl
	shell->environment->shlvl = 1;
	while (env[++i])
	{
		key = key_time(env[i]);
		make_values_node(key, env[i], shell);
		free(key);
	}
}

// void	change_shlvl(t_shell *shell)
// {
	
// }

void	minishell(t_shell *shell)
{
	while (1)
	{
		shell->input = readline("minishell> ");
		if (!shell->input)
			break ;
		else if (shell->input[0] != '\0')
			printf("got the input = %s\n", shell->input);
		else if (shell->input[0] == '\0')
			printf("???\n");
	}
}

int	main(int ac, char **av, char **env)
{
	t_shell shell;
	
	(void)av;
	if (ac != 1)
		return (printf("no arguments\n"));
	// int i = -1;
	// while (env[++i])
	// 	printf("%s\n", env[i]);

	// char *path = getenv("PATH");
    // if (path != NULL) {
    //     printf("PATH: %s\n", path);
    // } else {
    //     printf("PATH variable not found.\n");
    // }
	initialize_shell(&shell);
	// change_shlvl();
	get_env(&shell, env);
	sigaction()
	minishell(&shell);
	// int	j = -1;
	// while (shell.environment->vals)
	// {
	// 	printf("%d\t%s\n", ++j, shell.environment->vals->key);
	// 	printf("\t%s\n", shell.environment->vals->value);
	// 	printf("\t%s\n", shell.environment->vals->envstr);
	// 	shell.environment->vals = shell.environment->vals->next;
	// }
}
