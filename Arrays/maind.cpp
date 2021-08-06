#include "DArray.h"
using namespace std;
#define array DArray<int>
array merge(array A, array B)
{

    int i = 0, j = 0, k = 0;
    int as = A.noOfitems(), bs = B.noOfitems();
    array C(as + bs);
    while (i < as and j < bs)
    {
        A[i] > B[j] ? C.push_back(B[j++]) : C.push_back(A[i++]);
    }
    while (i < as)
    {
        C.push_back(A[i++]);
    }
    while (j < bs)
    {
        C.push_back(B[j++]);
    }
    cout << "C:" << C;
    return C;
}
array MergeSort(array arr)
{
    if (arr.noOfitems() == 1)
    {
        return arr;
    }
    int s = arr.noOfitems() / 2;

    cout << array(arr.begin(), arr.begin() + s) << endl;
    cout << array(arr.begin() + s, arr.begin() + arr.noOfitems()) << endl
         << endl;
    array left = MergeSort(array(arr.begin(), arr.begin() + s));
    array right = MergeSort(array(arr.begin() + s, arr.begin() + arr.noOfitems()));
    arr = merge(left, right);
    return arr;
}
array m(array arr)
{
    cout << arr;
    return arr;
}
int main()
{
    DArray<DArray<int>> m;
    DArray<int> a{1, 2};
    DArray<int> b{3, 4};
    DArray<int> c{5, 6};
    DArray<int> d{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    //DArray<int> l = m(d);
    //l.print();
    //cout << l;

    // DArray<int> f(d.begin(), d.begin() + 5);
    // f.print();
    // DArray<int> l = DArray<int>(d.begin(), d.begin() + 7);
    // l.print();
    // d.print();
    // //cout<<&a<<endl;
    m.push_back(a);
    m.push_back(b);
    m.push_back(c);
    m.push_back(d);
    m.push_back(a);
    m.push_back(b);
    m.push_back(c);
    m.push_back(d);
    m.pop_back();
    m.pop_back();
    m.print();

    // m.~DArray();
    // cout << "-----------------\n";
    // d.print();
    //d = MergeSort(d);
    //d.print();
    // d[3] = d[4];
    // d.print();
}