/*
** string.c for sokoban in /home/bauren_a/Work/tek-1/PSU/semestre_2/PSU_2015_my_sokoban
**
** Made by Arthur
** Login   <bauren_a@epitech.net>
**
** Started on  Sun Feb 28 19:04:54 2016 Arthur
** Last update Sun Feb 28 19:04:55 2016 Arthur
*/

#include <stdlib.h>

int	sl(char *str, char c)
{
  int	i;

  i = -1;
  if (str == NULL)
    return (0);
  while (str[++i])
    if (str[i] == c)
      return (i);
  return (c == '\0' ? i : -1);
}
int	stlen(char *str)
{
  int	i;

  i = -1;
  if (str == NULL)
    return (0);
  while (str[++i]);
  return (i);
}

int	getnbr(const char *str)
{
  int	i;
  int	sign;
  int	result;

  i = 0;
  sign = 1;
  result = 0;
  while (str[i] == '-' || str[i] == '+')
    {
      if (str[i] == '-')
	sign *= -1;
      i++;
    }
  while (str[i])
    {
      if ((str[i] < '0' || str[i] > '9'))
	return (result * sign);
      result *= 10;
      result += (str[i] - '0');
      i++;
    }
  return (result * sign);
}

char	*my_strcat(char *str1, char *str2, int  len2)
{
  int	i;
  int	len;
  char	*ret;

  i = 0;
  len = stlen(str1);
  if ((ret = malloc(sizeof(char) * (len + len2) + 1)) == NULL)
    return (NULL);
  while (*str1)
    {
      ret[i] = str1[0];
      str1 = &str1[1];
      i++;
    }
  while (*str2)
    {
      ret[i] = str2[0];
      str2 = &str2[1];
      i++;
    }
  ret[i] = 0;
  return (ret);
}

char	*my_strcpy(char *str)
{
  int	i;
  int	len;
  char	*ret;

  i = 0;
  len = stlen(str);
  if ((ret = malloc(sizeof(char) * len + 1)) == NULL)
    return (NULL);
  while (i < len)
    {
      ret[i] = str[i];
      i++;
    }
  ret[i] = 0;
  return (ret);
}
