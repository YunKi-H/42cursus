/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:21:23 by yuhwang           #+#    #+#             */
/*   Updated: 2021/12/16 19:50:03 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

char	*get_next_line(int fd)
{
	static char	*note[FD_MAX];
	char		*buf;
	char		*tmp;
	char		*index;
	ssize_t		len;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > FD_MAX)
		return (NULL);
	if (!note[fd])
		note[fd] = ft_strdup("");
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_strchr(note[fd], '\n') && !(len < BUFFER_SIZE))
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len <= 0)
			break ;
		buf[len] = '\0';
		tmp = ft_strjoin(note[fd], buf);
		free(note[fd]);
		//note[fd] = NULL;
		note[fd] = tmp;
	}
	index = ft_strchr(note[fd], '\n');
	tmp = NULL;
	if (index)
	{
		tmp = ft_substr(note[fd], 0, index - note[fd] + 1);
		len = (long)ft_strdup(index + 1);
		free(note[fd]);
		//note[fd] = NULL;
		note[fd] = (char *)len;
	}
	else if (!index && note[fd][0])
	{
		tmp = ft_strdup(note[fd]);
		free(note[fd]);
		note[fd] = NULL;
	}
	else
	{
		free(note[fd]);
		note[fd] = NULL;
	}
	free(buf);
	return (tmp);
}
