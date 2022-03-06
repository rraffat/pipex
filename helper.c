/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffat <rraffat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:37:36 by rraffat           #+#    #+#             */
/*   Updated: 2022/03/03 05:32:42 by rraffat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_ncmp(char *str1, char *str2, int n)
{
	while (--n > 0 && *str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str2 - *str1);
}

int	ft_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

char	*ft_dup(char *str, unsigned int n)
{
	char				*duped;
	unsigned int		i;

	i = 0;
	duped = malloc(sizeof(char) * (n + 1));
	while (i < n)
		duped[i++] = *str++;
	duped[n] = 0;
	return (duped);
}

char	**ft_split(char *str, char sep)
{
	char	**tab;
	int		count;
	int		i;
	int		j;

	count = 0;
	j = 0;
	while (str[j])
	{
		if (str[j++] == sep)
			count++;
	}
	tab = malloc(sizeof(char *) * (count + 2));
	tab[count + 1] = NULL;
	i = 0;
	while (i < count + 1)
	{
		j = 0;
		while (str[j] && str[j] != sep)
			j++;
		tab[i++] = ft_dup(str, j);
		str = str + j + 1;
	}
	return (tab);
}

char	*ft_join(char *join, char *str)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = malloc(sizeof(char) * (ft_char(join, 0) + ft_char(str, 0) + 2));
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (join[j])
	{
		ptr[i++] = join[j++];
	}
	ptr[i++] = '/';
	j = 0;
	while (str[j])
	{
		ptr[i++] = str[j++];
	}
	ptr[i] = 0;
	return (ptr);
}
