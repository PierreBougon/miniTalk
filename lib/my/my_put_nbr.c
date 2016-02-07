/*
** my_put_nbr.c for put nbr in /home/bougon_p
** 
** Made by Pierre Bougon
** Login   <bougon_p@epitech.net>
** 
** Started on  Tue Oct  6 11:34:10 2015 Pierre Bougon
** Last update Fri Oct  9 15:39:25 2015 Pierre Bougon
*/

int	my_calc_nbr(int nbr)
{
  if (nbr >= 10)
    my_calc_nbr(nbr / 10);
  if (nbr > 0)
    my_putchar((nbr % 10) + 48);
}

int	my_put_nbr(int nbr)
{
  if (nbr == 0)
    {
      my_putchar('0');
      return (0);
    }
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = -nbr;
    }
  my_calc_nbr(nbr);
}
