#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<sys/ioctl.h>
#define WR_VAL _IOW('a', 'a', int*)
//#define WR_VAL2 _IOW('b', 'a', int*)
main(){
	int fd;
	int num=12;
	fd=open("/dev/myfile",O_RDWR);
	if(fd<0){
		perror("open:");
		return fd;
	}

	ioctl(fd, WR_VAL, (int*)&num);
	//ioctl(fd, WR_VAL2, (int*)&num);
	close(fd);

}
