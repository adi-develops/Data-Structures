#include <bits/stdc++.h>
using namespace std;

void swap(int *e, int *f)
{
    int g = *e;
    *e = *f;
    *f = g;
}

// Iterative function
void insert_heap(int a[], int &n, int x)
{
    // n+=1;
    a[n] = x;
    int i = n;
    n++;
    while (i > 0)
    {
        int parent = floor((i - 1) / 2);
        if (a[parent] < a[i])
        {
            swap(&a[parent], &a[i]);
            i = parent;
        }
        else
            return;
    }
}

// Recursive function
void ins_heapify(int a[], int i)
{
    if (i > 0)
    {
        int parent = floor((i - 1) / 2);
        if (a[parent] < a[i])
        {
            swap(&a[parent], &a[i]);
            ins_heapify(a, parent);
        }
    }
}

void insert_heap_recur(int a[], int &n, int x)
{
    a[n] = x;
    int i = n;
    n += 1;
    ins_heapify(a, i);
}

void delete_heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;
    if (largest != i)
    {
        swap(&a[largest], &a[i]);

        delete_heapify(a, n, largest);
    }
}

void delete_heap(int a[], int &n)
{
    if (n == 0)
        return;
    a[0] = a[n - 1];
    n--;
    delete_heapify(a, n, 0);
}

int main()
{
    int arr[50];
    int n = 0;
    for (int i = 0; i < 6; i++)
    {
        int choice;
        cout << "HEAP Menu" << endl
             << "Press 1 to insert" << endl
             << "Press 2 to delete" << endl;
        cin >> choice;
        if (choice == 1)
        {
            int item;
            cout << "Enter item : " << endl;
            cin >> item;
            insert_heap_recur(arr, n, item);
        }
        else if (choice == 2)
        {
            delete_heap(arr, n);
        }
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\t";

    return 0;
}