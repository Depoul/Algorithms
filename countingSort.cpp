#include <iostream>
using namespace std;
int* countingSort(int[], int);
int max(int [], int);
int min(int [], int);
void printArray(const int [], const int);

void printArray(const int A[], const int n){
    for(int i=0; i<n; i++)
        cout << A[i] << " ";
    cout << endl;
}

int max(int A[], int n){
    int max = A[0];
    for(int i=1; i<n; i++){
        if(A[i] > max)
            max = A[i];
    }
    return max;
}

int min(int A[], int n){
    int min = A[0];
    for(int i=1; i<n; i++){
        if(A[i]<min)
            min = A[i];
    }
    return min;
}


int* countingSort(int A[], int n){
    int h = min(A, n); //Minimum element of the A array
    int k = max(A,n); //Maximum elemento of the A array
    int d = k-h+1; //dimension of ausiliary "C" array.
    int* C = new int[d];
    int* B = new int[n];
    for(int i=0; i<d; i++)
        C[i] = 0; //filling C Array with 0s
    for(int i=0; i<n; i++)
        C[A[i]-h] = C[ A[i]-h ] +1; //Counting of the A[i] element appereances.
    for(int i = 1; i<d; i++)
        C[i] = C[i] + C[i-1]; //Sum of the adjacent elements of the ausiliary C array. 

    //Now the C[i] element represents the number of elements that are <= to the correspondent A[i] element (represented by the C index);
    
    for(int i = n-1; i>=0; i--){
        B[ C[ A[i]-h ] -1 ] = A[i];
        C[ A[i]-h ] = C[ A[i]-h ] -1;
    }

    return B;
}


int main(){

    int A[] = {4, 6, 2, 4, 5, 4, 3, 2, 3, 7};  //Array to order via countingSort
    int dim = sizeof(A) / sizeof(A[0]);
    cout << "Array diension:" << dim << endl;
    cout << "A: ";
    printArray(A,dim);
    cout << "MAX: " << max(A,dim);
    cout << endl << "MIN: " << min(A,dim) << endl;
    int *b = countingSort(A, dim);
    printArray(b, dim);
}