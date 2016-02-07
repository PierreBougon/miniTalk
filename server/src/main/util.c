/*
** util.c for UTILS in /home/bougon_p/rendu/PSU_2015_minitalk/server/src/main
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Feb  7 05:12:15 2016 bougon_p
** Last update Sun Feb  7 05:28:24 2016 bougon_p
*/

#include "minitalk.h"

char	*initstr(char *str)
{
  if (str != NULL)
    free(str);
  if ((str = malloc(sizeof(char) * 1)) == NULL)
    return (NULL);
  str[0] = 0;
  return (str);
}

char	*my_realloc(char *str, char c)
{
  char  *newstr;
  int   size;
  int   i;

  size = my_strlen(str);
  if ((newstr = malloc(sizeof(char) * size + 2)) == NULL)
    return (NULL);
  i = 0;
  while (str[i] != 0)
    {
      newstr[i] = str[i];
      i++;
    }
  newstr[size] = c;
  newstr[size + 1] = 0;
  free(str);
  return (newstr);
}

t_recep		fill_union(t_recep chr)
{
  chr.byte.bit.bit0 = chr.tabbit[0];
  chr.byte.bit.bit1 = chr.tabbit[1];
  chr.byte.bit.bit2 = chr.tabbit[2];
  chr.byte.bit.bit3 = chr.tabbit[3];
  chr.byte.bit.bit4 = chr.tabbit[4];
  chr.byte.bit.bit5 = chr.tabbit[5];
  chr.byte.bit.bit6 = chr.tabbit[6];
  chr.byte.bit.bit7 = chr.tabbit[7];
  chr.pbit = 0;
  return (chr);
}
