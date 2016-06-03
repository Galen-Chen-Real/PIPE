/*
 *        'pipe.c'
 *     (C) 2014.4 GordonChen
 *
 */
#include "pipe.h"

int pipe_init(PIPEFD fd)
{
    if(pipe(fd))
    {
        perror("pipe() failed");
        return -1;
    }
    return 0;
}

int pipe_send(PIPEFD fd, const void *buf, int len)
{
    return write(fd[1], buf, len);
}

int pipe_recv(PIPEFD fd, void *buf, int len)
{
    return read(fd[0], buf, len);
}

void pipe_close(PIPEFD fd)
{
    close(fd[0]);
    close(fd[1]);
}

