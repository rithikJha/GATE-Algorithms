#include <bits/stdc++.h>
using namespace std;

// Tail-call optimisation - Having to do nothing after recursive step
int factorial(int a, int fact)
{
    //Base-Case - where the program actually stops
    if (a < 2)
        return fact;
    else
        return factorial(a - 1, fact * a);
}

// Interpretation
int factorialInterpret(int a, int fact)
{
//Base-Case - where the program actually stops
start:
    if (a < 2)
        return fact;

    //Tail recursion - update the parameter and goto start
    fact = fact * a;
    a = a - 1;
    goto start;
}

int main()
{
    cout << factorial(10, 1);
}