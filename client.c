#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
  int fd = open("mypipe",O_WRONLY);
  if(fd<0)
  {
    perror("open");
    return 1;
  }
  char buf[1024];
  while(1)
  {
    printf("Please input your message to server# ");
    fflush(stdout);
    //从标准输入获取数据
    ssize_t _s = read(0,buf,sizeof(buf)-1);
    buf[_s-1]=0;
    write(fd,buf,strlen(buf));
  }
  close(fd);
  return 0;
}
