#include <iostream>
using namespace std;

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << "\t";
    }
    cout << "\n";
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quicksort(int A[], int low, int high)
{
    // cout<<low<<"\t"<<high<<endl;
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        
        quicksort(A, low, partitionIndex - 1);
        quicksort(A, partitionIndex + 1, high);
    }
}

int main()
{
    int arr[] = {9,4};
    printArray(arr, 2);
    quicksort(arr, 0, 1);
    printArray(arr, 2);
    return 0;
}