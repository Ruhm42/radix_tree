/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_wrap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 14:57:03 by rda-cost          #+#    #+#             */
/*   Updated: 2015/06/03 13:06:12 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "radix.h"

static t_wrap	*new_wrap(char *str)
{
	t_wrap	*ret;

	if (!(ret = malloc(sizeof(t_wrap))))
		return (NULL);
	memset(ret, 0, sizeof(t_wrap));
	ret->str = str;
	return (ret);
}

void			wrap_build(t_wrap **start, t_wrap **cur, char *str)
{
	if (!str)
		return ;
	if (!*start)
	{
		*start = new_wrap(str);
		*cur = *start;
		(*cur)->next = *cur;
		(*cur)->prev = *cur;
		return ;
	}
	(*cur)->next = new_wrap(str);
	(*cur)->next->prev = *cur;
	(*cur)->next->next = *start;
	*cur = (*cur)->next;
}

static void		wrap_free_node(t_wrap *node)
{
	free(node->str);
	free(node);
}

void			wrap_free(t_wrap **start, t_wrap **cur)
{
	t_wrap	*save;
	t_wrap	*prev;

	if (!(*start))
		return ;
	if ((save = (*start)->prev) == (*start))
	{
		wrap_free_node(*start);
		*start = NULL;
		*cur = NULL;
		return ;
	}
	prev = NULL;
	while (*start != save)
	{
		if (prev)
			wrap_free_node(prev);
		prev = (*start)->prev;
		*start = (*start)->next;
	}
}
