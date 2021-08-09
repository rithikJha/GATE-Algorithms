#include<bits/stdc++.h>
using namespace std;

template<class T,size_t sz>
class Stack{
    T a[sz];
    int size;
    int topE;

    public:
        Stack() : size(sz),topE(-1){}

        void push(T s){
            if(topE==size-1){
                cout<<"Stack full"<<endl;return;}
            a[++topE] = s;
        }
        T pop(){
            if(topE==-1){
                cout<<"Stack Empty"<<endl;return T();}
            topE--;
            return a[topE+1];
        }
        T top(){
            if(topE==-1){
                cout<<"Nothing on top ! EMPTY"<<endl;return T();}
            return a[topE];
        }
        bool isEmpty(){
            return topE==-1;
        }
};

int main(){
    Stack<int,10> s;
    s.push(1);
    s.push(3);
    s.push(1);
    s.push(3);
    s.push(1);
    s.push(3);
    s.push(1);
    s.push(3);

    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
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
    cout<<s.top()<<endl;
}