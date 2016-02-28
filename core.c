/*
** core.c for sokoban in /home/bauren_a/Work/tek-1/PSU/semestre_2/PSU_2015_my_sokoban
**
** Made by Arthur
** Login   <bauren_a@epitech.net>
**
** Started on  Thu Feb 25 21:02:34 2016 Arthur
** Last update Sat Feb 27 17:46:00 2016 Arthur
*/

#include <term.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include <sys/ioctl.h>
#include "sokoban.h"

void		draw_entitys(t_entity *boxes, char *res, t_entity *player, t_map *map)
{
  t_winsize	winsize;
  int		posx;
  int		posy;
  int		i;

  if (ioctl(0, TIOCGWINSZ, (char *) &winsize) < 0)
    return;
  posx = winsize.ws_col/2 - map->w/2;
  posy = winsize.ws_row/2 - map->h/2;
  i = -1;
  while (++i < player->count)
    {
      tputs(tgoto(res, posx + boxes[i].x, posy + boxes[i].y), 1, &putchar);
      write(1, "X", 1);
    }
  tputs(tgoto(res, posx + player->x, posy + player->y), 1, &putchar);
  write(1, "P", 1);
}

int	putchar(int c)
{
  return (write(1, &c, 1));
}

int	count_box(t_map *map)
{
  int	x;
  int	y;
  int	box_count;
  int	out_count;
  int	player_count;

  if (((box_count = 0) == 0) && map == NULL || map->map == NULL)
    return (0);
  y = -1;
  out_count = 0;
  player_count = 0;
  while (++y < map->h && ((x = -1) == -1))
    {
      while (++x < map->w)
	{
	  if (map->map[x][y] == 'X')
	    box_count++;
	  if (map->map[x][y] == 'O')
	    out_count++;
	  if (map->map[x][y] == 'P')
	    if (++player_count > 1)
	      return (0);
	}
    }
  return (box_count);
}

void	set_entity_position(t_map *map, t_entity *entity, int x, int y)
{
  entity->x = x;
  entity->y = y;
  entity->fy = y;
  entity->fx = x;
  map->map[x][y] = ' ';
}

int		set_entitys(t_entity *player, t_entity **boxes, t_map *map)
{
  int		x;
  int		y;
  int		box_count;
  t_entity	*tmp;

  box_count = 0;
  if ((player->count = count_box(map)) == 0)
    return (0);
  if (map == NULL || map->map == NULL)
    return (0);
  if ((*boxes = malloc(sizeof(t_entity) * player->count)) == NULL)
    return (0);
  y = -1;
  while (++y < map->h && ((x = -1) == -1))
    {
      while (++x < map->w)
	{
	  if (map->map[x][y] == 'P' || map->map[x][y] == 'X')
	    {
	      tmp = (map->map[x][y] == 'P' ? player : &((*boxes)[box_count++]));
	      set_entity_position(map, tmp, x, y);
	    }
	}
    }
  return (1);
}
