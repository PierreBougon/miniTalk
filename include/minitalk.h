/*
** minitalk.h for HEADER in /home/bougon_p/rendu/PSU_2015_minitalk/include
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Feb  1 21:11:40 2016 bougon_p
** Last update Mon Feb  8 23:01:57 2016 bougon_p
*/

#ifndef MINITALK_H_
# define MINITALK_H_

# define _POSIX_SOURCE
# define _BSD_SOURCE

# include <stdio.h>
# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

# include "my.h"

typedef unsigned int	mbyte;

typedef struct	s_bit
{
  mbyte		bit7	:1;
  mbyte		bit6	:1;
  mbyte		bit5	:1;
  mbyte		bit4	:1;
  mbyte		bit3	:1;
  mbyte		bit2	:1;
  mbyte		bit1	:1;
  mbyte		bit0	:1;
}		t_bit;

typedef	union		u_byte
{
  unsigned char		u8loctet;
  t_bit			bit;
}			t_byte;

typedef struct		s_recep
{
  t_byte		byte;
  int			lastpbit;
  int			pbit;
  mbyte			tabbit[8];
  int			cl_pid;
  int			client_cond;
  int			cond;
}			t_recep;

/*
** Tools functions
*/
char	*initstr(char *);
char	*my_realloc(char *, char);
t_recep	fill_union(t_recep);
char	*setnbr(int);
int	my_pow(int, int);

#endif /* !MINITALK_H_ */
