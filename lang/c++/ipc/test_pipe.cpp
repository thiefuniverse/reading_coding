#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void sys_err(const char *str) {
    perror(str);
    exit(1);
}

//无名pipe的使用
int main(void)  
{  
    pid_t pid;  
    char buf[1024];  
    int fd[2];  
    char p[] = "test for pipe\n";  
          
    if (pipe(fd) == -1)  //创建管道  
        sys_err("pipe");  
      
    pid = fork();  // 创建子进程
    if (pid < 0) {  
        sys_err("fork err");  
    }
    else if (pid == 0) {  
        close(fd[1]);    //关闭写描述符
        printf("child process wait to read:\n");
        int len = read(fd[0], buf, sizeof(buf));  //等待管道上的数据  
        printf("child received: %s", p);
        write(STDOUT_FILENO, buf, len);  
        close(fd[0]);  
    }
    else {  
        close(fd[0]);  //关闭读描述符
        write(fd[1], p, strlen(p));   //向管道写入字符串数据wait(NULL);
        close(fd[1]);
    }

    return 0;
}
