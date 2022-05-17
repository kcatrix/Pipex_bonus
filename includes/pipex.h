/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:45:36 by kevyn             #+#    #+#             */
/*   Updated: 2022/05/17 12:03:33 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "macro.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct process	process;

struct process
{
	int process_num;
};

int		pipex(int argc, char **argv, char **env);
char	get_error(int i);
char	**path_fct(char **env);
int		verif_file(int argc, char **argv);
int		verif_exist(char **path, char *argv);
int		child_process(char **argv, char **path, char **env, int *fd);
int		parent_process(char **argv, char **path, char **env, int *fd);

#endif
