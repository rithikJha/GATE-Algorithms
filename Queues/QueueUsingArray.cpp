#include <bits/stdc++.h>
using namespace std;

template <class T,size_t sz>
class Queue
{
    T a[sz];
    int size;
    int front;
    int rear;
    int incr(int x)
    {
        x = (x + 1) % size;
        return x;
    }
    int ModIncr(int &x)
    {
        x = (x + 1) % size;
        return x;
    }

public:
    Queue() : size(sz), front(-1), rear(-1) {}

    void enqueue(T s)
    {
        if (front == -1)
        {
            front++;
            rear++;
            a[rear] = s;
            return;
        }
        if (incr(rear) == front)
        {
            cout << "Queue Full !!" << endl;
            return;
        }

        a[ModIncr(rear)] = s;
    }
    T dequeue()
    {
        if (front == -1)
        {
            cout << "Queue Empty !!" << endl;
            return T();
        }
        T temp = a[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
            return temp;
        }
        ModIncr(front);
        return temp;
    }
    T frontEle()
    {
        if (front == -1)
        {
            cout << "Queue empty !!" << endl;
            return T();
        }
        return a[front];
    }
    T rearEle()
    {
        if (front == -1)
        {
            cout << "Queue empty !!" << endl;
            return T();
        }
        return a[rear];
    }
    T isEmpty()
    {
        return front == -1;
    }
};

int main()
{
    Queue<int,10> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << q.dequeue()
         << " dequeued from queue\n";
    cout << q.dequeue()
         << " dequeued from queue\n";
    cout << q.dequeue()
         << " dequeued from queue\n";
    cout << q.dequeue()
         << " dequeued from queue\n";
    cout << q.dequeue()
         << " dequeued from queue\n";

    cout << "Front item is "
         << q.frontEle() << endl;
    cout << "Rear item is "
         << q.rearEle() << endl;

    return 0;
}