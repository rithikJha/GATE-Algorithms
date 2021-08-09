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
class Queue
{
    node<T> *front;
    node<T> *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}
    void enqueue(T s)
    {
        node<T> *temp = new node<T>();
        temp->data = s;
        if (rear == nullptr)
        {
            temp->next = nullptr;
            front = temp;
            rear = temp;
            return;
        }
        temp->next = nullptr;
        rear->next = temp;
        rear = temp;
        cout << "ENQ: " << rear->data << endl;
    }
    T dequeue()
    {
        if (front == nullptr)
        {
            cout << "Stack Empty" << endl;
            return T();
        }
        node<T> *item = front;
        if (front == rear)
            front = rear = nullptr;
        else
            front = front->next;
        T temp = item->data;
        item->~node();
        delete item;
        cout << "DQD: " << temp << endl;
        return temp;
    }
    T frontEle()
    {
        if (front == nullptr)
        {
            cout << "Queue empty !!" << endl;
            return T();
        }
        return front->data;
    }
    T rearEle()
    {
        if (rear == nullptr)
        {
            cout << "Queue empty !!" << endl;
            return T();
        }
        return rear->data;
    }
    T isEmpty()
    {
        return front == nullptr;
    }
};

int main()
{
    Queue<int> q;

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