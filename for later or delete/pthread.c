#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//the sum created by the background thread
long long sum = 0;


//thread function to generate sum of 0 to N
void *sum_runner(void *arg)
{
	long long *limit_ptr = (long long*) arg;
	long long limit = *limit_ptr;

	for(long long i =0; i <= limit; i++)
	{
		sum += i;
	}
	//TODO what to do with the answer
	// /sum is a global variable, so other threads can access
	pthread_exit(0);
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Usage: %s <num>\n", argv[0]);
		exit(-1);
	}
	long long limit = atoll(argv[1]);

	//thread ID;
	pthread_t tid;

	//create attributes
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	pthread_create(&tid, &attr, sum_runner, &limit);

	// wait until thread is done its work
	pthread_join(tid, NULL);
	printf("sum is %lld\n", sum);
}