#include <iostream>
#include <typeinfo>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void somaBinario(int numero1[], int numero2[], int n, int resultado[]){

	int r = 0;
	for (int k=n-1; k>=0; k--){
		resultado[k+1] = numero1[k] + numero2[k] + r;
		r=0;
		if (resultado[k+1] > 2){
			resultado[k+1] = 1;
			r = 1;
		}
		else if (resultado[k+1] > 1){
			resultado[k+1] = 0;
			r = 1;
		}
	}	
	resultado[0] = r;
}

int main(int argc, char** argv) {
	int numero1[] = {1,0,1,0,1,1,0,1,0};
	int numero2[] = {1,1,1,1,1,1,0,1,1};
	int n = 9;
	int resultado[n+1];
	//             1,1,0,1,0,1,0,1,0,1
	
	somaBinario(numero1, numero2, n, resultado);
	
	for(int i=0; i <= n; i++){
		std::cout << *(resultado + i) << ", ";
	}
	return 0;
}

