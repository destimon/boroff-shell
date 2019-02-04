#include "../../inc/21sh.h"

void			thread_manager(t_term *te, t_token *tok)
{
	if (tok)
	{
		if (tok->op == B_PIPE)
			init_pipethreads(te, tok);
		else if (tok->op == B_REDI)
			init_redirthreads(te, tok);
		else if (tok->op == B_BRED)
			init_bredthreads(te, tok);
	}
}

static void			solve_pipe(t_term *te, t_token *tok)
{
	int pipefd[2];
	t_bincmd bcmd1;
	t_bincmd bcmd2;
	pid_t pid1;
	pid_t pid2;

	bcmd1 = solve_bincmd(te, tok->left);
	bcmd2 = solve_bincmd(te, tok->right);
	pipe(pipefd);
	if (bcmd1.file)
	{
		pid1 = fork();
		if (pid1 == 0)
		{
			dup2(pipefd[1], STDOUT_FILENO);
			close(pipefd[0]);
			execve(bcmd1.file, bcmd1.argv, te->env);
			return ;
		}
		free_bincmd(bcmd1);
	}
	if (bcmd2.file)
	{
		pid2 = fork();
		if (pid2 == 0)
		{
			dup2(pipefd[0], STDIN_FILENO);
			close(pipefd[1]);
			execve(bcmd2.file, bcmd2.argv, te->env);
			return ;
		}
		free_bincmd(bcmd2);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	int st = 0;
	waitpid(pid1, &st, 0);
	waitpid(pid2, &st, 0);
}

void			init_pipethreads(t_term *te, t_token *tok)
{	
	// tok = tok->next;
	// while (tok)
	// {
		solve_pipe(te, tok);
		// tok = tok->next;
	// }
}

void			init_redirthreads(t_term *te, t_token *tok)
{
	char		**cmd;
	char		**cmd2;
	pid_t		pid;
	int 		in;
	int			out;
	int			status;

	pid = fork();
	if (pid == 0)
	{
		cmd = ft_strsplit_many(tok->right, ARR_WHITE_SPACES);
		cmd2 = ft_strsplit_many(tok->left, ARR_WHITE_SPACES);
		if (!cmd || !cmd2)
			return ;
		in = open(tok->left, O_RDONLY);
		dup2(in, STDIN_FILENO);
		close(in);
		out = open(cmd[0], O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
		dup2(out, STDOUT_FILENO);
		close(out);
		thread_manager(te, tok->next);
		execve(cmd2[0], cmd2, te->env);
		ft_two_del(cmd);
		ft_two_del(cmd2);
	}
	else
		wait(&status);
}

void			init_bredthreads(t_term *te, t_token *tok)
{

}

void			init_heredocthreads(t_term *te, t_token *tok)
{
	
}