#ifndef LEMIN_H
# define LEMIN_H

# include <stdio.h>
# include "../libft/includes/libft.h"
# include <stdlib.h>

typedef struct		s_node_list
{
	char			*name;
	struct s_node_list	*neighbour;
	struct s_node_list	*next;
	int				start_end;
	int				x;
	int				y;
}					t_node_list;

typedef struct		s_node
{
	int 			number;
	char			*name;

	struct s_node	*parent;
	int				weight;

	int				*neighbour;
	int				start_end;
}					t_node;

typedef struct		s_link
{
	int				a;
	int				b;
}					t_link;


typedef struct		s_room
{
	int				x;
	int				y;
	char			*name;
}					t_room;

typedef struct		s_vars
{
	t_node			*nodes;
	t_link			*links;
	int				start_node;
	int				end_node;
	int				ants;
	char 			*result;

	int				flag_start;
	int				flag_end;

	t_node_list		*head;
}					t_vars;

int ft_str_is_num(char *str);
void	*ft_free_arr(void **arr);
char	*ft_strjoin_free(char *s1, char const *s2);


void	ft_comment_command(char *str, t_vars *vars);
int 	ft_is_ants(char *str, t_vars *vars);
int		ft_is_room(char *str, t_vars *vars);
int 	ft_is_link(char *str, t_vars *vars);
void	ft_error(int i);
void	ft_counter(char *str, t_vars *vars);


void	ft_parser(t_vars *vars);
void 	ft_find_ants(t_vars *vars);
int		ft_is_comment_command(char *str, t_vars *vars);
void	ft_error(int i);

#endif

/*
пустой коммент #
комнаты среди линков и линки среди комнат
невалидные комнаты, невалидные линки
лишний пробел
L
2 start, 2 end;

валидация одинаковых координат комнат и имен


*/