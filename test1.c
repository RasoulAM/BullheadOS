#include<sys/time.h>
#include<stdio.h>

int main(){

	struct timeval tv;
	int a = gettimeofday(&tv, NULL);
	printf("%d",(int)(tv.tv_sec));


}
