/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 11:37:28 by aalcara-          #+#    #+#             */
/*   Updated: 2021/09/18 18:14:17 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	expand_variable(char *str, char **dest, int *i, int len)
{
	char	*aux;

	if (str[1] == '?')
		len = 2;
	aux = expand_word(str, len);
	if (aux)
		ft_strjoinrealloc(dest, aux, ft_strlen(aux));
	free(aux);
	*i = *i + len - 1;
	return ;
}

char	*expand_word(char *key, int len)
{
	char	*aux;
	char	*temp;
	char	*realkey;

	temp = NULL;
	if (len == 0)
		realkey = ft_substr(key, 1, ft_strlen(key));
	else
		realkey = ft_substr(key, 1, len - 1);
	if (key[1] == '?')
	{
		temp = ft_itoa(g_minishell.erro);
	}
	else
	{
		aux = ht_search(g_minishell.env, realkey);
		if (aux == NULL)
			aux = ht_search(g_minishell.local_var, realkey);
		if (aux)
			temp = ft_strdup(aux);
	}
	free(realkey);
	return (temp);
}

bool	check_is_closed(char *str, char quote)
{
	int	i;

	i = 1;
	while (str[i] != quote && str[i] != '\0')
		i++;
	if (str[i] == quote)
		return (TRUE);
	return (FALSE);
}

void	ft_strjoinrealloc(char **s1, char *s2, int len)
{
	char	*aux2;
	char	*aux1;

	aux1 = ft_strdup(*s1);
	aux2 = ft_substr(s2, 0, len);
	free(*s1);
	*s1 = ft_strjoin(aux1, aux2);
	free(aux1);
	free(aux2);
}

bool	special_token(t_token *token, const char *str)
{
	int	res;

	res = ft_strcmp(token->value, str);
	if (res == 0)
		return (TRUE);
	return (FALSE);
}
