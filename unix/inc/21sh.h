/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 15:04:59 by dcherend          #+#    #+#             */
/*   Updated: 2018/08/06 18:27:03 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INC_21SH_21SH_H
#define INC_21SH_21SH_H

#include "../lib/libft/libft.h"
#include "../lib/libft/get_next_line.h"
#include <stdlib.h>
#include <termcap.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/param.h>
#include <signal.h>
#include <termios.h>
#include <dirent.h>
#include <sys/stat.h>
#include <ftw.h>
#include <unistd.h>
#include <stdbool.h>
#include "structs.h"

/*
** pipe, redirect, double redirect and heredoc.
*/
# define B_EMPT				0
# define B_PIPE				1
# define B_REDI				2
# define B_DRED				3
# define B_HERE				4

/*
** COLORS.
*/
# define ANSI_COLOR_RED		"\x1b[31m"
# define ANSI_COLOR_GREEN	"\x1b[32m"
# define ANSI_COLOR_YELLOW	"\x1b[33m"
# define ANSI_COLOR_BLUE	"\x1b[34m"
# define ANSI_COLOR_MAGENTA	"\x1b[35m"
# define ANSI_COLOR_CYAN	"\x1b[36m"
# define ANSI_COLOR_RESET	"\x1b[0m"
# define ANSI_BOLD_GREEN	"\e[1;32m"
# define ANSI_BOLD_WHITE	"\e[1;37m"

/*
**  ERRORS.
*/
# define ERR_CD_MANYARGS	"too many arguments"
# define ERR_CD_UNEXIST		"no such file or directory"
# define ERR_CD_UNACCESS	"Permission denied."

/*
** KEYBOARD.
*/
# define KEY_Q		113
# define KEY_ESC	27
# define L_ARROW	4479771
# define R_ARROW	4414235
# define UP_ARROW	4283163
# define DOWN_ARROW	4348699
# define KEY_SPACE	32
# define KEY_RETURN	10
# define KEY_BACK	127
# define KEY_DEL	2117294875
# define PG_UP		2117425947
# define PG_DOWN	2117491483
# define CTRL_D		4
# define CTRL_E		5
# define CTRL_A		1
# define ALT_RIGHT	1130044187
# define ALT_LEFT	1146821403
# define CMD_V		2333758649037711114
# define BACKSPACE	127
# define KEY_ENTER	10

/*
** GLOBAL VARIABLES.
*/
struct termios	g_sa;
pid_t			g_curr_job;

/*
** DIR: CMD -------------------------------------------------------------------
*/
/*
** CMD.
*/
void		cmd_echo(t_term *te, char **strings);
int			cmd_exec(t_term *te, char *bin, char **argc);
/*
** CMD_CD.
*/
void		cmd_cd(t_term *te, char **dirs);
/*
** CMD_ENV.
*/
void		cmd_env(t_term *te, char **args);
void		cmd_setenv(t_term *te, char **envs);
int			cmd_resetenv(t_term *te, char *name, char *env);
void		cmd_unsetenv(t_term *te, char **envs);

/*
** DIR: CORE ------------------------------------------------------------------
*/
/*
** CORE.
*/
void		wait_input(t_term *te);
/*
** EXECUTE.
*/
void		commands_space(t_term *te, char *input);
/*
** BTREE.
*/
int			catch_pipes(char *cmd);

/*
** DIR: INPUT -----------------------------------------------------------------
*/
/*
** INPUT.
*/
void		key_esc(t_term *te);
void		key_return(t_term *te);
void		key_space(t_term *te);
void		key_backspace(t_term *te);
void		key_delete(t_term *te);
/*
** INPUT2.
*/
void		key_left(t_term *te);
void		key_right(t_term *te);
void		key_up(t_term *te);
void		key_down(t_term *te);
/*
** COMBINATIONS.
*/
void		ctrl_d(t_term *te);

/*
** QU_DELETER.
*/
void		ft_deletechars(int size);
void		ft_outputchars(char *str);
/*
** MOVING.
*/
void		key_ctrlleft(t_term *te);
void		key_ctrlright(t_term *te);
void		key_ctrle(t_term *te);
void		key_ctrla(t_term *te);

/*
** DIR: ETC -------------------------------------------------------------------
*/
/*
** SIGNALS.
*/
void		signals(t_term *te);
/*
** ENVIRON.
*/
char		**get_env(void);
void		set_var(t_term *te, char *name, char *var);
char		*get_var(t_term *te, const char *var);
/*
** ENVMANAGE.
*/
char		**realloc_env(t_term *te, size_t size);
int			is_exist(char **todel, char *env);
/*
** UTILS.
*/
char		*path_homecut(const char *path);
char		*get_path(void);
char		**get_envpaths(t_term *te, const char *bin);
int			search_env(t_term *te, int *i);
/*
** UTILS2.
*/
void		help_out(void);
char		*var_namecut(const char *var);
char		*tilde_handler(t_term *te, const char *string);
void		cursor_left(int times);
void		cursor_right(int times);
/*
** ERROR.
*/
void		unknown_cmd(char *cmd);
void		cd_errors(char *err);
/*
** HISTORY.
*/
t_history	*init_history(void);
void		push_history(t_history *hst, char *cont);

/*
** QUOTES.
*/
void		quote_handler(t_term *te, char *input);

/*
** DIR: INTERFACE -------------------------------------------------------------
*/
/*
** UI.
*/
void		show_prompt(t_term *te);
/*
** TERM.
*/
t_term		*init_term(void);
void		set_input_mode(void);
void		reset_input_mode(void);
int			complete(int a);

#endif
