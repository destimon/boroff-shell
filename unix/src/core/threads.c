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



static void			pair_proccesses(t_term *te, t_token *tok, int pipes[2])
{
	pid_t pid;
	int pipes2[2];
	t_bincmd bcmd;

	if (!tok || tok->op != '|')
	{
		close(pipes[0]);
		close(pipes[1]);
		return ;
	}
	bcmd = solve_bincmd(te, tok->right);
	pipe(pipes2);
	if (bcmd.file)
	{
		pid = fork();
		if (pid == 0)
		{
			dup2(pipes[0], STDIN_FILENO);
			if (tok->next)
			{
				dup2(pipes2[1], STDOUT_FILENO);
				close(pipes[0]);
				close(pipes[1]);
			}
			close(pipes2[0]);
			close(pipes2[1]);
			execve(bcmd.file, bcmd.argv, te->env);
			_exit(1);
		}
		free_bincmd(bcmd);
	}
	close(pipes[1]);
	wait(NULL);
	pair_proccesses(te, tok->next, pipes2);
}



static void			solve_pipe(t_term *te, t_token *tok)
{
	int pipes[2];
	int pipes2[2];
	pid_t pid;
	pid_t pid2;

	t_bincmd bcmd1 = solve_bincmd(te, tok->left);
	t_bincmd bcmd2 = solve_bincmd(te, tok->right);
	pipe(pipes);
	pid = fork();
	if (pid == 0)
	{
		dup2(pipes[1], STDOUT_FILENO);
		close(pipes[0]);
		// close(pipes[1]);
		execve(bcmd1.file, bcmd1.argv, te->env);
		_exit(1);
	}
	close(pipes[1]);
	wait(NULL);
	free_bincmd(bcmd1);
	pipe(pipes2);
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(pipes[0], STDIN_FILENO);
		if (tok->next)
			dup2(pipes2[1], STDOUT_FILENO);
		close(pipes[0]);
		close(pipes[1]);
		close(pipes2[0]);
		close(pipes2[1]);
		execve(bcmd2.file, bcmd2.argv, te->env);
		_exit(1);
	}
	close(pipes2[1]);
	wait(NULL);
	pair_proccesses(te, tok->next, pipes2);
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