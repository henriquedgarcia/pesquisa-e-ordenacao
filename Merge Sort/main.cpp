#include <iostream> 

#include <cmath> 

  

using namespace std; 

  

void merge(int *lista, int p, int q, int r) 
{ 
	int n1 = q - p + 1; 
	int n2 = r - q; 
	
	int *L = new int [sizeof(int)*(n1+1)]; 
	int *R = new int [sizeof(int)*(n2+1)]; 	 
	
	for(int i=0; i< n1; i++)	 
	{ 
		L[i] = lista[p+i]; 
	} 	
	
	for(int j=0; j< n2; j++)	 
	{ 
		R[j] = lista[q+1+j]; 
	} 
	
	L[n1] = 9999; 
	R[n2] = 9999; 
	
	int i = 0; 
	int j = 0; 
	
	for(int k=p; k<=r; k++) 
	{ 
		if(L[i]<R[j]) 
		{ 		
			lista[k] = L[i]; 
			i++; 
		} 
		else 
		{ 		
			lista[k] = R[j]; 		
			j++; 		
		} 
	} 
} 

void mergeSort(int *lista, int p, int r) 
{ 
	if (p < r) 
	{ 
		int q = floor((p+r)/2); 
		mergeSort(lista, p, q); 
		mergeSort(lista, q+1, r); 
		merge(lista, p, q, r); 
	} 
} 

int main(int argc, char** argv) 
{	
	int listinha[] = {15,25,1,20}; 
	int size = sizeof(listinha) / sizeof(int); 
	mergeSort(listinha, 0, size-1); 
	size = sizeof(listinha) / sizeof(int);
	for(int i=0; i< size; i++) 	
	{ 	
		std::cout << listinha[i]; 
		if(i!=size-1) std::cout << ", "; 	
	} 	

	return 0; 
} 

