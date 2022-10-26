#ifndef PARS_H
#define PARS_H

#include "../cub3d.h"

int flag_no;
int flag_so;
int flag_ea;
int flag_we;
int flag_f;
int flag_c;
int take_the_map;

typedef struct t_map
{
    char *str;
    struct t_map *next;
}   t_map;

typedef struct cub3d_t
{
    void	*mlx;
	void	*win;
    int     x_player;
    int     y_player;
    char    direction;
    int     *f_col;
    int     *c_col;
    char    **map;
    char    *info;
    char    *NO;
    char    *SO;
    char    *EA;
    char    *WE;
}   cub3d_t;

typedef struct lexer
{
	char	c;
	int		src_size;
	int		j;
	char	*src;
	int		i;
}	t_lexer;

char	*line_map(int fd);
char	**split_map(char *c);
cub3d_t	*return_map(char *av, cub3d_t *cub);
char	*change_value(char *str);
int     find_path(char *str, char *search);
int     check_if_true(char *str);
t_lexer	*init_lexer(char *src);
void	lexer_skip_space(t_lexer *lexer);
void	lexer_advance(t_lexer *lexer);
void	err_fre_lex_cub(t_lexer *lexer, cub3d_t *cub);
char	*get_c_as_str(char c);
void	lexer_skip_space_line(t_lexer *lexer);
char	*take_id(t_lexer *lexer, cub3d_t *cub);
void	lexer_back(t_lexer *lexer);
char	*check_id(t_lexer *lexer, cub3d_t *cub, char *str);
int     *take_col(t_lexer *lexer, cub3d_t *cub, char *str);
void    free_double_p(char **str);
int     lent_double_p(char **str);
int     check_numbers(char **str);
char    **find_er(t_lexer *lexer, cub3d_t *cub, char *str);
char    *take_line(t_lexer *lexer);
t_map    *take_map(t_lexer *lexer);
t_map   *init_map(char *str);
void	token_add_back(t_map **map, char *value);
char    **swap_to_double(t_map *map);
int     lst_size(t_map *map);
void	exit_mssg(char *str);
void    check_map(cub3d_t *cub);
void    free_cub(cub3d_t *cub);
int     all_element(char **map);
int     sur_by_walls(char **map);
int     check_1(char **str);
int     skip_space_start(char *str);
int     skip_space_end(char *str);
int     find_wall(char **str, int i, int j);
int     check_spaces(char **str);
int     check_first_line(char **str);
int     check_last_line(char **str);
#endif