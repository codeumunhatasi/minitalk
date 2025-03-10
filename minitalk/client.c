#include "minitalk.h"

static void send_char(t_pid pid, char c)
{
	int i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
		i--;
	}
}

int main(int argc, char **argv)
{
	t_pid   pid;
	int i;

	if (argc != 3)
		write(1, "Too few or too many arguments entered. Please try again.\n",57);
	else
	{
		pid = ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i])
		{
			send_char(pid, argv[2][i]);
			i++;
		}
	}
}