#include "../../inc/21sh.h"

void			init_pipethreads(t_term *te, t_token *tok)
{
	char		**cmd;
	int			pipefd[2];
	pid_t		pid;

	pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		dup2(pipefd[0], 0);
		close(pipefd[1]);
		execve("ls", (char *const *)"-l", te->env);
	}
	else if (pid < 0)
		ft_putendl("Unable to fork pid");
	else
	{
		dup2(pipefd[1], 1);
		close(pipefd[0]);
		execve("ls", (char *const *)"-l", te->env);
	}
}

void			init_redirthreads(t_term *te, t_token *tok)
{
	int 		in;
	int			out;

	in = open("scores", O_RDONLY);
	out = open("out", O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
	dup2(in, 0);
	dup2(out, 1);
	close(in);
	close(out);
	execvp(&tok->left[0], &tok->left);
}

void			init_heredocthreads(t_term *te, t_token *tok)
{
	
}