/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:23:34 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/02 14:10:01 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_vertical(t_data *data, t_point p1, t_point p2, int color)
{
	if (p1.y > p2.y)
	{
		while (p2.y <= p1.y)
		{
			my_pixel_put(data, p1.x, p1.y, color);
			p1.y -= 1;
		}
	}
	else
	{
		while (p1.y <= p2.y)
		{
			my_pixel_put(data, p1.x, p1.y, color);
			p1.y += 1;
		}
	}
}

void	ft_draw_horizontal(t_data *data, t_point p1, t_point p2, int color)
{
	if (p1.x > p2.x)
	{
		while (p2.x <= p1.x)
		{
			my_pixel_put(data, p1.x, p1.y, color);
			p1.x -= 1;
		}
	}
	else
	{
		while (p1.x <= p2.x)
		{
			my_pixel_put(data, p1.x, p1.y, color);
			p1.x += 1;
		}
	}
}

float	ft_abs(float nbr)
{
	if (nbr < 0)
		nbr = nbr * -1;
	return (nbr);
}

void	ft_draw_line(t_data *data, t_point p1, t_point p2, int color)
{
	float	dx;
	float	dy;
	float	m;

	dx = ft_abs(p2.x - p1.x);
	dy = ft_abs(p2.y - p1.y);
	m = dy / dx;
	if (dy == 0)
		ft_draw_horizontal(data, p1, p2, color);
	else if (dx == 0)
		ft_draw_vertical(data, p1, p2, color);
	else if (dx >= dy)
		ft_small_slope(data, p1, p2, color, m);
	else
		ft_big_slope(data, p1, p2, color, m);
}
