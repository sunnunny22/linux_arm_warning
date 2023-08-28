#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>
#include <unistd.h>
#include "pro.h"
int main()
{
	int i;
	int beepfd;
	int motorfd;
	float tvalue,hvalue;
	int dvalue;
	float ivalue;
	beepfd = open("/dev/input/event0",O_WRONLY);
	motorfd = open("/dev/input/event1",O_WRONLY);	
	
	for(i=1; i<4; i++)
	{
		ledfunc(i,1);
		sleep(1);
		ledfunc(i,0);
		sleep(1);
	}

	
	for(i = 0; i < 4; i++)
	{
		beepplay(beepfd,1000+i*200);
		sleep(1);
	}
		beepplay(beepfd,0);

	
	for(i = 0; i < 3; i++)
	{
		fanwork(i*50);
		sleep(1);
	}
		fanwork(0);
	
	motoron(motorfd, 3000);
	
	for(i = 0; i < 2; i++)
	{
		tvalue = gettemp();
		hvalue = gethum();
		printf("temperature = %.2f\n", tvalue);
		printf("humdata  = %.2f\n", hvalue);
	
		sleep(3);	
	}
	
	for(i = 0; i < 10; i++)
	{
		dvalue = getdistance();
		ivalue = getillum();
		printf("distance  = %d\n", dvalue);
		printf("illumdata   = %.2f\n", ivalue);
	
		sleep(1);
	}

	close(beepfd);
	close(motorfd);
	
}