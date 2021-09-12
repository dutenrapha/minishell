/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:33:05 by aalcara-          #+#    #+#             */
/*   Updated: 2021/09/12 13:48:08 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

char	*expand_word(char *key, int len)
{
	char	*aux;
	char	*realkey;

	if (len == 0)
		realkey = ft_substr(key, 1, ft_strlen(key));
	else
		realkey = ft_substr(key, 1, len - 1);
	printf("key = %s\n", realkey);// TODO finalizer expansão da variável $? (retorno)
	aux = ht_search(g_minishell.env, realkey);
	printf("value = %s\n", aux);// TODO finalizer expansão da variável $? (retorno)
	free(realkey);
	return (aux);
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

char	*ft_strjoinrealloc(char *s1, char *s2, int len)
{
	char	*aux;
	char	*aux2;
	int		s1len;

	s1len = ft_strlen(s1);
	aux = ft_substr(s2, 0, len);
	aux2 = malloc(sizeof(char) * (s1len + len + 1));
	aux2 = ft_strjoin(s1, aux);
	free(aux);
	free(s1);
	return (aux2);
}

bool	special_token(t_token *token, const char *str)
{
	int	res;

	res = ft_strcmp(token->value, str);
	if (res == 0)
		return (TRUE);
	return (FALSE);
}
