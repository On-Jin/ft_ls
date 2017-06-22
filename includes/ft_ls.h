/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 11:53:46 by ntoniolo          #+#    #+#             */
/*   Updated: 2017/06/23 00:04:20 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include "../libft/includes/ft_printf.h"
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h> 
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <sys/xattr.h>

# define NUM_TYPE 0
# define NUM_USR 1
# define NUM_GRP 4
# define NUM_OTH 7
# define NUM_R 0
# define NUM_W 1
# define NUM_X 2
# define ALL_R 7894898

# define FLAG_L (1 << 1)
# define FLAG_R (1 << 2)
# define FLAG_A (1 << 3)
# define FLAG_RV (1 << 4)
# define FLAG_T (1 << 5)

typedef struct	s_elem
{
	char		*path;
	char		mode[11];
	size_t		size;
	size_t		atime;
	size_t		nlink;
	char		*p_name;
	char		*g_name;
}				t_elem;

typedef struct	s_env
{
	int			flag;
	t_list		*file;
	t_list		*dir;
	t_list		*temp;
	t_list		*not_here;
}				t_env;

t_list			*ft_lst_remove_index(t_list **lst, size_t index);
t_list			*ft_lst_remove(t_list **lst, t_list *remove);
void			ft_lstinsert_alphabet(t_list **lst, t_list *new);


void			pars_arg(t_env *e, int argc, char **argv, int *i);
int				ls_recup_file_from_arg(t_env *e);

void			ls_type_and_file_right(unsigned long st_mode, char *tab);

void			ls_free_temp(t_list **lst);

#endif
