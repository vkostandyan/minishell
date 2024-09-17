/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:29:41 by vkostand          #+#    #+#             */
/*   Updated: 2024/09/17 16:33:58 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	str = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// char    ft_strdup(const char *s1, int n, int m)
// {
//     char    str;
//     int        i;

//     str = (char)malloc((n - m + 2) * sizeof(char));
//     if (str == NULL)
//         return (0);
//     i = m;
//     while (n >= m)
//     {
//         str[i] = s1[i];
//         i++;
//     }
//     str[i] = '\0';
//     return (str);
// }
