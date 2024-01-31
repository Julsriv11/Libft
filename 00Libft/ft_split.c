/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:06:32 by jarias-i          #+#    #+#             */
/*   Updated: 2024/01/26 13:40:51 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*En count_w contamos cuantas subcadenas tendríamos en nuestra string de 
 * acuerdo al tamaño de s. Hacemos dos bucles, un primero para comprobar que
 * va de un separador a otro y sumar i. y otro bucle para comprobar desde un 
 * separador a otro, y que procese la subcadena.*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

static int ft_count_w(char const *s, char c)
{
	unsigned int 	i;
	int				count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (count);
}

static char	*ft_memsubs(const char *s, size_t len)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
      return (NULL);
	ptr = ft_memmove(ptr, s, len);
	ptr[len] = '\0';
	return (ptr);
}

static void	*ft_freedom(char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static void ft_start_iti(size_t *i, int *j, int *k)
{
	*i = 0;
	*j = 0;
	*k = -1;
}

char    **ft_split(char const *s, char c)
{
	char	**result;
	int	i;
	int		j;
	int		k;

	ft_start_iti(&i, &j, &k);
	result = (char **)malloc(sizeof(char*) * (ft_count_w(s, c) + 1));
	if (!result)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			result[k] = ft_memsubs(s + j, i - j);
			k++;
     	}
	}
	result[k] = ft_freedom(result, k);
	return (result);
}

int main()
{
    char    *str = "Viento en popa, a toda vela, no corta el mar, sino vuela";
    char    del = ' ';
	//char    sep = ',';
   	char     **own;
	int		i = 0;
	//char	*man;

   	own = ft_split(str, del);
	printf("Propia:\n");
	while (own[i] != NULL)
	{
		printf("%s \n", own[i]);
		i++;
	}
	/*man = strtok(str, sep);
	printf("Man:\n");
	while (man != NULL)
	{
		printf("%s \n", man);
		i++;
	}*/
	return (0);
}
