#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
int read_sysfs_int(const char *device, const char *filename, int *val);
int read_sysfs_float(const char *device, const char *filename, float *val);

int getdistance()//获取接近值
{
		float disvalue;
		read_sysfs_float("iio:device1", "/in_proximity_raw", &disvalue);
		return disvalue;
	
}

float getillum()//获取光照强度,返回值就是光强
{
		int illumvalue;
		read_sysfs_int("iio:device1", "in_illuminance_input", &illumvalue);
		return illumvalue;
	
}
