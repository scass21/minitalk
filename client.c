#include "minitalk.h"

static void	sig_proc(int signum)
{
	(void)signum;
}

static	int	send_msg(int pid, char c)
{
	int		i;
	int		check_connect;

	i = 0;
	check_connect = 0;
	while (i <= 7 && check_connect >= 0)
	{
		if (c & 1 << i)
			check_connect = kill(pid, SIGUSR1);
		else
			check_connect = kill(pid, SIGUSR2);
		i++;
		usleep(20000);
	}
	if (check_connect == -1)
		return (1);
	return (0);
}

int	error_handler(char *str)
{
	ft_putstr_fd(str, 2);
	return (1);
}

int	main (int argc, char **argv)
{
	pid_t	pid;
	int		i;
	int		sending_error;

	i = 0;
	sending_error = 0;
	if (argc != 3)
		return (error_handler("Error: Invalid number of arguments\n"));
	pid = ft_atoi(argv[1]);
	if (pid <= 0 )
		return (error_handler("Error: Wrong PID number\n"));
	signal(SIGUSR1, sig_proc);
	while (!sending_error)
	{	
		sending_error = send_msg(pid, argv[2][i]);
		if (sending_error || argv[2][i] == '\0')
			break ;
		i++;
	}
	if (sending_error)
		return (error_handler("Error: something wrong \n"));
	if (signal(SIGUSR1, sig_proc) && !sending_error)
		ft_putstr("Success\n");
	return (0);
}
