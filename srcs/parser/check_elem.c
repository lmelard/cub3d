/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaillag <cgaillag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:08:18 by cgaillag          #+#    #+#             */
/*   Updated: 2022/12/14 16:12:41 by cgaillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_count_elem(t_base *base, int range)
{
	t_line	*line;
	int		count;

	count = 0;
	line = base->list_base;
	while (line)
	{
		if (line->range == range)
			count++;
		line = line->next;
	}
	if (count < 1)
		return (ft_msg_1(1, NULL, NULL, ER_ELE_MISS));
	else if (count > 1)
		return (ft_msg_1(1, NULL, NULL, ER_ELE_TOO));
	return (0);
}

/*  ***** Parsing - check texture elements *****
**  *************************
**  <SUMMARY>	Check if path is not a directory
**	<RETURN>	- EXIT_FAILURE: if is a directory
**				- XIT_SUCCESS, otherwise
*/
int	ft_check_elem_err(t_base *base)
{
	int		i;
	t_line	*line;

	line = base->list_base;
	i = 0;
	while (++i < 7)
	{
		if (ft_check_count_elem(base, i))
			return (EXIT_FAILURE);
	}
	while (line)
	{
		if (line->range >= 1 && line->range < 5)
		{
			ft_open_read(line->tex_path);
			if (!ft_check_filename(line->tex_path, ".xpm"))
				return (ft_msg_1(1, line->tex_path, ER_FIL_EXT, USAGE_XPM));
			if (ft_check_isdirectory(line->tex_path))
				return (ft_msg_1(EXIT_FAILURE, line->tex_path, NULL,
						ER_FIL_ISDIR));
		}
		line = line->next;
	}
	return (EXIT_SUCCESS);
}
