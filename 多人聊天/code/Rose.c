#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>

#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>

//自定义消息结构体
struct msgbuf
{
    long mtype;
    char name[20];
    char mtext[64];
};

int main(int argc, char *argv[])
{
    //定义key值
    key_t key;
    key = ftok(".", 10);

    //申请消息队列ID号
    int msgid;
    msgid = msgget(key, IPC_CREAT | 0666);

    struct msgbuf buf;
    strcpy(buf.name,"Rose");

    pid_t pid = fork();
    //父进程持续读信息
    if (pid > 0)
    {
        printf("I'm Rose.\n");
        while (1)
        {

            memset(buf.mtext, 0, sizeof(buf.mtext));

            //从队列中读标识是1的信息
            msgrcv(msgid, &buf, 64, 1, 0);

            printf("receive from %s:%s", buf.name, buf.mtext);
            //收到quit后，杀掉子进程，之后退出
            if (strncmp(buf.mtext, "quit", 4) == 0)
            {
                kill(pid, SIGKILL);
                break;
            }
        }
        wait(NULL);
    }
    //子进程持续发信息
    if (pid == 0)
    {
        while (1)
        {
            memset(buf.mtext, 0, sizeof(buf.mtext));
            printf("name:");
            char name[20] = {0};
            scanf("%s",name);
            char ch=getchar();
            if (name[0] == 'J')
            {
                buf.mtype = 2;
            }
            if (name[0] == 'R')
            {
                buf.mtype = 1;
            }
            if (name[0] == 'T')
            {
                buf.mtype = 3;
            }

            fgets(buf.mtext, 64, stdin);
            msgsnd(msgid, &buf, strlen(buf.mtext)+20, 0);
            //发送quit后，杀掉父进程，之后退出
            if (strncmp(buf.mtext, "quit", 4) == 0)
            {
                kill(getppid(), SIGKILL);
                break;
            }
        }
    }
    //删除队列消息
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}
