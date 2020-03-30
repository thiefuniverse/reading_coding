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
	
	ret = mkfifo("my_fifo", 0666); //创建命名管道
	if(ret != 0)
	{
		perror("mkfifo");
	}
	
	printf("before open\n");
	fd = open("my_fifo", O_RDONLY);//等着只写
	if(fd < 0)
	{
		perror("open fifo");
	}
	printf("after open\n");
	
	printf("before read\n");
	char recv[100] = {0};
	
	//读数据，命名管道没数据时会阻塞，有数据时就取出来
	read(fd, recv, sizeof(recv));
    printf("read from my_fifo buf=[%s]\n", recv);

    return 0;
}
