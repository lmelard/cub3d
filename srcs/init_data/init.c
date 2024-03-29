/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:56:20 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/16 18:41:25 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_texture(t_data *data, t_img *tex)
{
	tex->img = mlx_xpm_file_to_image(data->mlx_ptr, tex->path, &tex->tile_x, \
		&tex->tile_y);
	if (!tex->img)
		ft_exit_cub(ft_msg_1(1, tex->path, NULL, ER_TEX_IMG), data);
	if (tex->tile_x != tex->tile_y || tex->tile_x != TILE_SIZE)
		ft_exit_cub(ft_msg_1(1, tex->path, NULL, ER_TEX_SIZE), data);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel, \
		&tex->line_length, &tex->endian);
	if (!tex->addr)
		ft_exit_cub(ft_msg_1(1, tex->path, NULL, ER_MLX_ADDR), data);
}

static float	ft_get_minimap_scale(t_data *data)
{
	float	scale;

	scale = 0;
	if (data->base.cols <= 15 && data->base.rows <= 15)
		scale = MINI_MAP_SCALE;
	else if (MAP_SCALE * data->base.cols * MINI_TILE > WIN_WIDTH \
		|| MAP_SCALE * data->base.rows * MINI_TILE > WIN_HEIGHT)
		scale = 0;
	else
		scale = MAP_SCALE;
	return (scale);
}

static void	ft_init_data_0(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->map2d_win_ptr = NULL;
	data->map2d_display = FALSE;
	data->minimap_scale = ft_get_minimap_scale(data);
	data->map2d_width = data->base.cols * MINI_TILE * data->minimap_scale;
	data->map2d_height = data->base.rows * MINI_TILE * data->minimap_scale;
	data->fov = FOV_ANGLE * (PI / 180);
	data->dist_proj_plane = (WIN_WIDTH / 2) / tan(data->fov / 2);
	data->cub.img = NULL;
	data->m2d.img = NULL;
}

/*	<SUMMARY> Initialize data elements except 'base' content
*/
void	ft_init_data(t_data *data)
{
	ft_init_data_0(data);
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		ft_exit_cub(ft_msg_1(1, "mlx_init()", NULL, ER_MLX_INIT), data);
	ft_init_texture(data, &(data->base.no));
	ft_init_texture(data, &(data->base.so));
	ft_init_texture(data, &(data->base.we));
	ft_init_texture(data, &(data->base.ea));
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"CUB3D");
	if (data->win_ptr == NULL)
		ft_exit_cub(ft_msg_1(1, "mlx_new_window()", NULL, ER_MLX_WIN),
			data);
	ft_init_t_img(data, &(data->cub), WIN_WIDTH, WIN_HEIGHT);
	if (data->minimap_scale)
		ft_init_t_img(data, &(data->m2d), data->map2d_width, \
			data->map2d_height);
	ft_init_player(data);
	ft_init_rays(data);
}
