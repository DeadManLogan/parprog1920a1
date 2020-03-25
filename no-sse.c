#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void get_walltime(double *wct){
	struct timeval tp;
	gettimeofday(&tp, NULL);
	*wct = (double)(tp.tv_sec + tp.tv_usec/1000000.0);
}

int main(){

	float *a, *b;
    float k0 = 0.5, k1 = 0.5, k2 = 0.5, k3 = 0.5, k5 = 0.5, k6 = 0.5, k7 = 0.5, k8 = 0.5;
    float k4 = 5.0;
	double ts, te, mflops;
	int i, j;

//Desmeuseis
	a = (float*) malloc(N* M* sizeof(float));
    b = (float*) malloc(N* M* sizeof(float));

//Arxikopoiisi
	for(i=0; i < N *M; i++){
		a[i] = ((float)rand()/(float)(RAND_MAX));  //fill the array with random float numbers
        b[i] = 1;
        //printf("%f\n", array01[i]);
        //printf("%f\n", array02[i]);
	}

	get_walltime(&ts);
	printf("%f\n", ts);

//Fortio
	for(i = 1; i < N - 1; i++){
		for(j = 1; j < M - 1; j++){
			b[j] = (a[(i-1)+(j-1)] * k0) + (a[(i-1)+j] * k1) + (a[(i-1)+(j+1)] * k2) + (a[i+(j-1)] * k3) + (a[i+j] * k4) + (a[i+(j+1)] * k5) + (a[(i+1)+(j-1)] * k6) + (a[(i+1)+j] * k7) + (a[(i+1)+(j+1)] * k8);	
		}
	}

	get_walltime(&te);		//diafora xronou te-ts
	printf("%f\n", te);
	printf("%f\n", te-ts);

	mflops = (2.0*M*N)/((te-ts)*1e6);
  
  	printf("MFLOPS/sec = %f\n",mflops);
	
//Apodesmeusi
	free(a);
    free(b);
	return 0;
}



//gia na kano compile grafo :	gcc -Wall -O2 no-sse.c -o no-sse -DN=40000 -DM=40000
//gia na treksei grafo :	./no-sse



