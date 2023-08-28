#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>
#include <unistd.h>


void beepplay(int fd, int hz)//�Բ�ͬƵ����1��
{
	int ret;
		struct input_event event;
	struct timeval time;
	
//	if(hz == 0) hz = 1;
	event.type = EV_SND;
	event.code = SND_TONE;
	event.value = hz;
	time.tv_sec = 1;
	time.tv_usec = 0;
	event.time = time;
	ret = write(fd, &event, sizeof(struct input_event));
	perror("write");
	return;

}

