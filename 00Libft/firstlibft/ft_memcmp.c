/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:48:26 by jarias-i          #+#    #+#             */
/*   Updated: 2024/02/08 12:27:00 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Compara bytes de memoria entre string en vez de el contenido de estas string,
 * es decir, compara bloques de memoria sin interpretar su contenido como 
 * cadenas de char. Devuelve un entero que indica la relación entre los bloques 
 * de memoria comparados. Puede ser negativo si el primer bloque es menor, 
 * positivo si el primer bloque es mayor o cero si son iguales. El parámetro n, 
 * en este caso es el tamaño de 
bytes a comparar en vez de nº máx char como en strncmp*/

#include <stdio.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;
	size_t			i;

	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)ptr_s1[i] != (unsigned char)ptr_s2[i])
			return ((int)(unsigned char)ptr_s1[i] - (unsigned char)ptr_s2[i]);
		i++;
	}
	return (0);
}

/*int	main()
{
	const char	str1[] = "Oslo que tal";
	const char	str2[] = "Osla que tal";
	int		x;
	int		y;

	x = ft_memcmp(str1, str2, 10);
	printf("R1 %d\n", x);
	y = memcmp(str1, str2, 10);
	printf("R2 %d\n", y);
	return (0);
}*/
