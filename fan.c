#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void fanwork(int speed)//speed  风扇的转速  : 0 ---255           数字越大，转速越快 0---停止
{
	char cmd[100] = {0};
	sprintf(cmd,"echo %d > /sys/class/hwmon/hwmon1/pwm1",speed);
	system(cmd);
}
