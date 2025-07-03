#include "get_next_line.h"
#include <stdio.h>
#include <assert.h>
# include <fcntl.h>
# include <unistd.h>
// #include <string.h>

int main()
{
	int	fd = open("der_panther", O_RDONLY);
	char	*ptr;

	while(1)
	{
		ptr = get_next_line(fd);
		if (!ptr)
		{
			close(fd);
			return(1);
		}
		printf("%s", ptr);
		free(ptr);
	}
	close(fd);
	return (0);
}

// int main()
// {
// 	int	fd = open("43_no_nl", O_RDONLY);
// 	char	*ptr;
// 	int i;

// 	printf("String: '%s'\n", get_next_line(fd));
// 	// assert(0 == strcmp("0123456789012345678901234567890123456789012", get_next_line(fd)));
// 	// printf("String: '%p'\n", get_next_line(fd));
// 	assert(NULL == get_next_line(fd));

// 	close(fd);
// 	return (0);
// }
