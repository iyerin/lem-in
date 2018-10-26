/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <iyerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:30:18 by iyerin            #+#    #+#             */
/*   Updated: 2018/10/26 13:30:42 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

int ft_str_is_num(char *str)
{
	if(!*str)
		return(0);
	while (*str)
	{
		if(!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	*ft_free_arr(void **arr)
{
	size_t i;

	i = 0;
	if (arr == 0)
		return (arr);
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (0);
}

char	*ft_strjoin_free(char *s1, char const *s2)
{
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(*str) * (ft_strlen(s1)
		+ ft_strlen(s2) + 1))))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	free(s1);
	return (str);
}
