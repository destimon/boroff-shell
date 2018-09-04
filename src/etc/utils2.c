/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 15:06:19 by dcherend          #+#    #+#             */
/*   Updated: 2018/08/04 16:45:19 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/21sh.h"

void			help_out(void)
{
	ft_putstr(ANSI_BOLD_GREEN);
	ft_putendl("#\t>>> 21 sh <<<");
	ft_putendl("#");
	ft_putstr(ANSI_BOLD_WHITE);
	ft_putstr("#\techo [arg ...]\n#\tenv [utility [argument ...]]\n#\t");
	ft_putstr("setenv [name[=value] ...]\n#\tunsetenv [name ...]\n#\t");
	ft_putstr("cd [arg ...]\n#\texit\n#\n");
	ft_putstr(ANSI_COLOR_RED);
	ft_putstr("#\tAuteur: dcherend\n");
	ft_putstr(ANSI_COLOR_GREEN);
	ft_putendl("#\n#\t>>> 21 sh <<<");
	ft_putstr(ANSI_COLOR_RESET);
}

char			*tilde_handler(t_term *te, const char *string)
{
	char		*cuted;
	char		*home;

	if (string[0] == '~')
	{
		home = get_var(te, "HOME");
		if (home)
		{
			if (string[1])
			{
				cuted = ft_strjoin(home, &string[1]);
				free(home);
				return (cuted);
			}
			else
				return (home);
		}
	}
	return ((char*)string);
}

char			*var_namecut(const char *var)
{
	char		*name;

	if ((name = ft_strdupch(var, '=')))
	{
		return (name);
	}
	return (NULL);
}

void		cursor_left(int times)
{
	int		i;

	i = 0;
	while (i < times)
	{
		tputs(tgetstr("le", NULL), 1, &complete);
		i++;
	}
}

void		cursor_right(int times)
{
	int		i;

	i = 0;
	while (i < times)
	{
		tputs(tgetstr("nd", NULL), 1, &complete);
		i++;
	}
}