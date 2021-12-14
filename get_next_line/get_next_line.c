/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:21:23 by yuhwang           #+#    #+#             */
/*   Updated: 2021/12/11 15:36:05 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*note[OPEN_MAX];
	char		*buf;
	char		*tmp;
	ssize_t		len;
	ssize_t		index;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!note[fd] || !note[fd][0])
		note[fd] = ft_strdup("");
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_strchr(note[fd], '\n') && !(len < BUFFER_SIZE))
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (!len)
			return (NULL);
		buf[len] = '\0';
		tmp = ft_strjoin(note[fd], buf);
		free(note[fd]);
		note[fd] = tmp;
	}
	if (ft_strchr(note[fd], '\n'))
	{
		index = ft_strchr(note[fd], '\n') - note[fd];
		tmp = ft_substr(note[fd], 0, index);
		note[fd] += index + 1;
	}
	else
	{
		tmp = ft_strdup(note[fd]);
		free(note[fd]);
	}
	free(buf);
	return (tmp);
}
