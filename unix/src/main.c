/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 15:09:21 by dcherend          #+#    #+#             */
/*   Updated: 2018/08/04 18:05:46 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/21sh.h"

//◦ malloc, free
//◦ access
//◦ open, close, read, write
//◦ opendir, readdir, closedir
//◦ getcwd, chdir
//◦ stat, lstat, fstat
//◦ fork, execve
//◦ wait, waitpid, wait3, wait4
//◦ signal, kill
//◦ exit
//◦ pipe
//◦ dup, dup2
//◦ isatty, ttyname, ttyslot
//◦ ioctl
//◦ getenv
//◦ tcsetattr, tcgetattr
//◦ tgetent
//◦ tgetflag
//◦ tgetnum
//◦ tgetstr
//◦ tgoto
//◦ tputs

void			print_borroff()
{
	ft_putendl("\t         (__) \n"
				   "\t         (oo) ШО?\n"
				   "\t   /------\\/ \n"
				   "\t  / |    ||   \n"
				   "\t *  /\\---/\\ \n"
				   "\t    ~~   ~~   \n"
					   "\tboroff shell alpha\n"
					   "\t(c) dcherend");
}

void			init_loop()
{
	t_term		*te;

	set_input_mode();
	te = init_term();
	show_prompt(te);
	while (is_user_a_goat())
	{
		signals(te);
		wait_input(te);
	}
}

int				main(void)
{
	print_borroff();
	init_loop();
	return 0;
}