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

void			init_pipethreads(t_term *te, t_token *tok)
{
	char		**cmd;
	char		**cmd2;
	int			pipefd[2];
	pid_t		pid;
	pid_t		pid2;
	int			status;

	cmd = ft_strsplit(tok->left, ' ');
	cmd2 = ft_strsplit(tok->right, ' ');
	if (access(cmd[0], F_OK) == 0)
	{
		pid = fork();
		// set_input_mode();
		if (pid == 0)
		{
			pipe(pipefd);
			if (access(cmd[0], F_OK) == 0)
			{
				pid2 = fork();
				if (pid2 == 0)
				{
					dup2(pipefd[1], 1);
					close(pipefd[0]);
					execve(cmd[0], cmd, te->env);
				}
				else
					wait(&status);
			}
			dup2(pipefd[0], 0);
			close(pipefd[1]);
			thread_manager(te, tok->next);
			execve(cmd2[0], cmd2, te->env);
		}
		else
			wait(&status);
	}
	ft_free_twodm(cmd);
	ft_free_twodm(cmd2);
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