/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 01:10:41 by oamairi           #+#    #+#             */
/*   Updated: 2025/05/21 13:40:52 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return (&s[i]);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return (&s[i]);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_strdup("");
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		res[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2 && s2[i])
	{
		res[j] = s2[i];
		i++;
		j++;
	}
	return (res[j] = '\0', free(s1), s1 = NULL, (res));
}

char	*get_line(int fd, char *after)
{
	char	*buffer;
	int		line;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = 1;
	while (!ft_strchr(after, '\n') && line > 0)
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		line = read(fd, buffer, BUFFER_SIZE);
		if (line < 0)
		{
			free(buffer);
			return (NULL);
		}
		after = ft_strjoin(after, buffer);
		if (!after)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (after);
}

char	*get_next_line(int fd)
{
	static char	*after_n;
	char		*res;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	after_n = get_line(fd, after_n);
	if (!after_n || *after_n == '\0')
	{
		free(after_n);
		after_n = NULL;
		return (NULL);
	}
	res = ft_strsup(after_n, '\n');
	if (!res)
		return (free(after_n), after_n = NULL, (NULL));
	tmp = ft_strchr(after_n, '\n');
	if (tmp)
		ft_swap(&after_n, tmp);
	else
	{
		free(after_n);
		after_n = NULL;
	}
	return (res);
}
