#include <iostream>
using namespace std;


class heap{
private:
    int *h;
    int heapsize;

    int leftChild(int index){
        //return index << 1;
        return 2 * index;
    }
    int rightChild(int index){
        //return (index << 1) | 1;
        return (2*index)+1;
    }
    int parent(int index){
        //return index >> 1;
        return index/2;
    }

    void swap(int i, int j){
        int temp = h[i];
        h[i] = h[j];
        h[j] = temp;
    }

    void heapify(int index){
        int l = leftChild(index);
        int r = rightChild(index);
        int max = index;
        if(l <= heapsize-1 && h[l] > h[index])
            max = l;
        if(r <= heapsize-1 && h[r] > h[max])
            max = r;
        if(max != index){
            swap(index, max); //the indexes remain unmodified, just the content is swapped
            heapify(max);
        }
    }

public:
    heap(int *array): h(array), heapsize(0){}

    void build_max_heap(int A[], int dim){
            for(int i=0; i<dim; i++){
                h[i] = A[i];
                this->heapsize ++;
            }
            dim--;
            for(int i=(dim)/2; i>=0; i--){
                heapify(i);
                this->printHeap();
            }
    }

    void printHeap(){
        cout << endl;
        for(int i=0; i<heapsize; i++)
            cout << h[i] << " ";
    }

};



int main(){

    int V[] = {3,7,9,2,5,12,11,15,10,8,4,6};
    int dim = sizeof(V)/sizeof(V[0]);
    int *A = new int[30];
    heap h1(A);
    h1.build_max_heap(V, dim);
    h1.printHeap();

}