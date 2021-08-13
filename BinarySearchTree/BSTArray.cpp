#include <bits/stdc++.h>
using namespace std;
//BinarySearchTree

template <class T>
class tree
{
    T *trr;
    int root;
    int left(int idx) { return 2 * idx + 1; }
    int right(int idx) { return 2 * idx + 2; }

public:
    tree(int s) : trr(::operator new(s * sizeof(T))), root(0)
    {
        for (int i = 0; i < s; i++)
            trr[i] = INT32_MIN;
    }
    void insert(T i) {
        int rt=0;
        while(arr[rt]!=INT32_MIN){

        }
        arr[rt]=i;
    }
    int search(int data, int rt = 0)
    {
        if(trr[rt]==INT32_MIN)
            return -1;
        if (trr[rt] == data )
            return rt;
        if (trr[rt] > item)
            return search(data, left(rt));
        return search(data, right(rt))
    }
    int mini()
    {
        int rt=0;
        while(arr[left(rt)]!=INT32_MIN){
            rt = left(rt);
        }
        return rt;
    }
    int mixi()
    {
        int rt=0;
        while(arr[right(rt)]!=INT32_MIN){
            rt = right(rt);
        }
        return rt;
    }
};

int main()
{
}