// Simple implementation
#include<bits/stdc++.h>
using namespace std;
void insertionSort(int a[],int n){
    for(int i=1;i<n;i++){
        int j = i-1;
        int val = a[i];
        while(j>=0 && a[j]>val){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = val;
    }
}

int main(){
    int a[] = {32,1243,35,32,52,434,34,2,35,346,24,34,23,423,525};
    int n = sizeof(a)/sizeof(a[0]);
    insertionSort(a,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    
}