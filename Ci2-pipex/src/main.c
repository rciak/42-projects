#include "pipex.h"

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	write(STDOUT_FILENO, "Hello World!\n", 14);
}
