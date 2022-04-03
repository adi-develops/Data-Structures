#include<bits/stdc++.h>
using namespace std;

int maximumArr(int a[], int n){
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < a[i]){
            max = a[i];
        }
    }
    return max;
}

void countSort(int a[], int n){
    int max = maximumArr(a, n);

    int count[max+1];
    for (int i = 0; i < max+1; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        count[a[i]]++;
    }
    
    int j = 0;
    for (int i = 0; i < max+1; i++)
    {
        while(count[i]--){
         a[j]=i;
         j++;   
        }
    }
    
}

int main(){
    int arr[10] = {34,2,5,6,14,75,76,26,65,98};
    int n = 10;
    countSort(arr, n);
    for(int i=0; i<10; i++){
        cout<<arr[i]<<"\t";
    }

    return 0;
}