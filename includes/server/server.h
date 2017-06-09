//
// Created by thauvi_a on 5/22/17.
//

#ifndef IRC_H
# define IRC_H

# include <sys/types.h>
# include <sys/socket.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <netinet/in.h>
# include <netdb.h>
# include <string.h>
# include <arpa/inet.h>
# include <stdbool.h>

typedef struct		s_chan
{
  char 			*name;
  unsigned int		nb_users;
  struct s_chan		*next;
}			t_chan;

typedef struct 		s_client
{
  struct sockaddr_in	s_in_client;
  int 			fd;
  char 			*user;
  char 			*nickname;
  struct s_client	*next;
  char 			*buff_circu;
  unsigned int		front;
  unsigned int		rear;
  unsigned int		n;
  char 			**cmd;
  t_chan		*chan;
}			t_client;

typedef struct 		s_serv
{
  struct s_client	*head;
  int 			port;
  struct protoent	*pe;
  char 			**tab;
  t_chan		*ch_head;
}			t_serv;

void		choice(t_serv *, int);
char 		**ma2d(int, int, t_serv *);
bool		check_end(t_client *);
unsigned int 	nb_word(char *);
char 		**cmd_to_tab(char*, char **, int);
void 		f_nick(t_client *, t_serv *);
void 		f_list(t_client *, t_serv *);
void 		f_join(t_client *, t_serv *);
void 		f_part(t_client *, t_serv *);
void		f_users(t_client *, t_serv *);
void 		f_names(t_client *, t_serv *);
void 		f_msg(t_client *, t_serv *);
void 		f_send_file(t_client *, t_serv *);
void 		f_accept_file(t_client *, t_serv *);
void 		f_user(t_client *, t_serv *);
void 		f_quit(t_client *, t_serv *);
t_client 	*addToChain(t_client *, int, t_serv *);
int 		max_fd(t_client*);
char		*cpy(t_client *, char *);
bool		buff_manage(t_client *, char *);
void 		fill_cmd(t_client *, int, t_serv *);
t_client	*find_clt(t_client *, int, t_serv *);
void		print_at_all(t_client *, t_serv *);
void 		close_all(t_serv *);
t_chan		*add_chan(t_chan *, char *, t_serv *);
t_chan		*find_chan(t_chan *, char *);
void		aff_chan(t_chan *, int);
void 		dlt_chan(t_chan *, char *);
void		quit_error(t_serv *serv);
void 		dltFromChain(t_client *, int);

#endif //IRC_H
