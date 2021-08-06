#include <bits/stdc++.h>
using namespace std;

struct vee
{
    int a = 3, b = 4, c = 5;
    vee() {}
    vee(int x)
    {
        a = x;
        b = x;
        c = x;
    }
    vee(int x, int y, int z)
    {
        a = x;
        b = y;
        c = z;
    }
    vee(const vee &other) : a(other.a), b(other.b), c(other.c)
    {
        cout << "copy" << endl;
    }
    vee(vee &&other) : a(other.a), b(other.b), c(other.c)
    {
        cout << "move" << endl;
    }
    ~vee() { cout << "destroy" << endl; }
    vee &operator=(const vee &other)
    {
        cout << "copy" << endl;
        a = other.a;
        b = other.b;
        c = other.c;
        return *this;
    }
    vee &operator=(vee &&other)
    {
        cout << "move" << endl;
        a = other.a;
        b = other.b;
        c = other.c;
        return *this;
    }
};

template <typename DArray>
class DArrayIterator
{
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = typename DArray::value_type;
    using difference_type = std::ptrdiff_t;
    using pointer_type = value_type *;
    using reference_type = value_type &;

    DArrayIterator(pointer_type ptr) : m_ptr(ptr) {}

    DArrayIterator &operator++()
    {
        m_ptr++;
        return *this;
    }
    DArrayIterator &operator++(int)
    {
        DArrayIterator it = m_ptr;
        ++m_ptr;
        return *this;
    }
    DArrayIterator &operator--()
    {
        m_ptr--;
        return *this;
    }
    DArrayIterator &operator--(int)
    {
        --m_ptr;
        return *this;
    }
    reference_type operator[](int idx)
    {
        return *(m_ptr + idx);
    }
    reference_type operator*()
    {
        return *(m_ptr);
    }
    pointer_type operator->()
    {
        return m_ptr;
    }
    bool operator==(const DArrayIterator &other) const
    {
        return m_ptr == other.m_ptr;
    }
    bool operator!=(const DArrayIterator &other) const
    {
        return !(m_ptr == other.m_ptr);
    }

private:
    pointer_type m_ptr;
};

template <typename DArray>
class ConstDArrayIterator
{
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = typename DArray::value_type;
    using difference_type = std::ptrdiff_t;
    using pointer_type = const value_type *;
    using reference_type = const value_type &;

    ConstDArrayIterator(pointer_type ptr) : m_ptr(ptr) {}

    ConstDArrayIterator &operator++()
    {
        m_ptr++;
        return *this;
    }
    ConstDArrayIterator &operator++(int)
    {
        ConstDArrayIterator it = m_ptr;
        ++m_ptr;
        return *this;
    }
    ConstDArrayIterator &operator--()
    {
        m_ptr--;
        return *this;
    }
    ConstDArrayIterator &operator--(int)
    {
        ConstDArrayIterator it = m_ptr;
        --m_ptr;
        return *this;
    }
    reference_type operator[](int idx)
    {
        return *(m_ptr + idx);
    }
    reference_type operator*()
    {
        return *(m_ptr);
    }
    pointer_type operator->()
    {
        return m_ptr;
    }
    bool operator==(const ConstDArrayIterator &other) const
    {
        return m_ptr == other.m_ptr;
    }
    bool operator!=(const ConstDArrayIterator &other) const
    {
        return !(m_ptr == other.m_ptr);
    }

private:
    pointer_type m_ptr;
};

template <class T>
class DArray
{

public:
    using value_type = T;
    using Iterator = DArrayIterator<DArray<T>>;
    using ConstIterator = ConstDArrayIterator<DArray<T>>;

public:
    DArray<T>() : m_data(new T[10]), s(10), pos(0)
    {
    }
    DArray<T>(initializer_list<T> l) : m_data((T *)::operator new(sizeof(T) * l.size() + 10)), s(l.size() + 10), pos(l.size())
    {
        int pos = 0;
        for (auto i : l)
        {
            m_data[pos] = i;
            pos++;
        }
    }
    DArray<T>(size_t s) : m_data((T *)::operator new(sizeof(T) * s + 10)), s(s + 10), pos(0)
    {
    }
    //copy-constructor
    DArray<T>(DArray<T> &other) : m_data(new T[other.size()+10]), s(other.size() + 10), pos(other.noOfitems())
    {

        for (int i = 0; i < s; i++)
        {
            m_data[i] = other[i];
        }
    }
    ~DArray()
    {
        cout << "Delete: " << s * sizeof(T) << endl;
        clear();
        //delete[] m_data;
        ::operator delete(m_data, s * sizeof(T));
    }
    size_t size()
    {
        return s;
    }
    int noOfitems() { return pos; }
    value_type &operator[](int i)
    {
        return *(m_data + i);
    }
    const value_type &operator[](int i) const
    {
        return *(m_data + i);
    }
    void print()
    {
        cout << "\n--------------DATA------------------\n";

        for (int i = 0; i < pos; i++)
        {
            cout << m_data[i] << " ";
        }
        cout << "\nSize: " << s << "\nElements: " << pos;
        cout << "\n-------------------------------END>>\n";
    }
    void push_back(const value_type &data)
    {
        cout << "copy: " << s << endl;
        if (pos == s)
        {
            ReAlloc(1.5 * s);
        }

        m_data[pos++] = data;
    }
    void push_back(value_type &&data)
    {
        cout << "move: " << s << endl;
        if (pos == s)
        {
            ReAlloc(1.5 * s);
        }

        m_data[pos++] = std::move(data);
    }
    void pop_back()
    {
        if (pos >= 0)
        {
            pos--;
            m_data[pos].~T();
        }
    }
    void clear()
    {
        for (size_t i = 0; i < pos; i++)
        {
            m_data[i].~T();
        }
        pos = 0;
    }
    template <class Tx>
    friend ostream &operator<<(ostream &os, const DArray<Tx> &dt);

    Iterator begin()
    {
        return Iterator(m_data);
    }
    Iterator end()
    {
        return Iterator(m_data + s);
    }

private:
    value_type *m_data;
    size_t s;
    int pos;
    void ReAlloc(size_t capacity)
    {
        T *newBlock = (T *)::operator new(sizeof(T) * capacity);
        if (capacity < pos)
            pos = capacity;

        for (int i = 0; i < pos; i++)
            newBlock[i] = std::move(m_data[i]);

        for (int i = 0; i < pos; i++)
            m_data[i].~T();

        ::operator delete(m_data, sizeof(T) * s);
        m_data = newBlock;
        s = capacity;
    }
};
template <class T>
ostream &operator<<(ostream &os, const DArray<T> &dt)
{
    for (int i = 0; i < dt.pos; i++)
    {
        cout << dt[i] << ", ";
    }
    cout << endl;
}

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