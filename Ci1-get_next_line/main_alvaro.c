#include <stdio.h>
#include <fcntl.h>
int main()
{
    int    fd = open("test", O_RDONLY);
    char    *ptr;
    int i;

    i = 0;
    while (1)
    {
    ptr = get_next_line(fd);
    if (!ptr)
    {
        printf("ITS NULL!!");
        return (1);
    }
    printf("%s", ptr);
    free(ptr);
    ptr = NULL;
    i++;
    }
    close(fd);
    return (0);
    }
