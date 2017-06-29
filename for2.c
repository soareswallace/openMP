#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	int A[2][2] = {{1,2},{3,4}};
	int B[2][2] = {{5,6},{7,8}};
	int C[2][2];	
	int i, j, tid;

	#pragma omp parallel private(j, tid) num_threads(2)
	{
		#pragma omp for
		for (i=0;i<2;i++){
			for(j=0;j<2;j++){
				tid = omp_get_thread_num();
				C[i][j] = A[i][j] + B[i][j];
				printf("Thread %d Calculou: C[%d][%d] = %d\n", tid, i, j, C[i][j]);
			}
		}
	} 	
}