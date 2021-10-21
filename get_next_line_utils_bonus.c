/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorre <mmorre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:34:41 by mmorre            #+#    #+#             */
/*   Updated: 2021/10/21 13:01:33 by mmorre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (len + start > s_len)
		len = (s_len - start);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	if (start < s_len)
	{
		while (i < len)
			new[i++] = s[start++];
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i_1;
	size_t	i_2;
	char	*new;

	i_1 = 0;
	i_2 = 0;
	if (!s1 || !s2)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1 ));
	if (!new)
		return (NULL);
	while (s1[i_1])
	{
		new[i_1] = s1[i_1];
		i_1++;
	}
	while (s2[i_2])
	{
		new[i_1] = s2[i_2];
		i_1++;
		i_2++;
	}
	new[i_1] = '\0';
	return (new);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	if (!s)
		return (0);
	size = 0;
	while (s[size])
		size++;
	return (size);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*ptr_dst;
	const char	*ptr_src;

	i = 0;
	ptr_dst = (char *)dst;
	ptr_src = (const char *)src;
	if ((!src) && (!dst))
		return (NULL);
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		i++;
	}
	return (dst);
}

size_t	get_next_n(char *buffer, size_t filled)
{
	size_t	i;

	i = 0;
	while (i < filled && buffer[i] != '\n')
		i++;
	return (i);
}
