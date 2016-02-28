/*
** player.c for sokoban in /home/bauren_a/Work/tek-1/PSU/semestre_2/PSU_2015_my_sokoban
**
** Made by Arthur
** Login   <bauren_a@epitech.net>
**
** Started on  Sat Feb 27 17:06:22 2016 Arthur
** Last update Sat Feb 27 17:41:17 2016 Arthur
*/

#include "sokoban.h"

int	move_up(t_map *map, t_entity *player, t_entity *boxes)
{
  int	i;

  i = -1;
  while (++i < player->count)
    if (boxes[i].x == player->x && boxes[i].y == (player->y - 1))
      if (map->map[boxes[i].x][boxes[i].y - 1] != '#')
	{
	  boxes[i].y--;
	}
      else
	return(-1);
  if (map->map[player->x][player->y - 1] != '#')
    player->y--;
  return (0);
}

int	move_down(t_map *map, t_entity *player, t_entity *boxes)
{
  int	i;

  i = -1;
  while (++i < player->count)
    if (boxes[i].x == player->x && boxes[i].y == (player->y + 1))
      if (map->map[boxes[i].x][boxes[i].y + 1] != '#')
	{
	  boxes[i].y++;
	}
      else
	return(-1);
  if (map->map[player->x][player->y + 1] != '#')
    player->y++;
  return (0);
}

int	move_right(t_map *map, t_entity *player, t_entity *boxes)
{
  int	i;

  i = -1;
  while (++i < player->count)
    if (boxes[i].x == (player->x + 1) && boxes[i].y == player->y)
      if (map->map[boxes[i].x + 1][boxes[i].y] != '#')
	{
	  boxes[i].x++;
	}
      else
	return(-1);
  if (map->map[player->x + 1][player->y] != '#')
    player->x++;
  return (0);
}

int	move_left(t_map *map, t_entity *player, t_entity *boxes)
{
  int	i;

  i = -1;
  while (++i < player->count)
    if (boxes[i].x == (player->x - 1) && boxes[i].y == player->y)
      if (map->map[boxes[i].x - 1][boxes[i].y] != '#')
	{
	  boxes[i].x--;
	}
      else
	return(-1);
  if (map->map[player->x - 1][player->y] != '#')
    player->x--;
  return (0);
}

int     move_player(t_map *map, t_entity *player, t_entity *boxes, char key)
{
  if (key == 65)
    move_up(map, player, boxes);
  if (key == 66)
    move_down(map, player, boxes);
  if (key == 67)
    move_right(map, player, boxes);
  if (key == 68)
    move_left(map, player, boxes);
  return (0);
}
