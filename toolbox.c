/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:32:10 by varodrig          #+#    #+#             */
/*   Updated: 2024/10/06 16:26:26 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

int	ft_putstr_fd(char *s, int fd)
{
	int i;

	i = 0;
	while(s[i])
		write(fd, &s[i++], sizeof(char));
	return(i);
}
