/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:18:36 by kevyn             #+#    #+#             */
/*   Updated: 2022/05/17 14:37:34 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	pipex(int argc, char **argv, char **env)
{
	int		pid;
	int		pids[argc - 3];
	int		i;
	int		fd[2];
	char	**path;

	
	pid = argc - 3;
	i = 1;
	if (verif_file(argc, argv) != 0)
		return (verif_file(argc, argv));
	path = path_fct(env);
	pipe(fd);
	while (i != pid)
		pids[i] = fork();
	if (pid == -1)
		return (3);
	if (pid == 0)
	{
		if (child_process(argv, path, env, fd) == 3)
			return (3);
	}
	else
	{
		if (parent_process(argv, path, env, fd) == 3)
			return (3);
	}
	close(fd[0]);
	close(fd[1]);
	return (0);
}
