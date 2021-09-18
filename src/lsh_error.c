/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:47:31 by aalcara-          #+#    #+#             */
/*   Updated: 2021/09/18 12:24:45 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	error_return(char *input, char *error_message, int status)
{
	char	*output;
	int		len;

	len = 12 + 2 + 1 + ft_strlen(input) + ft_strlen(error_message);
	output = ft_calloc(len, sizeof(char));
	ft_strcpy(output, "minishell: ");
	ft_strlcat(output, input, ft_strlen(input) + ft_strlen(output) + 1);
	ft_strlcat(output, ": ", ft_strlen(": ") + ft_strlen(output) + 1);
	len = ft_strlen(error_message) + ft_strlen(output) + 1;
	ft_strlcat(output, error_message, len);
	ft_putendl_fd(output, 2);
	g_minishell.erro = status;
	free(output);
}
