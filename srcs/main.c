/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:21:42 by cgaillag          #+#    #+#             */
/*   Updated: 2022/11/25 00:30:09 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*	***** Parsing cub3D *****
**
**	1. check number of argc: executable + map only
**	2. check file: name (extension), empty file, accessible...

**	3. check map content: values, textures --> TODO
	- creer une structure pour la map
	- recup la map dans un char **
	- 0 toujours entoure : pas a cote de vide ou \0
		- ligne 1 : pas de 0 (car sinon map pas fermee)
		- colonne 1 : pas de 0
	- Player: verif pas en dehors de la map (a l'interieur des murs)

	- si le nom de la texture finit par .xpm mais n’est pas un fichier
		(plutot un folder… directory, donc erreur)
		- protéger texture (open O_DIRECTORY et bien close) => comme pour file

	- check env -i


	autres notes hors parsing:
		- attention aux coins
		- mettre un peu d’espace entre les murs et le joueurs (ex: 5 pixels)
*/

// void	ft_init_points(t_point *p1, t_point *p2)
// {
// 	p1->x = 400;
// 	p1->y = 100;
// 	p2->x = 400;
// 	p2->y = 500;
// }

// int	main(int argc, char **argv)
// {
// 	char	**map_content;
// 	t_img	img;
// 	t_point	p1;
// 	t_point	p2;

// 	(void)argv;
// 	(void)argc;
// 	map_content = NULL;
// 	// commente pour tester l'ouverture de la fenetre
// 	// if (ft_check_argc(argc) != 2)
// 	// 	return (EXIT_FAILURE);
// 	// if (ft_check_file(argv[1]))
// 	// 	return (EXIT_FAILURE);

// 	// init la map dans une structure data
// 	// map_content = ft_get_map_cub(argv[1]);
// 	// creer la map + init ?
// 	// check 3.

// 	img.mlx_ptr = mlx_init();
// 	img.win_ptr = mlx_new_window(img.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "CUB3D");
// 	img.img = mlx_new_image(img.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
// 				&img.line_lenght, &img.endian);
// 	// ft_draw game qui affiche tout les objets du jeu
// 	ft_init_points(&p1, &p2);
// 	ft_draw_vertical(&p1, &p2, &img);
// 	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.img, 0, 0);
// 	mlx_key_hook(img.win_ptr, key_hook, &img);
// 	mlx_hook(img.win_ptr, 17, 1L << 17, (void *)ft_quit, &img);
// 	mlx_loop(img.mlx_ptr);
// 	// printf("pour l'instant tout est ok");
// 	return (0);
// }

// main pour parsing
//	**************
int	main(int argc, char **argv)
{
	t_base	base;

	if (ft_check_arg_err(argc, argv[1]))
		return (EXIT_FAILURE);
	ft_init_t_base_cub(argv[1], &base);
	if (ft_check_file_err(&base))
		return (EXIT_FAILURE);
	//creer la map + init ?
	// check 3.
	printf("pour l'instant tout est ok\n");
	return (0);
}
