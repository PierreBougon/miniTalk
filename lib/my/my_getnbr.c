/*
** my_getnbr.c for getnbr in /home/bougon_p/rendu/PSU_2015_minitalk/lib/my
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Feb  1 22:52:39 2016 bougon_p
** Last update Mon Feb  1 23:18:35 2016 bougon_p
*/

int	my_getnbr(char *str)
{
  int	nb;
  int	i;
  int	boole;

  nb = 0;
  i = 0;
  boole = 0;
  if (str[i] == '-')
    {
      nb = -nb;
      i++;
      boole = i;
    }
  while (str[i] != 0)
    {
      nb = 10 * nb + (str[i] - 48);
      i++;
    }
  return (boole == 1 ? -nb : nb);
}
