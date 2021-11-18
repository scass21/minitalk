#include "minitalk.h"

void	get_msg(int signum, siginfo_t *info, void *ucontext)
{
	static char	c;
	static int	i;

	(void)ucontext;
	if (signum == SIGUSR1)
		c += 1 << i;
	i++;
	if (i == 8)
	{
		if (c == '\0')
			c = '\n';
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	kill (info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sig;

	ft_putstr_fd("PID = ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sig.sa_sigaction = get_msg;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
