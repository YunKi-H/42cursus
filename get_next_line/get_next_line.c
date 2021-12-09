/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:21:23 by yuhwang           #+#    #+#             */
/*   Updated: 2021/12/09 20:00:39 by yuhwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*note[OPEN_MAX];
	char		*buf;
	char		*tmp;
	int			len;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	note[fd] = ft_strdup("");
	if (!note[fd])
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_strchr(note[fd], '\n'))
	{
		len = read(fd, buf, BUFFER_SIZE);
		buf[len] = '\0';
		tmp = ft_strjoin(note[fd], buf);
		free(note[fd]);
		note[fd] = tmp;
		if (len < BUFFER_SIZE)
			break ;
	}
	tmp = ft_substr(note[fd], 0, ft_strchr(note[fd], '\n') - note[fd]);
	free(buf);
	if (len < BUFFER_SIZE)
			free(note[fd]);
	return (tmp);
}
