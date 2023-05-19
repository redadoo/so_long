/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:10:35 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/19 14:53:37 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ft_update(void *param)
{
    return (0);
}

int key_hook(int keycode, void *param)
{
    ft_printf("%i",keycode);
    return (0);
}