#include<bits/stdc++.h>
using namespace std;

int assembly(int a[][4], int t[][4], int e[], int x[]){
    // int l1[4], l2[4];
    // l1[0] = e[0] + a[0][0];
    // l2[0] = e[1] + a[1][0];

    int first, second;

    first = e[0] + a[0][0];
    second = e[1] + a[1][0];

    for (int i = 1; i < 4; i++)
    {
        // l1[i] = min(l1[i-1] + a[0][i], l2[i-1] + t[1][i] + a[0][i]);
        // l2[i] = min(l2[i-1] + a[1][i], l1[i-1] + t[0][i] + a[1][i]);

        int one = min(first + a[0][i], second + t[1][i] + a[0][i]);
        int two = min(second + a[1][i], first + t[0][i] + a[1][i]);

        first = one;
        second = two;
    }

    return min(first + x[0], second + x[1]);
    
}


int main(){
    
    int a[][4] = {{4,5,3,2}, {2,10,1,4}};
    int t[][4] = {{0,7,4,5}, {0,9,2,8}};

    int e[] = {10, 12};
    int x[] = {18, 7};

    cout<<assembly(a, t, e, x);
    return 0;
}