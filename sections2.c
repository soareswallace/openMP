#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 1000

int main(){
	int matriz[N];
	int i, tid, valorInicial = 1, contaPar = 0;
	for (i=0;i<N;i++){
		matriz[i] = valorInicial;
		valorInicial+=3;
	}

	#pragma omp parallel private(i, tid) num_threads(3)
	{
		#pragma omp sections reduction(+: contaPar)
		{
			#pragma omp section
			for (i=0;i<N/2;i++){
				if (matriz[i]%2==0){
					contaPar++;
				}
			}
			#pragma omp section
			for (i=N/2;i<N;i++){
				if (matriz[i]%2==0){
					contaPar++;
				}
			}
		}		
	}
	printf("Quantidade de pares: %d\n", contaPar );
}