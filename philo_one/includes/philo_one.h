/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coscialp <coscialp@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 09:40:47 by coscialp          #+#    #+#             */
/*   Updated: 2021/01/21 09:07:50 by coscialp         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_fork	t_fork;
struct			s_fork
{
	short			id;
	short			available;
	pthread_mutex_t	mutex;
	t_fork			*right;
	t_fork			*left;
};

typedef struct s_philosoph	t_philosoph;
struct			s_philosoph
{
	bool			is_dead;
	short			id;
	short			eating;
	t_fork			*r_fork;
	t_fork			*l_fork;
	pthread_t		brain;
	pthread_t		eat;
	pthread_mutex_t	mutex_eat;
	pthread_mutex_t	mutex_check;
	struct timeval	last_meal;
	t_philosoph		*right;
	t_philosoph		*left;
};

typedef struct s_rules	t_rules;
struct			s_rules
{
	short	number_of_philo;
	short	time_to_die;
	short	time_to_eat;
	short	time_to_sleep;
	short	number_of_must_eat;
};

typedef struct	s_state
{
	t_fork				*fork;
	t_philosoph			*philosoph;
	pthread_mutex_t		mutex_write;
	pthread_mutex_t		mutex_state;
	pthread_mutex_t		mutex_fork;
	t_rules				rules;
	struct timeval		begin_time;
	time_t				time;
	bool				end;
	int					eating;
}				t_state;

int				ft_write(int fd, char *buf, size_t size);
int				ft_atoi(const char *str);
size_t			ft_strlen(const char *s);
long int		get_time(void);
char			*ft_putnbr(int nb);
bool			ft_stris(char *str, bool (*f)(int));
bool			ft_isdigit(int c);
t_state			*state(void);
int				init_fork(int i);
int				init_philosoph(int i);
int				init_state(int ac, char **av);
int				ft_error(char *msg);
int				ft_standby(int time);
void			display(t_philosoph *philo, char *message);
int				get_timestamp(struct timeval s, struct timeval t);
void			*th_brain(void *philo_ptr);
void			*th_routine(void *philo_ptr);
void			ft_sleep(t_philosoph *philo);
int				ft_eat(t_philosoph *philo);
void			ft_think(t_philosoph *philo);
t_state			*state(void);
int				ft_is_dead(t_philosoph *philo);
void			destroy_mutex(void);
void			*ft_calloc(size_t size, size_t count);

#endif
