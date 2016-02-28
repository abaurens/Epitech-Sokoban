/*
** game.c for sokoban in /home/bauren_a/Work/tek-1/PSU/semestre_2/PSU_2015_my_sokoban
**
** Made by Arthur
** Login   <bauren_a@epitech.net>
**
** Started on  Sat Feb 27 16:03:33 2016 Arthur
** Last update Sun Feb 28 18:41:59 2016 Arthur
*/

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <sys/ioctl.h>
#include "sokoban.h"

void	reset_game(t_entity *player, t_entity *boxes)
{
  int	i;

  i = -1;
  while (++i < player->count)
    {
      boxes[i].x = boxes[i].fx;
      boxes[i].y = boxes[i].fy;
    }
  player->x = player->fx;
  player->y = player->fy;
}

int		check_win_size(t_map *map)
{
  t_winsize	winsize;

  if (ioctl(0, TIOCGWINSZ, (char *) &winsize) < 0)
    return (1);
  if (winsize.ws_col < map->w || winsize.ws_row < map->h)
    {
      write_centered("Please.\nResize\nthe\nwindow.");
      while (winsize.ws_col < map->w || winsize.ws_row < map->h)
	if (ioctl(0, TIOCGWINSZ, (char *) &winsize) < 0)
	  return (1);
    }
}

int	is_victory(t_map *map, t_entity *boxes, int boxCount)
{
  int	i;

  i = -1;
  while (++i < boxCount)
    {
      if (map->map[boxes[i].x][boxes[i].y] != 'O')
	return (0);
    }
  return (1);
}

int		loop_game(t_map *map, t_entity *player, t_entity *boxes)
{
  char		*res;
  char		line[3];
  int		victory;

  victory = 0;
  while (!victory)
    {
      my_clear_screen();
      victory = is_victory(map, boxes, player->count);
      if (check_win_size(map) == 1)
	return (1);
      show_game(map, player, boxes);
      read(0, line, 3);
      if (line[0] == 27 && line[1] == 91 && line[2] >= 65 && line[2] <= 68)
	move_player(map, player, boxes, line[2]);
      else if (line[0] == 32)
	reset_game(player, boxes);
    }
  return(0);
}
