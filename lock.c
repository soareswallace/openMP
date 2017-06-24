#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(){
	int thread_id,a;
	omp_lock_t lck1, lck2;
	omp_init_lock(&lck1);
	omp_init_lock(&lck2);
	a=0;
	#pragma omp parallel num_threads(4) shared(a) private(thread_id) 
	{
		thread_id = omp_get_thread_num();
		omp_set_lock(&lck1);
		a++;
		printf("Thread %d na regiao critica 1, a = %d \n", thread_id,a);
		omp_unset_lock(&lck1);

		omp_set_lock(&lck2);
		a--;
		printf("thread %d na regiao critica 2, a = %d\n", thread_id, a);
		omp_unset_lock(&lck2);
	}
	omp_destroy_lock(&lck1);
	omp_destroy_lock(&lck2);
	return 0;
}