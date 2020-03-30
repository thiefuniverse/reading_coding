#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

#define SIZE 1024
extern int errno;
int main(int argc, char *argv[]) {
    int *fib;
    int n;
    int i = 0;
    scanf("%d", &n);
    if (n < 0) printf("request a non-negative number!\n");
    int shmid;
    key_t key;
    pid_t pid;
    int *shmptr;
    if ((key = ftok(".", 1)) < 0) {
        //由ftok得到IPC键值
        printf("ftok error!\n");
        return -1;
    }
    if ((shmid = shmget(( key_t )8899, SIZE, IPC_CREAT | 0660)) < 0) {  //创建共享存储区
        printf("shmget error!\n");
        exit(-1);
    }
    shmptr = ( int * )shmat(shmid, NULL, 0);  //连接共享存储区
    fib = shmptr;                             //斐波那契数组的指针指向共享存储区地址，即共享该数组空间
    if (fib == ( int * )(-1)) {
        printf("shmat error!\n");
        exit(-1);
    }
    pid = fork();
    if (pid < 0) {  //创建子进程失败
        printf("fork error!\n");
        return -1;
    } else if (pid == 0) {  //在子进程中
        if (argc == 1) {

            printf("change it.\n");
            fib[0] = 0;
            fib[1] = 1;
            for (i = 2; i < n; ++i) {  //计算斐波那契数列
                fib[i] = fib[i - 1] + fib[i - 2];
            }
            // if ((shmctl(shmid, IPC_RMID, 0) < 0)) {  //控制共享存储区
            //    printf("shmctl error!\n");
            //    exit(-1);
            //}
            exit(0);
        }
    } else {      //父进程
        wait(0);  //等待子进程结束
        if (argc == 1) {
            scanf("%d", &n);
        }
        if (argc > 1) {
            for (i = 0; i < n; ++i)
                printf("%d ", fib[i]);
            printf("\n");
        }
        if (shmdt(fib) == -1) {
            printf("shmdt error!\n");
            exit(-1);
        }
    }
    exit(0);
}
