#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int read_sysfs_float(const char *device, const char *filename, float *val)
{
	int ret = 0;
	int fd;
	char temp[128];
	FILE *f;

	memset(temp, '0', 128);
	sprintf(temp, "/sys/bus/iio/devices/%s/%s", device, filename);
	
	fd = open(temp,O_RDONLY);
	f = fdopen(fd,"r");
	fscanf(f,"%f\n",val);

	close(fd);
	return ret;
}

int read_sysfs_int(const char *device, const char *filename, int *val)
{
	int ret = 0;
	int fd;
	char temp[128];
	FILE *f;

	memset(temp, '0', 128);

	sprintf(temp, "/sys/bus/iio/devices/%s/%s", device, filename);
	
	fd = open(temp,O_RDONLY);
	f = fdopen(fd,"r");	
	fscanf(f,"%d\n",val);

	close(fd);
	return ret;
}

float gettemp()//获取温度 , 返回值是温度
{
	int temp_raw,temp_offset;
	float temp_scale;
	float tempvalue;
	read_sysfs_int("iio:device0", "in_temp_raw", &temp_raw);
	read_sysfs_int("iio:device0", "in_temp_offset", &temp_offset);
	read_sysfs_float("iio:device0", "in_temp_scale", &temp_scale);
	tempvalue = (temp_raw + temp_offset) * temp_scale / 1000;
//	printf("temperature = %.2f\n", tempvalue);
	return tempvalue;
	
}

float gethum()//获取湿度, 返回值就是湿度
{
	int hum_raw;
	int hum_offset;
	float hum_scale;
	float humvalue;
	read_sysfs_int("iio:device0", "in_humidityrelative_raw", &hum_raw);
	read_sysfs_int("iio:device0", "in_humidityrelative_offset", &hum_offset);
	read_sysfs_float("iio:device0", "in_humidityrelative_scale", &hum_scale);
	humvalue = (hum_raw + hum_offset) * hum_scale / 1000;
	//printf("humidity = %.2f%%\n", humvalue);
	return humvalue;

}

