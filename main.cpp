#include <iostream>
#include <sys/time.h>
#include "osm.h"

int main(unsigned int iterations)
{
	printf("%.6lf nano-seconds elapsed\n", osm_operation_time(iterations));
	printf("%.6lf nano-seconds elapsed\n", osm_function_time(iterations));
	printf("%.6lf nano-seconds elapsed\n", osm_syscall_time(iterations));
	//Test that git yo
	return 0;
}