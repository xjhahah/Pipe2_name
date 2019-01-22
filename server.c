#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
  mkfifo("mypipe",0644);
  int fd = open("mypipe",O_RDONLY);
  if(fd<0)
  {
    perror("open");
    return 1;
  }
  char buf[1024];
  while(1)
  {
    ssize_t s = read(fd,buf,sizeof(buf)-1);
    if(s>0)
    {

      buf[s]=0;
      printf("client echo# %s\n",buf);
    }
    else if(s == 0)
    {
      printf("client quit...\n");
      break;
    }
    else{break;}
  }
  close(fd);
  return 0;
}
