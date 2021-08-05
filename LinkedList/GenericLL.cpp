#include <bits/stdc++.h>
using namespace std;

// selection enum
enum selection
{
    inclusive,
    exclusive
};

enum position
{
    onMe,
    beforeMe
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
    node<dtype> *reverseIt(node<dtype> *l, node<dtype> *r)
    {
        if (l == r)
        {
            head = tail = l;
            l->next = nullptr;
            return l;
        }

        node<dtype> *tempH = reverseIt(l->next, r);
        tail->next = l;
        tail = l;
        l->next = nullptr;
    }

    void insertAtPos(dtype data, int pos)
    {
        node<dtype> *temp = new node<dtype>();
        temp->data = data;
        //Invalid position
        if (pos > (int)s)
        {
            cout << "Invalid Position !";
            return;
        }

        s++;
        //first element
        if (head == nullptr)
        {
            temp->next = nullptr;
            head = temp;
            tail = temp;
            return;
        }

        if (pos == 0)
        {
            temp->next = head;
            head = temp;
            return;
        }

        //last position
        if (pos == (int)s || pos == -1)
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
    void deleteAddr(node<dtype> *addr, position p)
    {
        node<dtype> *temp;
        if (addr == head && p == onMe)
        {
            temp = head;
            head = head->next;
            delete temp;
            s--;
            if (head == nullptr)
                tail = nullptr;
            return;
        }
        if (addr == tail && p == onMe)
        {
            while (temp->next->next != nullptr)
                temp = temp->next;
            temp->next == nullptr;
            tail = temp;
            delete addr;
            s--;
            return;
        }

        if (p == beforeMe)
        {
            if (addr == tail)
                return;
            if (addr->next == tail)
                tail = addr;

            temp = addr->next;
            addr->next = temp->next;
            delete temp;
            s--;
            return;
        }

        temp = head;

        while (temp->next != addr && temp != nullptr)
            temp = temp->next;

        if (temp == nullptr)
            return;

        if (addr == tail)
            tail = temp;

        temp->next = addr->next;
        delete addr;
        s--;
        return;
    }

    void deleteAtPos(int pos)
    {
        if (pos > (int)s)
        {
            cout << "Invalid Position !8";
            return;
        }
        if (pos == 0)
        {
            deleteAddr(head, onMe);
            return;
        }
        if (pos == (int)s || pos == -1)
        {
            deleteAddr(tail, onMe);
            return;
        }
        node<dtype> *b = before(pos);
        deleteAddr(b, beforeMe);
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

public:
    LinkedList<dtype>() : head(nullptr), tail(nullptr), s(0)
    {
    }
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











    struct Iterator
    {
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = node<dtype>;
        using pointer = node<dtype>*;
        using reference = node<dtype>&;

        Iterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() const { return *m_ptr; }
        pointer operator->() { return m_ptr; }
        Iterator &operator++()
        {
            m_ptr=m_ptr->next;
            return *this;
        }
        Iterator operator++(int)
        {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }
        friend bool operator==(const Iterator &a, const Iterator &b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!=(const Iterator &a, const Iterator &b) { return a.m_ptr != b.m_ptr; };

    private:
        pointer m_ptr;
    };



    Iterator begin() { return Iterator(head); }
    Iterator end()   { return Iterator(tail->next); }







    node<dtype> *getHead()
    {
        return head;
    }
    node<dtype> *getTail()
    {
        return tail;
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

    node<dtype> *find(dtype data)
    {
        node<dtype> *p = head;
        while (p != nullptr && p->data != data)
        {
            p = p->next;
        }
        return p;
    }
    //Adds a new element ‘g’ at the beginning of the list .
    void push_front(dtype data)
    {
        insertAtPos(data, 0);
    }

    //Adds a new element ‘g’ at the end of the list.
    void push_back(dtype data)
    {
        insertAtPos(data, -1);
    }

    //Removes the first element of the list, and reduces size of the list by 1.
    dtype pop_front()
    {
        dtype data = head->data;
        deleteAtPos(0);
        return data;
    }

    //Removes the last element of the list, and reduces size of the list by 1.
    dtype pop_back()
    {
        dtype data = tail->data;
        deleteAtPos(-1);
        return data;
    }

    //Returns whether the list is empty(1) or not(0).
    bool isEmpty()
    {
        return s == 0;
    }

    //Reverses the list.
    void reverse()
    {
        reverseIt(head, tail);
    }

    //Removes a single element or a range of elements from the list.
    void erase(int l, int r = -1, selection type = inclusive)
    {
        if (r == -1)
            deleteAtPos(l);
        else
        {
            slice(l, r, type);
        }
    }

    //Removes all the elements from the list, which are equal to given element.
    void remove(int data)
    {
        node<dtype> *p = head;
        while (p->data == data)
        {
            deleteAddr(head, onMe);
            p = head;
        }
        while (p != nullptr && p->next != nullptr)
        {
            if (p->next->data == data)
                deleteAddr(p, beforeMe);
            p = p->next;
        }
    }

    //Used to remove all the values from the list that correspond true to the predicate or condition given as parameter to the function.
    void remove_if(function<bool(int)> test)
    {
        node<dtype> *p = head;
        while (p->next != nullptr)
        {
            if (test(p->next->data))
                deleteAddr(p, beforeMe);
            p = p->next;
        }
    }
};

bool even(int a)
{

    return (a % 2 == 0);
}
int main()
{
    LinkedList<int> a = {1, 2, 3, 4, 5, 3, 7, 8, 9, 893};
    // a.push_front(3);
    // //a.push_front(55);
    // a.printList();

    // a.erase(3);
    // a.printList();

    // a.reverse();
    // a.printList();
    for(auto i=a.rbegin();i!=a.rend();i++)
        cout<<(*i).data<<endl;

    /*
    cout << "Add 4 at 2\n";
    //a.insertAtPos(4, 2);
    a.printList();

    cout << "delete last\n";
    //a.deleteAtPos(-1);
    a.printList();

    cout << "delete from 3 to 6\n";
    //a.slice(3, 6, exclusive);
    a.printList();

    cout << "find address of 3\n";
    cout << a.find(3);*/
}