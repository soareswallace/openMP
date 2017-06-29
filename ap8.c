#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(){
	int matriz = {{5, 0, 1, 1},{-2, 3, 4, 1}, {0, 2, -1, 1}, {1, 1, 1, 1}};
	//iremos travar o termo a(1,1) da matriz para andar a linha
	int i1, j1, i2, j2, i3, j3, i4, j4, k, thread_id;
	#pragma omp parallel num_threads(4)
	{//funfact: este pragma so funciona se as chaves estiverem assim
		#pragma omp sections
		{
			#pragma omp section private(i1, j1)

		}
	}
}