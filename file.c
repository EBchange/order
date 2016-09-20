#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
int main()
{
	int fd;					//值为3，0，1，2被占用
	char buf[1024];
	int ret;
	long long pos;

	memset(buf, 0, 1024);
	fd = open("111", O_RDONLY | O_SYNC);
	if(fd < 0){
		printf("open error\n");
		return -1;
	}
	
	printf("%d\n", fd);
	pos = lseek(fd, 2, SEEK_SET);
	printf("pos=%lld\n", pos);
	ret=read(fd, buf, 1024);
	if (ret  < 0){
		printf("read error\n");
	}
	
	buf[ret] = '\0';
	write(fd, buf, ret);
	printf("buf:%s\n", buf);
	close(fd);	
}
