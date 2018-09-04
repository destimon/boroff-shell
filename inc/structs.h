/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 14:57:17 by dcherend          #+#    #+#             */
/*   Updated: 2018/08/06 20:12:09 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INC_21SH_STRUCTS_H
#define INC_21SH_STRUCTS_H

#include <sys/syslimits.h>

typedef struct		s_token
{
	int				op;
	char			*left;
	char			*right;
	struct s_token	*next;
}					t_token;

typedef struct		s_history
{
	char			**h_ptr;
	int				h_iterator;
	int				h_size;
	int				h_capacity;
}					t_history;

typedef struct		s_term
{
	char			**env;
	/*
	 * Query
	 */
	char			query[ARG_MAX];
	int				q_iterator;
	int				q_end;
	/*
	 * Expansions
	 */
	int				am_quotes;
	int				am_dquotes;
	/*
	 * Terminal
	 */
	int				ws_cols;
	int				ws_rows;
	/*
	 * Structs
	 */
	t_history		*hst;
}					t_term;

#endif
