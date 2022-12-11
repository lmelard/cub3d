/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:56:20 by lmelard           #+#    #+#             */
/*   Updated: 2022/12/11 20:51:26 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_texture(t_data *data, t_tex *tex)
{
	tex->img = mlx_xpm_file_to_image(data->mlx_ptr, tex->path, &tex->tile_x, \
		&tex->tile_y);
	if (tex->img == 0)
		ft_exit_cub(ft_msg_1(1, tex->path, NULL, ER_TEX_IMG), data);
	if (tex->tile_x != tex->tile_y || tex->tile_x != TILE_SIZE)
		ft_exit_cub(ft_msg_1(1, tex->path, NULL, ER_TEX_SIZE), data);
	// prevoir une etape pour les integrer dans la map
}

static void	ft_init_mlxwin_cub(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		ft_exit_cub(ft_msg_1(1, "mlx_init()", NULL, ER_MLX_INIT), data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"CUB3D");
	if (data->win_ptr == NULL)
		ft_exit_cub(ft_msg_1(1, "mlx_new_window()", NULL, ER_MLX_WIN),
			data);
}

static void	ft_init_data_0(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->map2d_win_ptr = NULL;
	data->map2d_display = FALSE;
	data->map2d_width = WIN_WIDTH;//a revoir, calculer
	data->map2d_height = WIN_HEIGHT;//a revoir, calculer
	data->cub.img = NULL;
	data->m2d.img = NULL;
}

/*	<SUMMARY> Initialize data elements except 'base' content
	- set up mlx to start game
	- open textures
	- init t_img for main game & minimap
	- init player
	- init rays
*/
void	ft_init_data(t_data *data)
{
	ft_init_data_0(data);
	ft_init_mlxwin_cub(data);
	ft_init_texture(data, &(data->base.no));
	ft_init_texture(data, &(data->base.so));
	ft_init_texture(data, &(data->base.we));
	ft_init_texture(data, &(data->base.ea));
	ft_init_t_img(data, &(data->cub), WIN_WIDTH, WIN_HEIGHT);
	ft_init_t_img(data, &(data->m2d), WIN_WIDTH, WIN_HEIGHT);
	ft_init_player(data);
	ft_init_rays(data);
}
