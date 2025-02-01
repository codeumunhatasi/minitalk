#include "minitalk.h"

void signal_process(int signal)
{
    static int  i;
    static unsigned char    x;

    if (signal == SIGUSR1)
        x = x | 1;
    i++;
    if (i == 8)
    {
        ft_printf("%c", x);
        i = 0;
        x = 0;
    }
    x = x << 1;
}

int main(void)
{
    ft_printf("Server started with PID: %d\n", getpid());
    signal(SIGUSR1, signal_process);
    signal(SIGUSR2, signal_process);
    while (1)
        pause();
    return (0);
}