#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
 
int main(int argc, char *argv[])
{
	int fd;
	int ret;
	
	ret = mkfifo("my_fifo", 0666);//创建命名管道
	if(ret != 0)
	{
		perror("mkfifo");
	}
	
	printf("before open\n");
	fd = open("my_fifo", O_WRONLY); //等着只读
	if(fd < 0)
	{
		perror("open fifo");
	}
	printf("after open\n");
	
	printf("before write\n");
	// 5s后才往命名管道写数据，没数据前，读端read()阻塞
	sleep(5);
    char send[100] = "thief";
    write(fd, send, strlen(send));
    printf("write to my_fifo buf=%s\n", send);

    return 0;
}
