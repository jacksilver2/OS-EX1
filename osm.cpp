#include "osm.h"
#include <sys/time.h>
#include <cmath>
#include <iostream>
#define DEFAULT_ITERATIONS 1000
#define ITERATIONS_IN_MACRO_ITER 10
#define NSEC_IN_USEC 1000
#define USEC_IN_SEC 1000000
#define OPERATION_ACT 0
#define FUNCTION_ACT 1
#define SYSCALL_ACT 2


void empty_func()
{
	return;
}
/* Time measurement function for a simple arithmetic operation.
   returns time in nano-seconds upon success,
   and -1 upon failure.
*/
double osm_action_time(unsigned int iterations, int action)
{
	struct timeval initial_tv;
	struct timeval final_tv;
	struct timezone tz;
	int x, y, z;
	unsigned int macro_iterations;
	x=y=0;
	z=1;
	gettimeofday(&initial_tv, &tz);
	if (iterations == 0)
	{
		iterations = DEFAULT_ITERATIONS;
	}
	macro_iterations = std::ceil(double(iterations)/ITERATIONS_IN_MACRO_ITER);
	if (action == OPERATION_ACT)
	{
		for (int i=0;i<macro_iterations;i++)
		{
			x=y+z;
			x=y+z;
			x=y+z;
			x=y+z;
			x=y+z;
			x=y+z;
			x=y+z;
			x=y+z;
			x=y+z;
			x=y+z;
		}
	}
	if (action == FUNCTION_ACT)
	{
		for (int i=0;i<macro_iterations;i++)
		{
			empty_func();
			empty_func();
			empty_func();
			empty_func();
			empty_func();
			empty_func();
			empty_func();
			empty_func();
			empty_func();
			empty_func();
		}
	}
	if (action == SYSCALL_ACT)
	{

		for (int i=0;i<macro_iterations;i++)
		{
			OSM_NULLSYSCALL;
			OSM_NULLSYSCALL;
			OSM_NULLSYSCALL;
			OSM_NULLSYSCALL;
			OSM_NULLSYSCALL;
			OSM_NULLSYSCALL;
			OSM_NULLSYSCALL;
			OSM_NULLSYSCALL;
			OSM_NULLSYSCALL;
			OSM_NULLSYSCALL;
		}
	}
	gettimeofday(&final_tv, &tz);
//	std::cout << initial_tv.tv_sec<<"  " << initial_tv.tv_usec << "\n" << final_tv.tv_sec << "  " << final_tv.tv_usec << std::endl;
	return NSEC_IN_USEC*(((final_tv.tv_sec-initial_tv.tv_sec) * USEC_IN_SEC +
						  final_tv.tv_usec-initial_tv.tv_usec)/
						 (double(macro_iterations)*ITERATIONS_IN_MACRO_ITER));
}

double osm_operation_time(unsigned int iterations)
{
	return osm_action_time(iterations, OPERATION_ACT);
}

double osm_function_time(unsigned int iterations)
{
	return osm_action_time(iterations, FUNCTION_ACT);
}

double osm_syscall_time(unsigned int iterations)
{
	return osm_action_time(iterations, SYSCALL_ACT);
}