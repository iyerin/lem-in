/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <iyerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:31:51 by iyerin            #+#    #+#             */
/*   Updated: 2018/10/26 15:42:10 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

// void	ft_comment_command(char *str, t_vars *vars)
// {
// 	if (ft_strlen(str) > 1)
// 	{
// 		if (str[1] == '#')
// 		{
// 			if (!ft_strcmp((str + 2), "start"))
// 			{
// 				printf("Start\n");
// 				vars->flag_start = 1;
// 			}
// 			if (!ft_strcmp((str + 2), "end"))
// 			{
// 				printf("End\n");
// 				vars->flag_end = 1;
// 			}
// 		}
// 	}
// }

// int 	ft_is_ants(char *str, t_vars *vars)
// {
// 	if (vars->flag_rooms == -1 && vars->ants < 0)
// 	{
// 		if (ft_str_is_num(str))
// 			{
// 				vars->ants = ft_atoi(str);
// 				//vars->flag_ants = 1;
// 				printf("ants = %i\n", vars->ants);

// 				return(1);
// 			}
// 	}
// 	return (0);
// }

// int		ft_is_room(char *str, t_vars *vars)
// {
// 	char *tmp;
// 	int i;
// 	char **arr;

// 	i = 0;
// 	tmp = str;

// 	while (*str)
// 	{
// 		if (*str == ' ')
// 			i++;
// 		str++;
// 	}
// 	if ((i != 2) || (str[0] == 'L') || (vars->flag_rooms == 1))
// 		return (0);
// 	str = tmp;
// 	arr = ft_strsplit(str, ' ');
// 	if (!arr[0] || !arr[1] || !arr[2])
// 		return (0);
// 	if (ft_str_is_num(arr[1]) && ft_str_is_num(arr[2]))
// 	{
// 		printf("name = %s\n", arr[0]);
// 		ft_free_arr((void**)arr);
// 		vars->flag_rooms = 0;
// 		return (1);
// 	}
// 	ft_free_arr((void**)arr);
// 	return (0);
// }

// int 	ft_one_dash(char *str)
// {
// 	int dash;

// 	dash = 0;
// 	while (*str)
// 	{
// 		if (*str == '-')
// 			dash++;
// 		str++;
// 	}
// 	if (dash == 1)
// 		return (1);
// 	return (0);
// }

// int 	ft_is_room_name(char *str)
// {
// 	ft_strlen(str);
// 	return (1);/////////////////////////////////////fix
// }

// int 	ft_both_parts_are_rooms_names(char *str)
// {
// 	char **arr;

// 	arr = ft_strsplit(str, '-');
// 	if (!arr[0] || !arr[1])
// 		return (0);
// 	if (ft_is_room_name(arr[0]))
// 		if (ft_is_room_name(arr[1]))
// 			return (1);
// 	ft_free_arr((void**)arr);
// 	return (0);

// }

// int 	ft_is_link(char *str, t_vars *vars)
// {
// 	if ((ft_one_dash(str)) && (ft_both_parts_are_rooms_names(str)))
// 	{
// 		vars->flag_rooms = 1;
// 		printf("link = %s\n", str);
// 		return(1);
// 	}
// 	return(0);
// }

// void	ft_error(int i)
// {
// 	if (i == 1)
// 		printf("ERROR:NOT ENOUGH ANTS\n");//////fix ft_printf

// 	if (i == 1)
// 		exit (1);
// }

// void	ft_counter(char *str, t_vars *vars)
// {
// 	//link
// 	//comment
// 	//error	

// 	if (str[0] == '#')
// 		ft_comment_command(str, vars);
// 	else if (ft_is_ants(str, vars))
// 	{
// 		if (vars->ants <= 0)
// 			ft_error(1);
// 	}
// 	else if (ft_is_room(str, vars))
// 		vars->rooms_count++;
// 	else if (ft_is_link(str, vars))
// 		vars->links++;
// 	// else
// 	// 	ft_error();

// }



