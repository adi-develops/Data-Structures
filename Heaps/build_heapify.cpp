#include<iostream>
using namespace std;

void swap(int *e, int *f)
{
    int g = *e;
    *e = *f;
    *f = g;
}

void heapify(int a[], int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<n && a[left]>a[largest])
        largest = left;
    if(right<n && a[right]>a[largest])
        largest = right;
    if(largest != i){
        swap(&a[largest], &a[i]);

        heapify(a, n, largest);
    }
}

void build_heapify(int a[], int n){
    for(int i = (n-1)/2; i>=0; i--)
        heapify(a, n, i);
}

void heapsort(int a[], int n){
    build_heapify(a, n);
    
    for(int i = n-1; i>0; i--){
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

int main(){
    int arr[]={32,4,42,46,543,134,26,7};
    int n = 8;
    build_heapify(arr, n);
    // heapsort(arr, n);
    // heapify(arr, n, 0);
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\t";
    return 0;
}