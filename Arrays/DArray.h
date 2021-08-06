#ifndef HEADER_H_
#define HEADER_H_
#include <bits/stdc++.h>

#ifndef DS_H
#define DS_H
#define _DAI template <typename DArray> \
DArrayIterator<DArray>
#define _DAIC DArrayIterator<DArray>

#define _CDAI template <typename DArray> \
ConstDArrayIterator<DArray>
#define _CDAIC ConstDArrayIterator<DArray>

#define _TCT template <class T>
#define _TTD template <typename DArray>
#define _DA DArray<T>
#define M_DA DArray<T>
#endif

using namespace std;

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

    DArrayIterator &operator++();
    DArrayIterator operator++(int);
    DArrayIterator operator+(int idx);
    DArrayIterator &operator--();
    DArrayIterator operator-(int idx){
        return (m_ptr-idx);
    };
    int operator-(DArrayIterator idx);
    DArrayIterator operator--(int);
    reference_type operator[](int idx);
    reference_type operator*();
    pointer_type operator->();
    bool operator==(const DArrayIterator &other) const;
    bool operator!=(const DArrayIterator &other) const;

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

    ConstDArrayIterator &operator++();
    ConstDArrayIterator operator++(int);
    ConstDArrayIterator operator+(int idx);
    ConstDArrayIterator &operator--();
    ConstDArrayIterator operator--(int);
    int operator-(ConstDArrayIterator idx);
    reference_type operator[](int idx);
    reference_type operator*();
    pointer_type operator->();
    bool operator==(const ConstDArrayIterator &other) const;
    bool operator!=(const ConstDArrayIterator &other) const;

private:
    pointer_type m_ptr;
};

template <class T>
class DArray
{

public:
    using value_type = T;
    using Iterator = DArrayIterator<DArray<T>>;
    using ConstIterator = ConstDArrayIterator<const DArray<T>>;

public:
    //Constructors
    DArray<T>();
    DArray<T>(initializer_list<T> l);
    DArray<T>(size_t);
    DArray<T>(DArray<T> &other);
    DArray<T>(DArray<T> &&other) : m_data((T *)::operator new(sizeof(T) * other.size())), s(other.size()), pos(other.noOfitems())
    {
        //cout<<"r...";
        for (int i = 0; i < s; i++)
        {
            m_data[i] = move(other[i]);
        }
    }

    DArray<T>(Iterator b, Iterator e) :  m_data(new T[e-b]),s(e - b), pos(e-b)
    {
        int i = 0;
        for (Iterator it = b; it != e; it++, i++){
            m_data[i] = *it;
        }
            
    }
    DArray<T>(const T *b, const T *e) : m_data((T *)::operator new((e - b+10) * sizeof(T))),s(e - b+10), pos(e-b)
    {
        //cout << "s";
        int i = 0;
        for (auto it = b; it != e; it++, i++)
            m_data[i] = *it;
    }

    ~DArray();

    size_t size();
    int noOfitems();
    void print();

    value_type &operator[](int i);
    const value_type &operator[](int i) const;
    DArray &operator=(DArray &other);
    DArray &operator=(const DArray &other);
    DArray &operator=(DArray &&other);
    void push_back(const value_type &data);
    void push_back(value_type &&data);
    void pop_back();
    void clear();

    template <class Tx>
    friend ostream &operator<<(ostream &os, const DArray<Tx> &dt);

    Iterator begin();
    Iterator end();
    ConstIterator begin() const;
    ConstIterator end() const;

private:
    value_type *m_data;
    size_t s;
    int pos;
    void ReAlloc(size_t capacity);
};
#include "DArray.cpp"
#endif
