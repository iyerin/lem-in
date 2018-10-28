/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <iyerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:30:02 by iyerin            #+#    #+#             */
/*   Updated: 2018/10/28 13:45:57 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"
//parse:
//create nodes array
//create links array
//

//algorythm
// print



int		main(void)
{
	t_vars	vars;
	//char	*str;

	// ft_bzero (&vars, sizeof(t_vars));

	vars.ants = -1;
	vars.flag_start = 0;
	vars.flag_end = 0;
	vars.head = 0;

	vars.result = ft_strnew(0);
	// while (get_next_line(0, &str))
	// {
	// 	printf("str = %s\n", str);
	// 	//ft_counter(str, &vars);
	// 	vars.result = ft_strjoin_free(ft_strjoin_free(vars.result, str), "\n");
	// 	vars.map_size++;
	// 	printf("res = %s\n", vars.result);
	// 	//vars.map = ft_strsplit
	// }
	//printf("res = %s\n", vars.result);
	//vars.map = ft_strsplit(vars.result, '\n');
	ft_parser(&vars);
	
	ft_strdel(&vars.result);

	return (0);
}

