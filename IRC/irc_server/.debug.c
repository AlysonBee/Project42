
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int		sign_catch(int sig)
{
	int i;

	i = sig;
	exit(1);
}
