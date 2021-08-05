#include <bits/stdc++.h>
using namespace std;

// selection enum
enum selection
{
    inclusive,
    exclusive
};

// Generic Node structure
template <class dtype>
struct node
{
    dtype data;
    node *next;
};

// Generic LinkedList class on the node structure
template <class dtype>
class LinkedList
{
    node<dtype> *head; // a pointer to the start of linkedlist
    node<dtype> *tail;
    size_t s;
    //to get an element before given position
    node<dtype> *before(int pos)
    {
        node<dtype> *p = head;
        if (pos == 0)
            return head;
        while (pos != 1)
        {
            p = p->next;
            pos--;
        }
        return p;
    }

public:
    //initializer_list constructor
    LinkedList<dtype>(initializer_list<dtype> l) : head(nullptr), tail(nullptr), s(0)
    {
        for (auto i = l.end() - 1; i != l.begin() - 1; i--)
        {
            node<dtype> *temp = new node<dtype>();
            temp->data = (*i);
            temp->next = nullptr;
            //1st node
            if (head == nullptr)
            {
                head = temp;
                tail = temp;
            }
            //other node
            else
            {
                temp->next = head;
                head = temp;
            }
            this->s++;
        }
    }
    void printList()
    {
        if (head == nullptr)
            cout << "List is empty !";
        else
        {
            node<dtype> *p = head;
            cout << "LIST : ";
            while (p != nullptr)
            {
                cout << p->data << " ";
                p = p->next;
            }
        }
        cout << "\nSize :" << s << endl
             << endl;
    }
    size_t size()
    {
        return s;
    }

    void insertAtPos(dtype data, int pos)
    {
        node<dtype> *temp = new node<dtype>();
        temp->data = data;
        if (pos > (int)s)
        {
            cout << "Invalid Position !";
            return;
        }
        s++;
        if (pos == 0)
        {
            temp->next = head->next;
            head = temp;
            return;
        }
        if (pos == s || pos == -1)
        {
            temp->next = nullptr;
            tail->next = temp;
            tail = temp;
            return;
        }
        node<dtype> *b = before(pos);
        temp->next = b->next;
        b->next = temp;
    }
    void deleteAtPos(int pos)
    {
        node<dtype> *temp;
        if (pos > (int)s)
        {
            cout << "Invalid Position !8";
            return;
        }
        s--;
        if (pos == 0)
        {
            temp = head;
            head = head->next;
            delete temp;
            return;
        }
        if (pos == s || pos == -1)
        {
            temp = tail;
            node<dtype> *b = before(s);
            tail = b;
            tail->next = nullptr;
            delete temp;
            return;
        }

        node<dtype> *b = before(pos);
        temp = b->next;
        b->next = temp->next;
        delete temp;
    }
    void slice(int posA, int posB, selection type)
    {
        if (type == exclusive)
        {
            posA += 1;
            posB -= 1;
        }
        if (posA > (int)s || posB > (int)s || posA > posB)
        {
            cout << "Invalid Position !";
            return;
        }
        if (posA == posB)
        {
            deleteAtPos(posA);
            return;
        }

        node<dtype> *l = before(posA);
        node<dtype> *r = before(posB + 1);
        node<dtype> *temp;
        if (l == head && r == tail)
        {
            while (l != r)
            {
                temp = l;
                l = l->next;
                delete temp;
            }
            delete l;
            head = nullptr;
            tail = nullptr;
            s = 0;
            return;
        }
        node<dtype> *i = l->next;
        l->next = r->next;
        while (i != r)
        {
            temp = i;
            i = i->next;
            delete temp;
            s--;
        }
        delete r;
        s--;
    }
    node<dtype> *find(dtype data)
    {
        node<dtype> *p = head;
        while (p != nullptr && p->data != data)
        {
            p = p->next;
        }
        return p;
    }
};