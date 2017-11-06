#include <unistd.h>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void get(int filedesc, int* a, int* b){
	int sum = 0;

	char data[10];
	read(filedesc, data, 5);
	read(filedesc, data, 6);
	sum += atoi(data);
	//printf("%d\n", atoi(data));
	memset(data, 0, 10);
	read(filedesc, data, 4);
        sum += atoi(data);
	//printf("%d\n", atoi(data));
	memset(data, 0, 10);
	read(filedesc, data, 6);
        sum += atoi(data);
	*a = sum;
	//printf("%d\n", atoi(data));
	memset(data, 0, 10);
        read(filedesc, data, 8);
        sum += atoi(data);
	//
	memset(data, 0, 10);
        read(filedesc, data, 6);
        sum += atoi(data);
	//
	memset(data, 0, 10);
        read(filedesc, data, 1);
        sum += atoi(data);
	//
	memset(data, 0, 10);
        read(filedesc, data, 5);
        sum += atoi(data);
	*b = sum;
}


int main(){

	char data[100];

	int filedesc = open("/proc/stat", O_RDONLY);
	int use1, all1, use2, all2;
	get(filedesc, &use1, &all1);
	close(filedesc);
	sleep(3);
	filedesc = open("/proc/stat", O_RDONLY);
	get(filedesc, &use2, &all2);
	
	printf("CPU Usage is %.2f%%\n", (double)(use2 - use1) * 100/(all2 - all1) );
}
