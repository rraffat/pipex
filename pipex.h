/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffat <rraffat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:39:44 by rraffat           #+#    #+#             */
/*   Updated: 2022/03/02 18:08:19 by rraffat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>

//# include <errno.h>
//# include <stdio.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define INFILE 0
# define OUTFILE 1

//char	*ft_path(char *cmd, char **env);
//void	exec(char *cmd, char **env);
//void	redir(char *cmd, char **env, int fdin);
//int		openfile(char *filename, int mode);
char	**ft_split(char *str, char c);
char	*ft_join(char *join, char *str);
int		ft_ncmp(char *str1, char *str2, int n);
char	*ft_dup(char *str, unsigned int n);
int		ft_char(char *str, char c);

#endif
