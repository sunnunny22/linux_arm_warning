#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void ledfunc(int ledno, int on)//ledno 是led 的号 (1 2 3) ，   on 为1 灯亮， 为0 灯灭
{
	char cmd[100] = {0};
		sprintf(cmd,"echo %d > /sys/class/leds/led%d/brightness",on,ledno);
	system(cmd);
	return;
		
}
