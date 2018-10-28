/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <iyerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:31:51 by iyerin            #+#    #+#             */
/*   Updated: 2018/10/28 14:03:21 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

int 	ft_one_dash(char *str)
{
	int dash;

	dash = 0;
	while (*str)
	{
		if (*str == '-')
			dash++;
		str++;
	}
	if (dash == 1)
		return (1);
	return (0);
}

int 	ft_is_room_name(char *str)
{
	ft_strlen(str);
	return (1);/////////////////////////////////////fix
}

int 	ft_both_parts_are_rooms_names(char *str)
{
	char **arr;

	arr = ft_strsplit(str, '-');
	if (!arr[0] || !arr[1])
		return (0);
	if (ft_is_room_name(arr[0]))
		if (ft_is_room_name(arr[1]))
		{
			ft_free_arr((void**)arr);
			return (1);
		}
	ft_free_arr((void**)arr);
	return (0);
}

int 	ft_is_link(char *str, t_vars *vars)
{
	if ((ft_one_dash(str)) && (ft_both_parts_are_rooms_names(str)))
	{
		printf("link = %s\n", str);
		return(1);
	}
	return(0);
}

void	ft_find_links()
{
	printf("IN THE LINKS\n");
	exit(1);
}
void	ft_parse_room(char *str, t_room *room)
{
	char **arr;

	arr = ft_strsplit(str, ' ');

	room->name = arr[0];
	room->x = ft_atoi(arr[1]);
	room->y = ft_atoi(arr[2]);

	ft_free_arr((void**)arr);
}

t_node_list	*ft_create_node(char *str, int i, t_vars *vars)
{
	t_node_list *new;
	t_room room;

	ft_parse_room(str, &room);

	new = (t_node_list*)malloc(sizeof(t_node_list));
	if (new != 0)
	{
		new->name = room.name;
		new->neighbour = 0;
		new->next = 0;
		new->start_end = i;
		new->x = room.x;
		new->y = room.y;
	}
	return (new);

	//free room.name
}

void	ft_add_node_to_list(char *str, int i, t_vars *vars)
{
	t_node_list *new_node;

	new_node = ft_create_node(str, i, vars);
	new_node->next = vars->head;
	vars->head = new_node;
}

int		ft_is_room(char *str, t_vars *vars)
{
	char *tmp;
	int i;
	char **arr;

	i = 0;
	tmp = str;


	while (*str)
	{
		if (*str == ' ')
			i++;
		str++;
	}
	if ((i != 2) || (str[0] == 'L'))
		return (0);
		//ft_error(2);
	str = tmp;
	arr = ft_strsplit(str, ' ');
	if (!arr[0] || !arr[1] || !arr[2])
		return (0);
		//ft_error(2);

	//check unique name, coords;

	if (ft_is_room_name(arr[0]) && ft_str_is_num(arr[1]) && ft_str_is_num(arr[2]))
	{
		printf("name = %s\n", arr[0]);
		ft_free_arr((void**)arr);
		//vars->flag_rooms = 0;
		return (1);
	}
	ft_free_arr((void**)arr);
	return (0);
}
void print_check(t_vars *vars)
{
	t_node_list *tmp;
	tmp = vars->head;
	while(tmp)
	{
		printf("=================name room = %s\n", tmp->name);
		tmp = tmp->next;
	}
}
void	ft_find_rooms(t_vars *vars)
{
	printf("IN THE ROOMS\n");
	char *str;

	while (get_next_line(0, &str))
	{
		printf("tyt - %s\n", str);
		if ((ft_is_comment_command(str, vars)) == 1)
		{
			printf("1\n");
		}
		else if (ft_is_room(str, vars))
		{
			printf("2\n");
			if (vars->flag_start == 1)
			{
				printf("tyt1\n");
				ft_add_node_to_list(str, 1, vars);
				vars->flag_start = 2;
			}
			else if (vars->flag_end == 1)
			{
				printf("tyt2\n");
				ft_add_node_to_list(str, 2, vars);
				vars->flag_end = 2;
			}
			else
			{
				printf("tyt3\n");
				ft_add_node_to_list(str, 0, vars);
			}
		}
		else if (ft_is_link(str, vars))
		{
			print_check(vars);
			ft_find_links();
			//break;
			printf("3\n");;
			//check start end;
			//ft_find_links();
		}
		else
		{
			printf("4\n");;
			
			ft_error(2);
		}
	}
}

void	ft_error(int i)
{
	if (i == 1)
		printf("ERROR:NOT ENOUGH ANTS\n");//////fix ft_printf
	if (i == 2)
		printf("ERROR:SOMETHING WRONG WITH ROOMS\n");
	if (i == 3)
		printf("ERROR:SOMETHING WRONG WITH START/END\n");

	if ((i == 1) || (i == 2))
		exit (1);
}

int		ft_is_comment_command(char *str, t_vars *vars)
{
	if (str[0] == '#')
	{
		if(!str[1] || str[1] != '#')
		{
			printf("%s - COMMENT\n", str);
			return (1);
		}
		else if (str[1] == '#')
		{
			if (!ft_strcmp((str + 2), "start"))
			{
				printf("Start\n");
				if (vars->flag_start == 2)
					ft_error(3);
				if (vars->flag_start == 0)
				vars->flag_start = 1;
				return (1);
			}
			else if (!ft_strcmp((str + 2), "end"))
			{
				printf("End\n");
				if (vars->flag_end == 2)
					ft_error(3);
				if (vars->flag_end == 0)
					vars->flag_end = 1;
				return (1);
			}
			else
			{
				printf("ANOTHER COMMAND\n");
				return (1);
			}
		}
	}
	return (0);
}

void 	ft_find_ants(t_vars *vars)
{
	char *str;

	while(get_next_line(0, &str) && vars->ants == -1)
	{
		printf("tyt - %s\n", str);
		if ((ft_is_comment_command(str, vars)) == 1)
			;
		else if (ft_str_is_num(str) && vars->ants == -1)
		{
			vars->ants = ft_atoi(str);
			if (vars->ants > 0)
			{
				printf("ANTS = %i\n", vars->ants);
				ft_find_rooms(vars);
			}
			else
				ft_error(1);
		}
		else
			ft_error(1);
	}
}

void	ft_parser(t_vars *vars)
{
	vars->ants = -1;
	ft_find_ants(vars);
}
