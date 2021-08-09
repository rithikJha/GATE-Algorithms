#include <bits/stdc++.h>
using namespace std;
template <class T>
struct node
{
    T data;
    node<T> *next;
    ~node()
    {
        data.~T();
    }
};
template <class T>
class Stack
{
    node<T> *topE;

public:
    Stack() : topE(nullptr) {}
    void push(T s)
    {
        node<T> *temp = new node<T>();
        temp->data = s;
        if (topE == nullptr)
        {
            temp->next = nullptr;
            topE = temp;
            return;
        }
        temp->next = topE;
        topE = temp;
        cout << "P: " << topE->data << endl;
    }
    T pop()
    {
        if (topE == nullptr)
        {
            cout << "Stack Empty" << endl;
            return T();
        }
        node<T> *item = topE;
        topE = topE->next;
        T temp = item->data;
        item->~node();
        delete item;
        cout << "POP: " << temp << endl;
        return temp;
    }
    T top()
    {
        if (topE == nullptr)
        {
            cout << "Nothing on top ! EMPTY" << endl;
            return T();
        }
        return topE->data;
    }
    bool isEmpty()
    {
        return topE == nullptr;
    }
};

int main()
{
    Stack<int> s;
    s.push(1);
    s.push(3);
    s.push(1);
    s.push(3);
    s.push(1);
    s.push(3);
    s.push(1);
    s.push(3);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout << s.top() << endl;
}