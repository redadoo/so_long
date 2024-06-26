/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:34:16 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/13 00:05:27 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	print_vector2(t_vector2 v)
{
	printf("x : %.2f | y : %.2f \n", v.x, v.y);
}

void	print_vector3(t_vector3 v)
{
	printf("x : %.2f | y : %.2f | z : %.2f \n", v.x, v.y, v.z);
}

void	print_vector2_int(t_vector2_int v)
{
	printf("x : %d | y : %d \n", v.x, v.y);
}

void	print_vector3_int(t_vector3_int v)
{
	printf("x : %d | y : %d | z : %d \n", v.x, v.y, v.z);
}
