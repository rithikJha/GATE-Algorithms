#include "DArray.h"
using namespace std;

int main()
{
    DArray<DArray<int>> m;
    DArray<int> a{1, 2};
    DArray<int> b{3, 4};
    DArray<int> c{5, 6};
    DArray<int> d{7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    //cout<<&a<<endl;
    m.push_back(a);
    m.push_back(b);
    m.push_back(c);
    m.push_back(d);
    m.push_back(a);
    m.push_back(b);
    m.push_back(c);
    m.push_back(d);

    m.print();

    m.pop_back();
    m.pop_back();
    m.pop_back();
    m.print();
    cout << "________11";
    m.~DArray();
    cout << "________11";
}