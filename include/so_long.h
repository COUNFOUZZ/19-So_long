/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 00:11:27 by aabda             #+#    #+#             */
/*   Updated: 2022/12/06 10:42:45 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../gnl/get_next_line.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>		// Need to be delete !

/******************************************************************************/
/*								BASIC SETTINGS								  */
/******************************************************************************/
# define GAME_TITLE "So_long"
# define WIN_WIDTH 800
# define WIN_HEIGHT 600

/******************************************************************************/
/*								ERROR MESSAGES								  */
/******************************************************************************/
# define ERR_MALLOC "Malloc error !\n"
# define ERR_BAD_ARG "Invalid number of arguments !\n\
You can find all maps in \"maps\" directory\n\
The program should be launched like this -> \"./so_long MapName.ber\"\n"
# define ERR_PATH "The map does not exist !\n"
# define ERR_BAD_EXT "Wrong extension file !\n\
All maps must have the extension .ber\n"
# define ERR_NBR_PLAYER1 "Too much player on the map !\n\
Only one player on the map is allowed"
# define ERR_NBR_PLAYER2 "Not enough players on the map !\n\
Only one player on the map is allowed"
# define ERR_NBR_EXIT1 "Too much exit on the map !\n\
Only one exit on the map is allowed"
# define ERR_NBR_EXIT2 "Not enough exit on the map !\n\
Only one exit on the map is allowed"
# define ERR_MISSING_WALL "The map is not totally closed by walls !\n"

/******************************************************************************/
/*								MACRO KEYCODE								  */
/******************************************************************************/
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define KEY_ESC 53
# define KEY_SPACE 49
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

typedef struct s_checkmap
{
	int	nbr_coin;
	int	nbr_player;
	int	nbr_exit;
}	t_checkmap;

typedef struct s_map
{
	char	**map;
	int		nl;
	int		lenline;
}	t_map;

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
	int	coin_collected;
}	t_player;

typedef struct s_img
{
	void	*img;
	int		img_width;
	int		img_height;
	char	*path;
}	t_img;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	char		*argv;
	t_checkmap	check;
	t_map		map;
	t_player	player;
	t_img		img;
}	t_game;

/*		srcs/utils.c		*/
void	init_struct(t_game *g);
void	ft_path_map(const char *dir, const char *argv, t_game *g);
void	ft_free_tab(char *tab1, char **tab2);
void	ft_error(int res, char *tab1, char **tab2, const char *error);

/*		srcs/libft_utils.c		*/
void	ft_putstr_fd(const char *s, int fd);

/*		srcs/parsing.c		*/
void	ft_parsing_map(t_game *g);
void	ft_init_lenline_nl(t_game *g);

/*		srcs/map_utils		*/
void	ft_check_map(t_game *g);

/*		srcs/movement.c		*/
void	ft_movement(int keycode, t_game *g);

int		key_pressed(int keycode, t_game *g);
void	ft_img(t_game *g, char *path, int *width, int *height);
int		red_cross(void);
void	ft_print_map1(t_game *g);

#endif