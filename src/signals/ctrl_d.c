/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcahall <dcahall@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:41:13 by dcahall           #+#    #+#             */
/*   Updated: 2022/05/08 12:49:44 by dcahall          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ctrl_d(void)
{
	ft_putendl_fd("exit", STDOUT_FILENO);
	exit(EXIT_SUCCESS);
}