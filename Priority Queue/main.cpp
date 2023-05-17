#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


class PriorityQueue
{
	public:
		vector<int> p_queue;
		int heapSize = 0;
		
		PriorityQueue(int list[], int n){
			for(int i=0; i<n;i++){
				this->insert(list[i]);
			}			
		}
		
		PriorityQueue(){						
		}
		
		int extract_max(){
			if (this->heapSize < 1){
				return -1;
			}
			int max = this->p_queue[0];
			this->p_queue[0] = this->p_queue[this->heapSize - 1];
			this->heapSize--;
			this->max_heapify(0);			
			return max;
		}
		
		void insert(int key){
			this->heapSize++;
			this->p_queue.push_back(-1);
			this->increase_key(this->heapSize - 1, key);			
		}
		
		void increase_key(int i, int key){
			if (key < this->p_queue[i]){
				return ;
			}
			this->p_queue[i] = key;
			
			int aux;
			while(i>0 && this->p_queue[this->parent(i)] < this->p_queue[i]){
				aux = this->p_queue[this->parent(i)];
				this->p_queue[this->parent(i)] = this->p_queue[i];
				this->p_queue[i] = aux;
				i = this->parent(i);
			}
		}
		
		void max_heapify(int i){
			int l=left(i);
			int r=right(i);
			int maior;
			
			if (l <= heapSize && this->p_queue[l] > this->p_queue[i]){
				maior = l;
			}
			else{
				maior = i;
			}
			
			if (r <= heapSize && this->p_queue[r] > this->p_queue[maior]){
				maior = r;
			}
			
			if (maior!=i){
				int aux = this->p_queue[i];
				this->p_queue[i] = this->p_queue[maior];
				this->p_queue[maior] = aux;
				max_heapify(i);
			}
		}
		
		int left(int i){
			return 2*i+1;
		}
		
		int right(int i){
			return 2*i+2;
		}
		
		int parent(int i){
			return floor((i-1)/2);
		}
};


int main() {
	int arr[] = { 5,3,4,6,1,9,2 };
	int n = 7;
	PriorityQueue p_queue = PriorityQueue(arr, n);
	
	for (int x=0;x<7;x++)
		cout << p_queue.extract_max() << " ";
		
	return 0;
}
