/*
** client.c for MAIN in /home/bougon_p/rendu/PSU_2015_minitalk/client/src/main
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Feb  1 19:04:48 2016 bougon_p
** Last update Fri Feb  5 13:18:31 2016 bougon_p
*/

#include "minitalk.h"

int	cond;

void	pause_prog(int sig)
{
  (void)sig;
  signal(SIGUSR2, pause_prog);
  cond = 1;
}

int		push_byte(char c, int serv_pid, int pid_cond)
{
  t_byte	byte;
  int		ret;
  int		i;

  i = 0;
  byte.u8loctet = c;
  while (i < 8)
    {
      (byte.bit.bit0 == 0) ?
  	(ret = kill(serv_pid, SIGUSR1)) : (ret = kill(serv_pid, SIGUSR2));
      if (ret == -1)
	{
	  write(2, "Kill problem\n", 13);
	  exit (1);
	}
      while (cond != 1 && pid_cond == 0);
      cond = 0;
      if (i == 7)
	usleep(1);
      if (pid_cond == 1)
	usleep(100);
      byte.u8loctet = byte.u8loctet << 1;
      i++;
    }
  return (0);
}

int	push_data(int serv_pid, char *str, int pid_cond)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      push_byte(str[i], serv_pid, pid_cond);
      i++;
    }
  push_byte(str[i], serv_pid, pid_cond);
  return (0);
}

int	send_pid(int serv_pid, int pid_cond)
{
  int	pid;
  char	*my_pid;

  pid = getpid();
  my_pid = setnbr(pid);
  push_data(serv_pid, my_pid, pid_cond);
  free(my_pid);
  return (0);
}

int	main(int ac, char **av, char **env)
{
  int	serv_pid;
  int	pid_cond;

  if (env[0] == NULL)
    return (1);
  if (ac != 3)
    {
      write(2, "Wrong usage : ./client PID data\n", 32);
      return (1);
    }
  cond = 0;
  pid_cond = 1;
  signal(SIGUSR2, pause_prog);
  serv_pid = my_getnbr(av[1]);
  send_pid(serv_pid, pid_cond);
  pid_cond = 0;
  push_data(serv_pid, av[2], pid_cond);
  return (0);
}
