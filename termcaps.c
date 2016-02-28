/*
** termcaps.c for sokoban in /home/bauren_a/Work/tek-1/PSU/semestre_2/PSU_2015_my_sokoban
**
** Made by Arthur
** Login   <bauren_a@epitech.net>
**
** Started on  Fri Feb 26 06:34:48 2016 Arthur
** Last update Sun Feb 28 19:02:04 2016 Arthur
*/

#include <term.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include "sokoban.h"

int	init_term(t_term *term)
{
  char	*term_name;
  char	*res;

  if ((term_name = getenv("TERM")) == NULL)
    return(0);
  if (tgetent(NULL, term_name) != 1)
    return (0);
  if (tcgetattr(0, term) == -1)
    return (0);
  term->c_lflag &= ~ICANON;
  term->c_lflag &= ~ECHO;
  term->c_cc[VMIN] = 1;
  term->c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSADRAIN, term) == -1)
    return (0);
  if ((res = tgetstr("cl", NULL)) == NULL)
    return (0);
  tputs(res, 0, &putchar);
  return (1);
}

int	reset_term(t_term *term)
{
  if (tcgetattr(0, term) == -1)
    return (-1);
  term->c_lflag = ICANON | ECHO;
  if (tcsetattr(0, 0, term) == -1)
    return (-1);
}

void	my_clear_screen()
{
  char	*res;

  if ((res = tgetstr("cl", NULL)) == NULL)
    return;
  tputs(res, 0, &putchar);
}

void		write_centered(char *str)
{
  t_winsize	winsize;
  char		*res;
  int		x;
  int		y;
  int		len;

  if (str == NULL || (res = tgetstr("cm", NULL)) == NULL)
    return;
  len = stlen(str);
  if (ioctl(0, TIOCGWINSZ, (char *) &winsize) < 0)
    return;
  x = winsize.ws_col/2 - len / 2;
  y = winsize.ws_row/2;
  tputs(tgoto(res, x, y), 1, &putchar);
  my_clear_screen();
  write(1, str, len);
  tputs(tgoto(res, 0, 0), 1, &putchar);
}
