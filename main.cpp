#include <iostream>
#include <sys/time.h>
#include "osm.h"


int main(unsigned int iterations)
{
//	printf("%.6lf nano-seconds elapsed\n", osm_operation_time(iterations));
//	printf("%.6lf nano-seconds elapsed\n", osm_function_time(iterations));
//	printf("%.6lf nano-seconds elapsed\n", osm_syscall_time(iterations));
	//Test that git yo
	//test it again yo!
	printf("%.6lf nano-seconds elapsed\n", osm_action_time(1000000000, 0));
	printf("%.6lf nano-seconds elapsed\n", osm_action_time(1000000000,1));
	printf("%.6lf nano-seconds elapsed\n", osm_action_time(1000,2));

	return 0;
}
