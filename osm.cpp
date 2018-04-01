#include <sys/time.h>
#include <cstdio>
#include <iostream>
#include "osm.h"
double osm_operation_time(unsigned int iterations=1000)
{
	int i = 0;
	struct timeval tim{};
	gettimeofday(&tim, nullptr);
	double t1=tim.tv_sec+(tim.tv_usec*1000.0);
	int k = 0;
	std::cout<< "started timer for operation" << std::endl;
	for (i=0;i<iterations/10;i++)
	{
		++k;
		++k;
		++k;
		++k;
		++k;
		++k;
		++k;
		++k;
		++k;
		++k;
	}
	gettimeofday(&tim, nullptr);
	double t2=tim.tv_sec+(tim.tv_usec*1000.0);
	double result = (t2 - t1)/(iterations*10);
	std::cout<< "ended timer" << std::endl;

	return result;
}

void empty_function()
{

}

double osm_function_time(unsigned int iterations)
{
	int i = 0;
	struct timeval tim{};
	gettimeofday(&tim, nullptr);
	double t1=tim.tv_sec+(tim.tv_usec*1000.0);
	int k = 0;
	std::cout<< "started timer for empty function call" << std::endl;
	for (i=0;i<iterations/10;i++)
	{
		empty_function();
	}
	gettimeofday(&tim, nullptr);
	double t2=tim.tv_sec+(tim.tv_usec*1000.0);
	double result = (t2 - t1)/(iterations*10);
	std::cout<< "ended timer" << std::endl;

	return result;
}

double osm_syscall_time(unsigned int iterations)
{
	int i = 0;
	struct timeval tim{};
	gettimeofday(&tim, nullptr);
	double t1=tim.tv_sec+(tim.tv_usec*1000.0);
	int k = 0;
	std::cout<< "started timer for sys call" << std::endl;
	for (i=0;i<iterations/10;i++)
	{
		OSM_NULLSYSCALL;
	}
	gettimeofday(&tim, nullptr);
	double t2=tim.tv_sec+(tim.tv_usec*1000.0);
	double result = (t2 - t1)/(iterations*10);
	std::cout<< "ended timer" << std::endl;

	return result;

}
