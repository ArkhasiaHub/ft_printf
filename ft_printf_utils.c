/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:30:28 by sbriche           #+#    #+#             */
/*   Updated: 2023/11/20 10:46:08 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	if (str == NULL)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_verif_write_c(int *count, char c)
{
	int	temp_c;

	temp_c = ft_putchar(c);
	if (temp_c == -1)
	{
		*count = -1;
		return (temp_c);
	}
	*count += temp_c;
	return (temp_c);
}

int	ft_verif_write_str(int *count, char *str)
{
	int	temp_c;

	temp_c = ft_putstr(str);
	if (temp_c == -1)
	{
		*count = -1;
		return (temp_c);
	}
	*count += temp_c;
	return (temp_c);
}
