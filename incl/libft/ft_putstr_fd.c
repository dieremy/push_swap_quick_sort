/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:19:38 by robegarc          #+#    #+#             */
/*   Updated: 2023/01/17 10:19:45 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	while (*s)
		write(fd, &(*s++), 1);
}