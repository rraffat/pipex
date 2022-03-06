/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffat <rraffat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 04:03:17 by rraffat           #+#    #+#             */
/*   Updated: 2022/03/03 01:11:52 by rraffat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	openfile(char *filename, int mode)
{
	if (mode == INFILE)
	{
		if (access(filename, F_OK))
		{
			write(STDERR, "pipex: ", 7);
			write(STDERR, filename, ft_char(filename, 0));
			write(STDERR, "Sorry no file or directory\n", 27);
			return (STDIN);
		}
		return (open(filename, O_RDONLY));
	}
	else
		return (open(filename, O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IROTH));
}

char	*ft_path(char *cmd, char **env)
{
	char	*path;
	char	*dir;
	char	*ptr;
	int		i;

	i = 0;
	while (env[i] && ft_ncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (cmd);
	path = env[i] + 5;
	while (path && ft_char(path, ':') > -1)
	{
		dir = ft_dup(path, ft_char(path, ':'));
		ptr = ft_join(dir, cmd);
		free(dir);
		if (access(ptr, F_OK) == 0)
			return (ptr);
		free(ptr);
		path += ft_char(path, ':') + 1;
	}
	return (cmd);
}

void	exec(char *cmd, char **env)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (ft_char(args[0], '/') > -1)
		path = args[0];
	else
		path = ft_path(args[0], env);
	execve(path, args, env);
	write(STDERR, "pipex: ", 7);
	write(STDERR, cmd, ft_char(cmd, 0));
	write(STDERR, ": command not found\n", 20);
	exit(127);
}

void	redir(char *cmd, char **env, int fdin)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT);
		if (fdin == STDIN)
			exit(1);
		else
			exec(cmd, env);
	}
}

int	main(int argc, char **argv, char **env)
{
	int	fdin;
	int	fdout;

	if (argc == 5)
	{
		fdin = openfile(argv[1], INFILE);
		fdout = openfile(argv[4], OUTFILE);
		dup2(fdin, STDIN);
		dup2(fdout, STDOUT);
		redir(argv[2], env, fdin);
		exec(argv[3], env);
	}
	else
		write(STDERR, "Invalid number of arguments.\n", 29);
	return (1);
}
