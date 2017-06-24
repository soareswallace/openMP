#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(){
	int matriz = {{5, 0, 1, 1},{-2, 3, 4, 1}, {0, 2, -1, 1}, {1, 1, 1, 1}};
	int i, j, k, thread_id;
	#pragma omp parallel for private (j, k) num_threads(4)
	{//funfact: este pragma so funciona se as chaves estiverem assim
			
	}
}