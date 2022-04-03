#include <iostream>
using namespace std;

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int *A, int mid, int low, int high)
{
    
    int i, j, k, B[high-low+1];
    i = low;
    j = mid + 1;
    k = 0;

    while (i <= mid && j <= high)
    {
        if (A[i] <= A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low, j=0; i <= high; i++, j++)
    {
        A[i] = B[j];
    }
    
}

void mergeSort(int *A, int low, int high){
    int mid;
    if(low<high){
        mid = (low + high) /2;
        cout<<mid<<endl;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, mid, low, high);
    }
}
 
int main()
{
    // int A[] = {9, 14, 4, 8, 7, 5, 6};
    int A[] = {9, 1, 43, 14, 4};
    int n = 5;
    printArray(A, n);
    mergeSort(A, 0, 4);
    printArray(A, n);
    return 0;
}
