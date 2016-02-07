/*
** setnbr.c for SETNBR in /home/bougon_p/rendu/gfx_tekpaint
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Jan 22 05:11:57 2016 bougon_p
** Last update Thu Feb  4 05:09:17 2016 bougon_p
*/

#include "minitalk.h"

char	*cleanstr(char *nbr)
{
  char	*clean;
  int	p;
  int	i;

  if ((clean = malloc(sizeof(char) * 10)) == NULL)
    return (NULL);
  p = 0;
  while (nbr[p] != 0 && nbr[p++] == '0');
  i = 0;
  p--;
  while (nbr[p] != 0)
    clean[i++] = nbr[p++];
  free(nbr);
  return (clean);
}

char	*setnbr(int nbr)
{
  char	*numb;
  int	i;
  int	p;

  p = 10;
  if ((numb = malloc(sizeof(char) * 10)) == NULL)
    return (NULL);
  numb[9] = 0;
  i = 0;
  while (p >= 0)
    numb[p--] = ((nbr / (int)(my_pow(10, i++)) % 10) + '0');
  return (cleanstr(numb));
}
