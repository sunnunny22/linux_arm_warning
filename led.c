#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void ledfunc(int ledno, int on)//ledno ��led �ĺ� (1 2 3) ��   on Ϊ1 ������ Ϊ0 ����
{
	char cmd[100] = {0};
		sprintf(cmd,"echo %d > /sys/class/leds/led%d/brightness",on,ledno);
	system(cmd);
	return;
		
}
