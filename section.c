#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 500

int main()
{
	/* code */
	int i, j, k, thread_id, a[N];
	#pragma omp parallel num_threads(4)
		#pragma omp sections
		{
			#pragma omp section			
				for (i=0;i<N/2;i++){
					a[i] = 0;
				}
			#pragma omp section
				for (int j = N/2; j < N; j++){
						a[j] = 0;
						/* code */
					}
		}
	i = 0;
	while(i<N){
		printf("%d", a[i]);
		if((i+1)%25 == 0){
			printf("\n");
		}
		i++;
	}
	return 0;
}