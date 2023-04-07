/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:50:48 by marvin            #+#    #+#             */
/*   Updated: 2023/04/06 12:50:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char    *ft_free_join(char *resto, char *buffer)
{
    char    *tmp;
    
    resto = ft_strjoin(resto, buffer);
    tmp = resto;
    free(resto);
    return (tmp);
}

char    *ft_read_file(int fd, char *resto)
{
    char    *buffer;
    int     *c_read;

    if (!resto)
        resto = calloc(1,1);
    buffer = ft_calloc(BUFFER_SIZE + 1, 1);
    if (!buffer)
        return (NULL);
    c_read = 1;
    while (c_read > 0)
    {
        c_read = read(fd, buffer, BUFFER_SIZE);
        if (c_read = -1)
        {
            free(buffer);
            return (NULL);
        }
        resto = ft_free_join(resto, buffer);
        if (ft_strchr(buffer, '\n'))
            return ;
    }
    free (buffer);
    return (resto);
}

char    *ft_line(char *ln, char *resto)
{
    int i;

    i = 0;
    while (resto[i++] != '\0'); 
    ln = ft_calloc(i + 2, sizeof(char));
    if (!ln)
        return (NULL);
    i = 0;
    while (resto[i] && resto[i] != '\n')
    {
        ln[i] = resto[i];
        i++;
    }
    if (resto[i] && resto[i] == '/n')
        ln[i++] = '/n';
    return (ln);
}

char    *get_next_line(int fd)
{
    static char    *resto;
    char           *ln;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	    return (NULL);
    resto = ft_read_file(fd, resto);
    if (!resto)
        return (NULL);
    ln = ft_line(resto);
}