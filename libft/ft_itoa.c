/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 20:01:03 by marrodri          #+#    #+#             */
/*   Updated: 2018/12/13 20:24:32 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_check_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

static int		flag_pos(int n, int flag)
{
	if (n == 147483648)
		flag = 2;
	else
		flag = 1;
	return (flag);
}

static char		*nbr_to_str(int n, int i, int size, char *str)
{
	int	temp;
	int	flag;

	flag = 0;
	if (n < 0)
	{
		str[i] = '-';
		n = n * -1;
	}
	if (n >= 10)
	{
		i = size;
		if (str[0] == '-')
			flag = flag_pos(n, flag);
		while (i >= flag)
		{
			temp = n % 10;
			n = n / 10;
			str[i] = temp + '0';
			i--;
		}
	}
	else
		str[i] = n + '0';
	return (str);
}

char			*ft_itoa(int n)
{
	int		size;
	int		i;
	char	*str;

	i = 0;
	size = 0;
	size = ft_check_size(n);
	str = (char *)malloc((size + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		str[i++] = '-';
		str[i++] = '2';
		n = 147483648;
		str = nbr_to_str(n, i, (size - 1), str);
	}
	else
		str = nbr_to_str(n, i, (size - 1), str);
	str[size] = '\0';
	return (ft_strdup(str));
}
