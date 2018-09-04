/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 10:45:19 by dcherend          #+#    #+#             */
/*   Updated: 2018/08/06 18:16:02 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/21sh.h"

static _Bool	cmd_echo_cases(t_term *te, char *str)
{
	char		*var;

	ft_puts_except(str, '\"');
	ft_putchar(' ');
	return (1);
}

void			cmd_echo(t_term *te, char **strings)
{
	int			i;
	_Bool		endl;

	endl = 0;
	if (!strings)
		return ;
	i = -1;
	while (strings[++i])
	{
		if (endl)
			ft_putstr(" ");
		endl = cmd_echo_cases(te, strings[i]);
	}
	ft_putendl("");
}

static int		cmd_exec_woenv(t_term *te, char *bin, char **args)
{
	int			status;
	pid_t		child_pid;

	status = -1;
	if (access(bin, F_OK) == 0)
	{
		child_pid = fork();
		if (child_pid < 0)
			ft_putendl("Unable to fork pid");
		else if (child_pid == 0)
		{
			execve(bin, args, te->env);
		}
		else
			waitpid(child_pid, &status, 0);
		return (1);
	}
	return (0);
}

void			do_process(t_term *te, char *env, char **args)
{
	pid_t		child_pid;
	int			status;

	status = -1;
	child_pid = fork();
	if (child_pid < 0)
		ft_putendl("Unable to fork pid");
	else if (child_pid == 0)
	{
		g_curr_job = child_pid;
		execve(env, args, te->env);
	}
	else
	{
		g_curr_job = child_pid;
		waitpid(child_pid, &status, 0);
	}
}

int				cmd_exec(t_term *te, char *bin, char **args)
{
	char		**envpaths;
	int			i;


	i = -1;
	if (cmd_exec_woenv(te, bin, args))
		return (1);
	if (!(envpaths = get_envpaths(te, bin)))
		return (0);
	while (envpaths[++i])
		if (access(envpaths[i], F_OK) == 0)
		{
			if (access(envpaths[i], X_OK) != 0)
			{
				ft_putendl("Permission denied");
				ft_free_twodm(envpaths);
				return (1);
			}
			do_process(te, envpaths[i], args);
			ft_free_twodm(envpaths);
			g_curr_job = -1;
			return (1);
		}
	ft_free_twodm(envpaths);
	return (0);
}
