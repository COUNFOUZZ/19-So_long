/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 00:11:27 by aabda             #+#    #+#             */
/*   Updated: 2023/01/10 14:13:07 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../gnl/get_next_line.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/******************************************************************************/
/*								NEED TO BE DELETE							  */
/******************************************************************************/
# include <stdio.h>			//	Need to be delete !!!
# define BLACK "\x1b[30m"	//	Need to be delete !!!
# define RED "\x1b[31m"		//	Need to be delete !!!
# define GREEN "\x1b[32m"	//	Need to be delete !!!
# define YELLOW "\x1b[33m"	//	Need to be delete !!!
# define BLUE "\x1b[34m"	//	Need to be delete !!!
# define PURPLE "\x1b[35m"	//	Need to be delete !!!
# define CYAN "\x1b[36m"	//	Need to be delete !!!
# define WHITE "\x1b[37m"	//	Need to be delete !!!
# define NORMAL "\x1b[m"	//	Need to be delete !!!

/******************************************************************************/
/*								BASIC SETTINGS								  */
/******************************************************************************/
# define GAME_TITLE "So_long"

/******************************************************************************/
/*								ERROR MESSAGES								  */
/******************************************************************************/
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
# define ERR_UKNOWN_CHAR_MAP "Unknown character in the parsing of the map !\n\
If you want to create your own map, please use only :\n\
\t- \"0\" for the floor.\n\
\t- \"1\" for the wall.\n\
\t- \"P\" for the player.\n\
\t- \"C\" for the collectible.\n\
\t- \"E\" for the exit.\n"
# define ERR_INIT_IMG "Missing img !"
# define ERR_PATH_FINDING "The map is imposible to be finished. Unreachable output or collectible"

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
	int	exit_pos_x;
	int	exit_pos_y;
	int	total_obj;
}	t_checkmap;

typedef struct s_map
{
	char	**map;
	char	**cp_map;
	int		nl;
	int		lenline;
}	t_map;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	int		coin_collected;
	int		move;
	char	char_staged;
}	t_player;

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*player_floor;
	void	*player_exit;
	void	*dclose;
	void	*dopen;
	void	*coin;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	char		*argv;
	int			w_height;
	int			w_width;
	int			argv_malloc;
	t_checkmap	check;
	t_map		map;
	t_player	player;
	t_img		img;
}	t_game;

/*		srcs/utils.c		*/
void	init_struct(t_game *g);
void	ft_path_map(const char *dir, char *argv, t_game *g);
void	ft_check_ber_map(const char *argv);
void	ft_free_tab(char *tab1, char **tab2);
void	ft_error(int res, char *tab1, char **tab2, const char *error);

/*		srcs/libft_utils.c		*/
void	ft_putstr_fd(const char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_itoa(int n);

/*		srcs/parsing.c		*/
void	ft_parsing_map(t_game *g);
void	ft_init_lenline_nl(t_game *g);

/*		srcs/map_utils		*/
void	ft_check_map(t_game *g);

/*		srcs/movement.c		*/
void	ft_movement(int keycode, t_game *g);

/*		srcs/img.c		*/
void	ft_init_img(t_game *g);
void	ft_put_img_map(t_game *g);
void	ft_put_img(t_game *g, int x, int y, const char c);

/*		srcs/mlx_utils.c		*/
int		key_pressed(int keycode, t_game *g);
int		red_cross(void);
void	ft_print_infos(t_game *g);
void	ft_print_map1(t_game *g);

/*		srcs/pathfinding.c		*/
void	ft_cp_map(t_game *g);
int		ft_path_finding(t_game *g, int y, int x);

#endif