/*
** serv.c for  in /home/bougon_p/rendu/PSU_2015_minitalk/server/src/main
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Feb  1 19:13:39 2016 bougon_p
** Last update Sun Feb  7 05:23:50 2016 bougon_p
*/

#include "minitalk.h"

t_recep	recep;

void	get_sig1(int sig)
{
  (void)sig;
  recep.tabbit[recep.pbit++] = 0;
  signal(SIGUSR1, get_sig1);
  if (recep.client_cond == -1)
    kill(recep.cl_pid, SIGUSR2);
  recep.cond = 1;
}

void	get_sig2(int sig)
{
  (void)sig;
  recep.tabbit[recep.pbit++] = 1;
  signal(SIGUSR2, get_sig2);
  if (recep.client_cond == -1)
    kill(recep.cl_pid, SIGUSR2);
  recep.cond = 1;
}

char	*recep_pid(char *client_pid)
{
  recep = fill_union(recep);
  if (recep.byte.u8loctet == 0)
    {
      recep.cl_pid = my_getnbr(client_pid);
      recep.pbit = -1;
      recep.client_cond = -1;
      return (client_pid);
    }
  client_pid = my_realloc(client_pid, recep.byte.u8loctet);
  return (client_pid);
}

int	serv_loop(char *client_pid)
{
  while (1)
    {
      if (recep.pbit == 8 && recep.client_cond == 0)
	client_pid = recep_pid(client_pid);
      if (recep.pbit == 8 && recep.client_cond == -1)
	{
	  recep = fill_union(recep);
	  if (recep.byte.u8loctet == 0)
	    {
	      recep.pbit = -1;
	      client_pid = initstr(client_pid);
	      recep.client_cond = 0;
	    }
	  my_putchar(recep.byte.u8loctet);
	}
      if (recep.pbit == -1)
	recep.pbit = 0;
      while (recep.cond != 1);
      recep.cond = 0;
    }
  return (0);
}

int	main()
{
  int	pid;
  char  *client_pid;

  client_pid = NULL;
  client_pid = initstr(client_pid);
  recep.client_cond = 0;
  recep.cond = 0;
  pid = getpid();
  my_put_nbr(pid);
  recep.pbit = 0;
  recep.lastpbit = recep.pbit;
  signal(SIGUSR1, get_sig1);
  signal(SIGUSR2, get_sig2);
  serv_loop(client_pid);
  return (0);
}
