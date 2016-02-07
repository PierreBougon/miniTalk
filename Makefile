##
## Makefile for MINITALK in /home/bougon_p/rendu/PSU_2015_minitalk
## 
## Made by bougon_p
## Login   <bougon_p@epitech.net>
## 
## Started on  Mon Feb  1 18:33:22 2016 bougon_p
## Last update Sun Feb  7 05:21:29 2016 bougon_p
##

# USEFUL VARIABLES

RM      =	rm -rf

GREEN	=	\033[1;32m

WHITE	=	\033[0m

ECHO	=	echo -e


# SOURCES VARIABLES

DIR_CLIENT	=	client

DIR_SERVER	=	server

DIR_CL		=	$(DIR_CLIENT)/src/main/

DIR_SRV		=	$(DIR_SERVER)/src/main/

SRCCLI		=	$(DIR_CL)client.c \
			$(DIR_CL)setnbr.c \
			$(DIR_CL)my_power.c

SRCSERV		=	$(DIR_SRV)server.c \
			$(DIR_SRV)util.c

OBJCLIENT    	=	$(SRCCLI:.c=.o)

OBJSERVER    	=	$(SRCSERV:.c=.o)


# LIBRARY VARIABLES

LIBPATH =	lib/

LIB	=	-lmy

LDFLAGS =	-lmy -L$(LIBPATH)


# PROJECT VARIABLES

CLIENT  =	clientbin

SERVER	=	serverbin

IFLAG	=	-Iinclude/

CFLAGS  =	-W -Wextra -Wall -Werror -ansi -pedantic $(IFLAG)

CC      =	gcc $(CFLAGS)



# PROJECT RULES

$(SERVER)	:	$(OBJSERVER) $(CLIENT)
			@$(ECHO) "$(GREEN)\n> Compiling server\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"
			@$(CC) -o $(SERVER) $(OBJSERVER) $(LDFLAGS)
			@cp $(SERVER) $(DIR_SERVER)/server

$(CLIENT)	: 	$(OBJCLIENT)
			@$(ECHO) "$(GREEN)\n> Compiling client\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"
			@$(CC) -o $(CLIENT) $(OBJCLIENT) $(LDFLAGS)
			@cp $(CLIENT) $(DIR_CLIENT)/client


all		:	$(SERVER) 

clean		:
			@$(RM) $(OBJCLIENT) $(OBJSERVER)
			@$(ECHO) "$(GREEN)\n> Cleaning repository\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"

fclean		: 	clean
			@$(RM) $(CLIENT) $(SERVER) $(DIR_CLIENT)/client $(DIR_SERVER)/server
			@$(ECHO) "$(GREEN)\n> Cleaning exec\t\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"

re		:	fclean all

.c.o		:
			@$(CC) -c $< -o $@
			@$(ECHO) "$(GREEN)> $<\t : \t [OK]$(WHITE)"
