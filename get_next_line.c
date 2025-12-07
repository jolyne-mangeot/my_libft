/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:12:36 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/07 14:02:10 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*free_me_the_malloc(t_list *list)
{
	t_list	*temp_line;

	while (list)
	{
		temp_line = list->next;
		if (((t_line *)list->content)->buffer)
			free(((t_line *)list->content)->buffer);
		free(list->content);
		free(list);
		list = temp_line;
	}
	return (NULL);
}

static ssize_t	new_node(char *buffer, t_list **list, ssize_t line_len)
{
	t_list	*line;
	t_line	*line_content;
	ssize_t	line_index;

	line_content = (void *)malloc(sizeof(t_line));
	if (!line_content)
		return ((ssize_t)free_me_the_malloc(*list));
	line_content->buffer = (char *)malloc(sizeof(char) * (line_len + 1));
	if (!line_content->buffer)
		return ((ssize_t)free_me_the_malloc(*list));
	line = ft_lstnew((void *)line_content);
	if (!line)
		return ((ssize_t)free_me_the_malloc(*list));
	ft_lstadd_back(list, line);
	line_index = -1;
	while (line_index++ < line_len - 1)
	{
		line_content->buffer[line_index] = buffer[line_index];
		if (buffer[line_index] == '\n')
			return (line_content->line_len = line_index + 1, line_index);
	}
	return (line_content->line_len = line_index, line_index);
}

static char	*list_to_char(t_list *list, char *return_char)
{
	ssize_t	len;
	ssize_t	buf_index;
	t_list	*temp;

	temp = list;
	len = 0;
	while (temp)
	{
		len += ((t_line *)temp->content)->line_len;
		temp = temp->next;
	}
	return_char = (char *)malloc(sizeof(char) * (len + 1));
	if (!return_char)
		return (free_me_the_malloc(list));
	return_char[len] = '\0';
	len = 0;
	temp = list;
	while (temp)
	{
		buf_index = 0;
		while (buf_index < ((t_line *)temp->content)->line_len)
			return_char[len++] = ((t_line *)temp->content)->buffer[buf_index++];
		temp = temp->next;
	}
	return (free_me_the_malloc(list), return_char);
}

static ssize_t	get_content(char *buffer,
		t_list **list, ssize_t buf_start, int fd)
{
	ssize_t	read_len;
	ssize_t	line_len;

	if (buf_start && buffer[buf_start] && buf_start < BUFFER_SIZE)
	{
		line_len = new_node(buffer + buf_start, list, BUFFER_SIZE - buf_start);
		if (line_len < BUFFER_SIZE - buf_start)
			return (buf_start + line_len + 1);
	}
	read_len = read(fd, buffer, BUFFER_SIZE);
	while (read_len != 0)
	{
		buffer[read_len] = '\0';
		if (read_len == -1)
			return ((ssize_t)free_me_the_malloc(*list));
		line_len = new_node(buffer, list, read_len);
		if (line_len < read_len)
			return (line_len + 1);
		read_len = read(fd, buffer, BUFFER_SIZE);
	}
	return (read_len);
}

/*
read and returns a single line from a fie descriptor, either ending with a `\n` 
or the last character of the file.
*/
char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	static ssize_t	last_size;
	static int		last_fd;
	t_list			*buffer_list;
	char			*return_line;

	if (last_fd != fd || buffer[last_size - 1] != '\n')
	{
		last_fd = fd;
		last_size = 0;
	}
	buffer_list = NULL;
	return_line = NULL;
	last_size = get_content(buffer, &buffer_list, last_size, fd);
	if (!last_size && !buffer_list)
		return (free_me_the_malloc(buffer_list));
	return (list_to_char(buffer_list, return_line));
}
