#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct Msg
{
    long mytype;
    char m_name[20];
    char m_text[1000];
};

int main()
{
    struct Msg msg;
    char writer[] = "bob";
    key_t key = ftok(".", 0x00);
    int msgid = msgget(key, IPC_CREAT | 0666);
    pid_t pid = fork();

    if (pid == 0)
    {
        while (1)
        {
            printf("请输入接收者的名字:");
            char x_name[20];
            fgets(x_name, sizeof(x_name), stdin);
            printf("请输入内容:");
            fgets(msg.m_text, sizeof(msg.m_text), stdin);
            if (x_name == "lucy" || x_name == "bob")
            {
                if (x_name == "lucy")
                {
                    msg.mytype = 103;
                }
                if (x_name == "tom")
                {
                    msg.mytype = 102;
                }

                msgsnd(msgid, &msg, sizeof(msg) - sizeof(long), 0); //默认阻塞等待消息发送到消息队列
            }
        }
    }
    else
    {
        while (1)
        {
            msgrcv(msgid, &msg, sizeof(msg) - sizeof(long), 101, 0);
            printf("\r message from %s: %s\n", msg.m_name, msg.m_text);
        }
    }

    return 0;
}