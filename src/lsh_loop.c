/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:00:48 by rdutenke          #+#    #+#             */
/*   Updated: 2021/09/16 17:15:09 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	print_tokens(t_token *tokens) //!REMOVER
{
	t_token	*aux;

	aux = tokens;
	printf("\n========= tokens ==========\n");
	while (aux)
	{
		printf("[type = %d]  [%s]\n", aux->type, aux->value);
		aux = aux->next;
	}
	printf("===========================\n\n");
}

void	lsh_loop(void)
{
	char	*line;
	int		status;
	t_token	*tokens;

	status = 1;
	while (status)
	{
		loop_signals();
		line = readline("\033[1;32mT-Rex\033[1;36mShell🦖\033[0m$ ");
		if (line == NULL)
		{
			ft_printf("exit\n");
			return ;
		}
		add_history(line);
		tokens = tokenizer(line);
		free(line);
		parse_tokens(tokens);
		free_tokens(&tokens);
	}
}
