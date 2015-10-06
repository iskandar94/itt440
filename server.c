#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<errno.h>
#include<string.h>

int main(int argc,char *argv[])

{
   unsigned int len;

   int s,cli;
   struct sockaddr_in server , client;

	if((s = socket(AF_INET , SOCK_STREAM, 0 ))==-1)
	{
	    perror("socket:");
	    

	}
	server.sin_family = AF_INET;
	server.sin_port=htons(1026);
	server.sin_addr.s_addr = INADDR_ANY;
	bzero(&server.sin_zero,8);
	
	len = sizeof(struct sockaddr_in);
	if((bind(s ,(struct sockaddr *)&server, len))== -1)
	{
	 perror("bind");
	 exit(-1);
	}
	
	if((listen(s,5)) == -1)
	{
	 perror("listen");
	 exit(-1);
	}
	while(1)
	{
	 if((cli = accept(s, (struct sockaddr *)&client , &len)) == -1)
	{
	 perror("accept");
	 exit(-1);
	}

	  
	}

	return 0;
 }

