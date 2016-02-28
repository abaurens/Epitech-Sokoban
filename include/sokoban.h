/*
** sokoban.h for sokoban in /home/bauren_a/Work/tek-1/PSU/semestre_2/PSU_2015_my_sokoban
**
** Made by Arthur
** Login   <bauren_a@epitech.net>
**
** Started on  Thu Feb 25 20:27:52 2016 Arthur
** Last update Sun Feb 28 19:15:00 2016 Arthur
*/

#ifndef SOKOBAN_H
# define SOKOBAN_H

#include <unistd.h>
#include <termios.h>

typedef struct	termios t_term;
typedef struct	winsize t_winsize;

typedef struct	s_map
{
  int		x;
  int		y;
  int		w;
  int		h;
  char		**map;
}		t_map;

typedef struct	s_entity
{
  int		count;
  int		x;
  int		y;
  int		fx;
  int		fy;
}		t_entity;

int	putchar(int c);
int	stlen(char *str);
int	sl(char *str, char c);
int	count_line(char *str);
int	getnbr(const char *str);
int	init_term(t_term *term);
int	reset_term(t_term *term);
int	loop_game(t_map *map, t_entity *player, t_entity *boxes);
int	set_entitys(t_entity *player, t_entity **boxes, t_map *map);
int	move_player(t_map *map, t_entity *player, t_entity *boxes, char key);

char	*my_strcpy(char *str);
char	*my_strcat(char *str1, char *str2, int  len2);

void	*free_map(t_map *map);
void	my_clear_screen(void);
void	write_centered(char *str);
void	show_game(t_map *map, t_entity *player, t_entity *boxes);
void	draw_entitys(t_entity *boxes, char *res, t_entity *player, t_map *map);

#endif /* !SOKOBAN_H */
