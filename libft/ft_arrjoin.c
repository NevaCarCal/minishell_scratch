/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:39:55 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/10 20:10:10 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_create_arr(char **arr, t_array_data *data)
{
	data->i = 0;
	while (data->i < data->len1)
	{
		data->new_arr[data->i] = ft_strdup(arr[data->i]);
		if (!data->new_arr[data->i])
		{
			ft_free_str_array(data->new_arr);
			return (-1);
		}
		data->i++;
	}
	return (0);
}

static int	ft_join_arr(char **arr, t_array_data *data)
{
	data->j = 0;
	while (data->j < data->len2)
	{
		data->new_arr[data->i + data->j] = ft_strdup(arr[data->j]);
		if (!data->new_arr[data->i + data->j])
		{
			ft_free_str_array(data->new_arr);
			return (-1);
		}
		data->j++;
	}
	return (0);
}

char	**ft_arrjoin(char **arr1, char **arr2)
{
	t_array_data	data;

	data.len1 = ft_arrlen(arr1);
	data.len2 = ft_arrlen(arr2);
	data.new_arr = (char **)malloc(sizeof(char *) * (
				data.len1 + data.len2 + 1));
	if (!data.new_arr)
		return (NULL);
	if (ft_create_arr(arr1, &data) == -1)
		return (NULL);
	if (ft_join_arr(arr2, &data) == -1)
		return (NULL);
	data.new_arr[data.len1 + data.len2] = NULL;
	return (data.new_arr);
}
