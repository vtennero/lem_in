/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:36:24 by vtennero          #+#    #+#             */
/*   Updated: 2017/11/28 11:26:43 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_eol_is_full(char *buf, char **line)
{
	int			eol_pos;

	if ((eol_pos = ft_char_pos(buf, '\n')) >= 0)
	{
		*line = ft_strndup(buf, eol_pos);
		ft_memcpy(buf, buf + eol_pos + 1, BUFF_SIZE);
		return (1);
	}
	else
	{
		*line = ft_strdup(buf);
		ft_bzero(buf, BUFF_SIZE);
	}
	return (0);
}

int				ft_read_line(char *buf, char **line, int fd)
{
	int			ret;
	int			eol_pos;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((eol_pos = ft_char_pos(buf, '\n')) >= 0)
		{
			*line = ft_strjoin_clr(*line, ft_strndup(buf, eol_pos), 2);
			ft_memcpy(buf, buf + eol_pos + 1, BUFF_SIZE);
			return (1);
		}
		else
		{
			*line = ft_strjoin_clr(*line, buf, 0);
			ft_bzero(buf, BUFF_SIZE);
		}
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char	buf[BUFF_SIZE + 1];
	int			eol_pos;

	if (!line || fd < 0)
		return (-1);
	*line = NULL;
	eol_pos = ft_char_pos(buf, '\n');
	if (ft_strlen(buf) > 0)
	{
		if (ft_eol_is_full(buf, line) == 1)
			return (1);
	}
	if (eol_pos == -1)
	{
		if (ft_read_line(buf, line, fd) == 1)
			return (1);
	}
	if (*line)
		return (1);
	else
		return (0);
}
