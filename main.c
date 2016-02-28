/*
** min.c for compactor in /home/bauren_a/Work/tek-1/CPE/CPE_2015_compactor
**
** Made by Arthur
** Login   <bauren_a@epitech.net>
**
** Started on  Mon Feb 15 14:38:17 2016 Arthur
** Last update Sun Feb 28 19:02:20 2016 Arthur
*/

#include <term.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include "sokoban.h"

int	count_line(char *str)
{
  int	i;
  int	j;

  i = -1;
  j = 0;
  while (str[++i])
    if (str[i] == '\n')
      j++;
  return (j);
}

t_map	*alloc_table(t_map *map, char *file)
{
  int	i;
  int	j;

  map->w = sl(file, '\n');
  if ((map->h = count_line(file)) == 0 || map->w == 0)
    return (NULL);
  if ((map->map = malloc(sizeof(char *) * map->w + (0 * (j = -1)))) == NULL)
    return (NULL);
  while (++j < map->w + (0 * (i = -1)))
    if ((map->map[j] = malloc(sizeof(char) * map->h)) == NULL)
      return (NULL);
  while (file[++i])
    {
      if (file[i] == '\n')
	{
	  if (sl(&file[i + 1], '\n') != map->w && sl(&file[i + 1], '\n') != -1)
	    return (NULL);
	  continue;
	}
	map->map[i % (map->w + 1)][i / (map->w + 1)] = file[i];
    }
  free(file);
  return (map);
}

int	load_file(t_map *map,
		  t_entity *player,
		  t_entity **boxes,
		  char *filepath)
{
  int	fd;
  int	size;
  char	buffer[1024 + 1];
  char	*tmp;
  char	*result;

  result = NULL;
  fd = open(filepath, O_RDONLY);
  while ((size = read(fd, buffer, 1024)) > 0)
    {
      buffer[size] = 0;
      tmp = result;
      if (result == NULL)
	result = my_strcpy(buffer);
      else
	result = my_strcat(result, buffer, size);
      free(tmp);
    }
  close(fd);
  return (size < 0 ? 0 : set_entitys(player, boxes, alloc_table(map, result)));
}

void		show_game(t_map *map, t_entity *player, t_entity *boxes)
{
  t_winsize	winsize;
  char		*res;
  int		x;
  int		y;
  int		posx;
  int		posy;

  res = tgetstr("cm", NULL);
  if (ioctl(0, TIOCGWINSZ, (char *) &winsize) < 0 || res == NULL)
    return;
  posx = winsize.ws_col/2 - map->w/2;
  posy = winsize.ws_row/2 - map->h/2 + (0 * (y = -1));
  while (++y < map->h && ((x = -1) == -1))
    while (++x < map->w)
      {
	tputs(tgoto(res, posx + x, posy + y), 1, &putchar);
	write(1, &(map->map[x][y]), 1);
      }
  draw_entitys(boxes, res, player, map);
  tputs(tgoto(res, 0, 0), 1, &putchar);
}

int		main(int ac, char **av)
{
  int		result;
  t_map		map;
  t_term	term;
  t_entity	player;
  t_entity	*boxes;

  if (ac < 2 || init_term(&term) == 0)
    return (1);
  if (load_file(&map, &player, &boxes, av[1]) == 0)
    {
      write(2, "[ERROR] unable to load file ", 28);
      write(2, av[1], stlen(av[1]));
      write(2, "\n", 1);
      return (1);
    }
  show_game(&map, &player, boxes);
  if (loop_game(&map, &player, boxes) == 1)
    return (1);
  reset_term(&term);
  free_map(&map);
  free(boxes);
  return (0);
}
