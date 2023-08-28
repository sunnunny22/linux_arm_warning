#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#define err_log(log)\
	  do{\
	  	perror(log);\
		exit(1);\
	  }while(0)  //出错处理的宏函数
typedef struct sockaddr SA;
//./server    192.168.1.104 8888

int main(int argc, const char *argv[])
{

	int sockfd;
	char buf[32]={0};
	struct sockaddr_in serveraddr;
	socklen_t len=sizeof(serveraddr);
	bzero(&serveraddr,len);
	if(argc<3)
	{
		fprintf(stderr,"USER:%s IP PORT",argv[0]);
		return -1;
	}

	if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)//创建流式套接字
	{
		err_log("fail to socket:");
	}
	//填充服务器的网络信息
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(atoi(argv[2]));
	serveraddr.sin_addr.s_addr=inet_addr(argv[1]);

	if(connect(sockfd,(SA*)&serveraddr,len)<0)//请求链接服务器
	{
		err_log("fail to connect:");
	}
	while(1)
	{
#if 0		
		fgets(buf,sizeof(buf),stdin);
		buf[strlen(buf)-1]='\0';///\n---》\0
		//send(sockfd,buf,sizeof(buf),0);
		write(sockfd,buf,sizeof(buf));
		bzero(buf,sizeof(buf));
		//recv(sockfd,buf,sizeof(buf),0);
#endif
		read(sockfd,buf,31);
		printf("%s\n",buf);
	}



	close(sockfd);//关闭套接字


	return 0;
}
