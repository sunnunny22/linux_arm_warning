#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <linux/input.h>
#include <sys/ioctl.h>

void motoron(int fd, int ms)//ms: 振子震动的时间,以毫秒为单位
{
	struct ff_effect effect;
	
	effect.type = FF_RUMBLE,
	effect.id = -1,
	effect.u.rumble.strong_magnitude = 0xFFFF; //调节振动强度
	effect.u.rumble.weak_magnitude = 0;
	effect.replay.length = ms; //调节振动时长 ms
	effect.replay.delay = 0;

	if (ioctl(fd, EVIOCSFF, &effect) < 0) {
		printf("Error creating new effect: %s\n", strerror(errno));
		return ;
	}

	printf("New effect ID: %d\n", effect.id);

	struct input_event play = {
		.type = EV_FF,
		.code = effect.id,
		.value = 1
	};
	
	if(ms == 0)
		{
			play.value = 0;
		}

	if (write(fd, (const void*) &play, sizeof(play)) < 0) {
		printf("Error writing effect to file: %s\n", strerror(errno));
		return ;
	}

	printf("Wrote effect\n");
	if(ms == 0)
		{
		}
	else
	{
		sleep(ms/1000 + 1);
	}
}
	
