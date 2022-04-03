#include<bits/stdc++.h>
using namespace std;

void partition(int a[], int i, int j){

    while(i<=j){
        if(a[i]<0 && a[j]<0)
            i++;
        else if(a[i]>0 && a[j]<0){
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        else if(a[i]>0 && a[j]>0)
            j--;
        else{
            i++;
            j--;
        }
    }
}

int main(){
    int arr[]={4, -2, -63, -123, 43, -345};
    partition(arr, 0, 5);
    for(int i=0; i<6; i++){
        cout<<arr[i]<<"\t";
    }
    return 0;
}