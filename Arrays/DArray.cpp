#include "DArray.h"
_DAI &_DAIC::operator++() { ++m_ptr; return *this; }
_DAI _DAIC::operator++(int) { DArrayIterator it = m_ptr++; return it; }
_DAI _DAIC::operator+(int idx) { return m_ptr + idx; }

_DAI &_DAIC::operator--() { m_ptr--; return *this; }
_DAI _DAIC::operator--(int) { DArrayIterator it = m_ptr--; return *this; }
_TTD int _DAIC::operator-(DArrayIterator idx) { return m_ptr - idx.m_ptr; }

_TTD typename _DAIC::reference_type _DAIC::operator[](int idx) { return *(m_ptr + idx); }
_TTD typename _DAIC::reference_type _DAIC::operator*() { return *(m_ptr); }
_TTD typename _DAIC::pointer_type _DAIC::operator->() { return m_ptr; }

_TTD bool _DAIC::operator==(const DArrayIterator &other) const { return m_ptr == other.m_ptr; }
_TTD bool _DAIC::operator!=(const DArrayIterator &other) const { return !(m_ptr == other.m_ptr); }
/************************************************************/


/************************************************************/
_CDAI &_CDAIC::operator++() { ++m_ptr; return *this; }
_CDAI _CDAIC::operator++(int){ _CDAIC it = m_ptr++; return it; }
_CDAI _CDAIC::operator+(int idx) { return m_ptr + idx; }

_CDAI &_CDAIC::operator--() { m_ptr--; return *this; }
_CDAI _CDAIC::operator--(int) { _CDAIC it = m_ptr--; return it; }
_TTD int _CDAIC::operator-(ConstDArrayIterator idx) { return m_ptr - idx.m_ptr; }

_TTD typename _CDAIC::reference_type _CDAIC::operator[](int idx) { return *(m_ptr + idx); }
_TTD typename _CDAIC::reference_type _CDAIC::operator*() { return *(m_ptr); }
_TTD typename _CDAIC::pointer_type _CDAIC::operator->() { return m_ptr; }

_TTD bool _CDAIC::operator==(const ConstDArrayIterator &other) const { return m_ptr == other.m_ptr; }
_TTD bool _CDAIC::operator!=(const ConstDArrayIterator &other) const { return !(m_ptr == other.m_ptr); }
/************************************************************/


/************************************************************/
_TCT _DA::DArray() : m_data((T *)::operator new(10 * sizeof(T))), s(10), pos(0) {}
_TCT _DA::DArray(initializer_list<T> l) : m_data((T *)::operator new(sizeof(T) * l.size() + 10)), 
                                                        s(l.size() + 10), pos(l.size()){
    //cout<<"ini";
    int pos = 0;
    for (auto i : l) 
        m_data[pos++] = i;
}
_TCT _DA::DArray(size_t s) : m_data((T *)::operator new(sizeof(T) * s)), s(s), pos(0) {}
_TCT _DA::DArray(DArray<T> &other) : m_data((T *)::operator new(sizeof(T) * (other.size() + 10))), 
                                        s(other.size() + 10), pos(other.noOfitems()) {
    //cout<<"copy";
    for (int i = 0; i < s; i++)
        m_data[i] = other[i];
}
_TCT _DA::DArray(DArray<T> &&other) : m_data((T *)::operator new(sizeof(T) * other.size())), 
                                        s(other.size()), pos(other.noOfitems()) {
        //cout<<"r...";
        for (int i = 0; i < s; i++)
            m_data[i] = move(other[i]);
}
_TCT _DA::DArray(Iterator b, Iterator e) :  m_data(new T[e-b]),s(e - b), pos(e-b) {
        int i = 0;
        for (Iterator it = b; it != e; it++, i++)
            m_data[i] = *it;
}
_TCT _DA::DArray(const T *b, const T *e) : m_data((T *)::operator new((e - b+10) * sizeof(T)))
                                            ,s(e - b+10), pos(e-b) {
        //cout << "s";
        int i = 0;
        for (auto it = b; it != e; it++, i++)
            m_data[i] = *it;
}

_TCT _DA::~DArray(){
    //cout << "Deleted: " << m_data[0] << endl;
    clear();
    ::operator delete(m_data, s * sizeof(T));
    s = 0;
    pos = 0;
}
/************************************************************************************************************************/













/************************************************************************************************************************/
_TCT size_t _DA::size() { return s; }
_TCT int _DA::noOfitems() { return pos; }
_TCT void _DA::print() {
    cout << "\n--------------DATA------------------\n";
    for (int i = 0; i < pos; i++)
        cout << m_data[i] << " ";
    cout << "\nSize: " << s << "\nElements: " << pos;
    cout << "\n-------------------------------END>>\n";
}
_TCT typename _DA::value_type &_DA::operator[](int i) { return *(m_data + i); }
_TCT const typename _DA::value_type &_DA::operator[](int i) const { return *(m_data + i); }

_TCT _DA &_DA::operator=(_DA &other) {
    clear();
    ::operator delete(m_data, s * sizeof(T));
    s = other.size();
    pos = other.noOfitems();
    m_data = (T *)::operator new(s * sizeof(T));
    for (int i = 0; i < pos; i++)
        m_data[i] = other[i];
}
_TCT _DA &_DA::operator=(_DA &&other) {
    clear();
    ::operator delete(m_data, s * sizeof(T));
    s = other.size();
    pos = other.noOfitems();
    m_data = (T *)::operator new(s * sizeof(T));
    for (int i = 0; i < pos; i++)
        m_data[i] = move(other[i]);
    return *this;
}
_TCT _DA &_DA::operator=(const _DA &other){
    clear();
    ::operator delete(m_data, s * sizeof(T));
    s = other.s;
    pos = other.pos;
    m_data = (T *)::operator new(s * sizeof(T));
    for (int i = 0; i < pos; i++)
        m_data[i] = other[i];
    return *this;
}

_TCT void _DA::push_back(const value_type &data) {
    if (pos + 1 == (int)s)
        ReAlloc(1.5 * s);
    m_data[pos++] = data;
}

_TCT void _DA::push_back(value_type &&data) {
    if (pos + 1 == s)
        ReAlloc(1.5 * s);
    m_data[pos++] = std::move(data);
}

_TCT void _DA::pop_back() {
    if (pos >= 0) {
        pos--;
        m_data[pos].~T();
    }
}

_TCT void _DA::clear() {
    for (size_t i = 0; i < (size_t)pos; i++)
        m_data[i].~T();
    pos = 0;
}

_TCT ostream &operator<<(ostream &os, const DArray<T> &dt) {
    for (int i = 0; i < dt.pos; i++)
        os << dt[i] << ", ";
    os << endl;
    return os;
}

_TCT void _DA::ReAlloc(size_t capacity) {
    T *newBlock = (T *)::operator new(sizeof(T) * capacity);

    if ((int)capacity < pos)
        pos = capacity;

    for (int i = 0; i < pos; i++)
        newBlock[i] = move(m_data[i]);

    for (int i = 0; i < pos; i++)
        m_data[i].~T();

    ::operator delete(m_data, sizeof(T) * s);
    m_data = newBlock;
    s = capacity;
}






//******************************************* ITERATORS
_TCT typename _DA::Iterator _DA::begin() { return Iterator(m_data); }
_TCT typename M_DA::Iterator M_DA::end() { return M_DA::Iterator(m_data + s); }
_TCT typename _DA::ConstIterator _DA::begin() const { return ConstIterator(m_data); }
_TCT typename M_DA::ConstIterator M_DA::end() const { return ConstIterator(m_data + s); }
