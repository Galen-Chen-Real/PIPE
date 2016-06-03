#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "pipe.h"

int main(void)
{
    int fd[2];
    int count;
    int res;
    
    if(pipe_init(fd))
    {
        printf("pipe_init() failed!\n");
        exit(1);
    }
    
    if(!fork())
    {
        count = 100;
        sleep(5);
        pipe_send(fd, &count, 4);
    }
    else
    {
        count = 0;
        pipe_recv(fd, &count, 4);
        printf("count = %d\n", count);
    }
    
    pipe_close(fd);
}

