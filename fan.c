#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void fanwork(int speed)//speed  ���ȵ�ת��  : 0 ---255           ����Խ��ת��Խ�� 0---ֹͣ
{
	char cmd[100] = {0};
	sprintf(cmd,"echo %d > /sys/class/hwmon/hwmon1/pwm1",speed);
	system(cmd);
}
