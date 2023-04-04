#include <iostream>
using namespace std;
/*
Considere a ordenação de n números armazenados no arranjo A. Primeiramente o 
algoritmo localiza o menor elemento de A e troca esse elemento com o elemento 
contido em A[1] (Lembre-se que no livro os vetores começam com 1). Em seguida, 
determine o segundo menor elemento de A e troque-o com A[2]. Continue dessa 
maneira para os primeiros n - 1 elementos de A.
*/

void selection_sort(int* lista, int n)
{
	int aux;
		
	for (int i=0;i<n-1;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			if (lista[i] > lista[j])
			{
				aux = lista[j];
				lista[j] = lista[i];
				lista[i] = aux;
			}			
		}
	}
}

int main(int argc, char** argv) {
	int lista[] = {5,4,8,3,1,6,2,8,9,7};
	int size = sizeof(lista) / sizeof(int);
	
	selection_sort(lista, size);
	
	for (int i=0;i<size;i++)
	{
		cout << lista[i]<< ", ";
	}
	return 0;
}



