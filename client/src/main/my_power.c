/*
** my_power_rec.c for power rec in /home/bougon_p/rendu/Piscine_C_J05
**
** Made by Pierre Bougon
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Oct  2 14:25:40 2015 Pierre Bougon
** Last update Thu Feb  4 05:26:10 2016 bougon_p
*/

int	my_pow(int nb, int power)
{
  int	tmp;

  if (power == 0)
    return (1);
  tmp = my_pow(nb, power / 2);
  if (power % 2 == 0)
    return (tmp * tmp);
  else
    return (nb * tmp * tmp);
}
/*
** Optimized algorith to calculate power
*/
