/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 15:23:31 by dcherend          #+#    #+#             */
/*   Updated: 2018/08/06 20:12:50 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/21sh.h"

int					complete(int a)
{
	return ((int)write(STDERR_FILENO, &a, 1));
}

void				reset_input_mode(void)
{
	tcsetattr(STDERR_FILENO, TCSANOW, &g_sa);
}

void				set_input_mode()
{
	struct termios	tattr;
	char			buf[1024];

	if (!isatty(STDIN_FILENO))
	{
		ft_putstr_fd("Not a terminal.\n", 2);
		exit(0);
	}
	tcgetattr(STDIN_FILENO, &g_sa);
	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag &= ~(ICANON|ECHO);
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	if ((tgetent(buf, getenv("TERM"))) == ERR)
	{
		ft_putstr_fd("TERM environment variable not set.\n", 2);
		ft_putstr_fd("WARNING: terminal is not fully functional\n", 2);
	}
	tcsetattr(STDERR_FILENO, TCSANOW, &tattr);
}

static void			sh_lvl(t_term **te)
{
	char			*shvar;
	int				lvl;

	shvar = get_var(*te, "SHLVL");
	lvl = ft_atoi(shvar) + 1;
	free(shvar);
	shvar = ft_itoa(lvl);
	set_var(*te, "SHLVL=", shvar);
	free(shvar);
}

t_term				*init_term(void)
{
	struct winsize	ws;
	t_term			*te;

	te = (t_term*)malloc(sizeof(t_term));
	if (!te)
		return (NULL);
	ioctl(0, TIOCGWINSZ, &ws);
	te->env = get_env();
	sh_lvl(&te);
	te->am_quotes = 0;
	te->am_dquotes = 0;
	te->q_iterator = 0;
	te->q_end = 0;
	te->ws_cols = ws.ws_col;
	te->ws_rows = ws.ws_row;
	te->hst = init_history();
	return (te);
}