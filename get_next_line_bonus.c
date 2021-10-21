/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorre <mmorre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:34:33 by mmorre            #+#    #+#             */
/*   Updated: 2021/10/21 13:15:22 by mmorre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_return(char **rest, char *tmp, size_t *filled)
{
	char			*return_2;
	const size_t	new_position = get_next_n(tmp, *filled);
	char *const		sub = ft_substr(tmp, 0, new_position
	+ (new_position != *filled));

	if (!sub)
	{
		free(*rest);
		return (0);
	}
	return_2 = ft_strjoin(((char *[2]){"", *rest})[*rest != 0], sub);
	free(sub);
	free(*rest);
	*rest = return_2;
	if (new_position == *filled)
		*filled = 0;
	else
	{
		ft_memcpy(tmp, tmp + new_position + 1, *filled - 1 - new_position);
		*filled = *filled - 1 - new_position;
	}
	return (*rest != 0);
}

int	checkbuf(void)
{
	return (BUFFER_SIZE > 0 && BUFFER_SIZE <= (size_t)-1);
}

char	*get_next_line(int fd)
{
	static t_stat	sta;
	t_buffer		buff;

	if (fd < 0 || !checkbuf())
		return (0);
	buff.rest = 0;
	while (1)
	{
		buff.n = read(fd, sta.buf + sta.len_buff, BUFFER_SIZE - sta.len_buff);
		sta.len_buff += buff.n;
		if (!buff.n && sta.len_buff == 0)
		{
			sta.len_buff = 0;
			return (buff.rest);
		}
		if (buff.n == -1 || !get_return(&buff.rest, sta.buf, &sta.len_buff))
		{
			if (buff.n == -1)
				free(buff.rest);
			sta.len_buff = 0;
			return (0);
		}
		if (buff.rest[ft_strlen(buff.rest) - 1] == '\n')
			return (buff.rest);
	}
}
