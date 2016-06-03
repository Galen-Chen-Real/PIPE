/*
 *        'pipe.h'
 *     (C) 2014.4 GordonChen
 *
 */
#ifndef _PIPE_H
#define _PIPE_H

#include <stdio.h>
#include <unistd.h>

typedef int PIPEFD[2];

//初始化管道;成功返回0;失败返回-1.
int pipe_init(PIPEFD fd);
//向管道发送数据;成功返回发送出的字节数;失败返回-1.
int pipe_send(PIPEFD fd, const void *buf, int len);
//从管道接收数据;成功返回接收到的字节数;失败返回-1.
int pipe_recv(PIPEFD fd, void *buf, int len);
//关闭管道
void pipe_close(PIPEFD fd);

#endif

