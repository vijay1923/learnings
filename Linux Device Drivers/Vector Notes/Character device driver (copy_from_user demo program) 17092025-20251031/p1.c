#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

main(){

	int fd;
	fd=open("/dev/myfile",O_RDWR);
	if(fd<0){
		perror("open:");
		return fd;	
	}

	write(fd, "HELLO", 6);
	close(fd);
}
