/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_lyall.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:36:49 by lalwafi           #+#    #+#             */
/*   Updated: 2024/09/13 22:08:38 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>
# include <string.h>
# include <dirent.h>
# include <sys/stat.h>
# include <errno.h>
# include <termios.h>
# include <curses.h>
# include <term.h>

typedef struct s_environment	t_environment;
typedef struct s_shell			t_shell;
typedef struct s_values			t_values;

typedef struct s_shell
{
	int     fd;
	pid_t   child;
	pid_t   lastpid;
	char    *str;
	t_environment   *environment;
	
} t_shell;

typedef struct s_environment
{
	int			exit;
	int			shlvl;
	char		*cwd;
	char		*owd;
	char		**path;
	char		**environ;
	t_values	*vals;
	t_shell		*shell;
}	t_environment;

typedef struct s_values
{
	char		*key;
	char		*value;
	char		*str;
	t_values	*next;
} t_values;

// functions lyall

void	get_env(t_shell *shell, char **env);
char	*key_time(char *env);
void	initialize_shell(t_shell *shell);


#endif