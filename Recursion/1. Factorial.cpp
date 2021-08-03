#include <bits/stdc++.h>
using namespace std;
int factorial(unsigned int a)
{
    //Base-Case - where the program actually stops
    if (a < 2)
        return 1;
    else
        return a * factorial(a - 1);
}

int main()
{
    cout << factorial(4);
}