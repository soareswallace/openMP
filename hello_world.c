#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main(){
	int nthreads, tid;

	#pragma omp parallel num_threads(4) private (nthreads, tid)
	{
		tid = omp_get_thread_num();
		printf("Hello World da Thread = %d\n", tid);
		if (tid == 0){
			nthreads = omp_get_thread_num();
			printf("Quantidade de threads = %d\n", nthreads );
		}
	}
}