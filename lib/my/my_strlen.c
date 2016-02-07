/*
** my_strlen.c for STRLEN in /home/bougon_p/rendu/PSU_2015_minitalk/lib/my
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Feb  1 20:46:00 2016 bougon_p
** Last update Mon Feb  1 20:56:09 2016 bougon_p
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while(str[i] != 0)
    i++;
  return (i);
}
