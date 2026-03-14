/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:46:33 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/14 11:03:13 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error_exit(char *err_msg, int err_code)
{
	ft_write(err_msg, 2);
	exit(err_code);
}

void	ft_exit(char *msg, int ex_code)
{
	ft_write(msg, 1);
	exit(ex_code);
}
