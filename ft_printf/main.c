/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:48:54 by jarias-i          #+#    #+#             */
/*   Updated: 2024/02/17 16:53:33 by jarias-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//para comprobar el proyecto

#include "ft_printf.h"

int	main(void)
{
	int	x;
	int	y;
	int num = 21;
	//void *ptr = malloc(10);

	x = ft_printf("Hola %d o %i o %s o %p\n", num, ptr );
	y = printf("Hola %d o %i o %s o %p\n", num, ptr );
	free(ptr);
	printf("Longitud de mi print %d y el original %d", x, y);
	return 0;
}
