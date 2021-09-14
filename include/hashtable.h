/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 21:04:09 by aalcara-          #+#    #+#             */
/*   Updated: 2021/09/14 00:42:23 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

# include <stdlib.h>
# define TRUE 1
# define false 0

typedef struct s_ht_item
{
	char				*key;
	char				*value;
	struct s_ht_item	*next;
}						t_ht_item;

typedef struct s_hashtable
{
	t_ht_item	**items;
	int			size;
	int			count;
}				t_hashtable;

unsigned long	hash_function(char *str, unsigned int size);
char		**hashtable_to_array(t_hashtable *table);
// insert
void		ht_insert(t_hashtable *table, char *key, char *value);
// search
char		*ht_search(t_hashtable *table, char *key);
int		ht_bool_search(t_hashtable *table, char *key);
// delete
void		ht_delete(t_hashtable *table, char *key);
// create
t_ht_item	*create_item(char *key, char *value);
t_hashtable	*create_table(int size);
// free
void		free_item(t_ht_item *item);
void		free_table(t_hashtable *table);
#endif