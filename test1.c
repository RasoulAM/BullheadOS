#include <sys/time.h>
#include <time.h>
#include <stdio.h>

int main(void)
{
    
	struct timeval tv; 
	struct tm *info;
	
	gettimeofday(&tv, NULL);	
	info = localtime(&tv.tv_sec);	
	printf("%s",asctime(info));

    return 0;
}

