/*
** freeer.c for sokoban in /home/bauren_a/Work/tek-1/PSU/semestre_2/PSU_2015_my_sokoban
**
** Made by Arthur
** Login   <bauren_a@epitech.net>
**
** Started on  Thu Feb 25 20:39:36 2016 Arthur
** Last update Thu Feb 25 20:42:00 2016 Arthur
*/

#include <stdlib.h>
#include "sokoban.h"

void	*free_map(t_map *map)
{
  int	x;

  x = -1;
  while (++x < map->w)
    free(map->map[x]);
  free(map->map);
  return (map = NULL);
}
