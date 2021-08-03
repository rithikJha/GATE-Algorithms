#include<bits/stdc++.h>
using namespace std;

int fibb(int a){
    //Base-Case - where the program actually stops
    if(a<2)
        return 1;
    else
        return fibb(a-1)+fibb(a-2);
}
int main(){
    cout<<fibb(5);
}

// T(n) = T(n-1)+T(n-2)+c - constant operation of adding 
//  T(n) <= c + 2c + 4c + 16c + .... + 2^(n-1)*c
//  T(n) <= c{1+2+4+...+2^(n-1)}
//  T(n) <= c{sum of G.P.}
//  T(n) <= c{1.(2^(n-1)-1)/(2-1)}
//  T(n) = O(2^n)
