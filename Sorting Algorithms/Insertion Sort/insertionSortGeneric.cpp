#include<bits/stdc++.h>
using namespace std;
struct student{
    string name;
    int roll;
    char grade;
    float marks;
    friend ostream& operator<<(ostream& out,const student a);
};
ostream& operator<<(ostream& out, const student a){
    out<<"{"<<"Name: "<<a.name;
    out<<" "<<"Roll: "<<a.roll;
    out<<" "<<"Grade: "<<a.grade;
    out<<" "<<"Marks: "<<a.marks<<"}\n";
    return out;
}

template<class dtype>
void insertionSort(dtype A[], size_t n, function<bool(dtype,dtype)> cmp){
    for(int i =1;i<int(n);i++){
        int j=i-1;
        dtype val = A[i];
        while(j>=0 && cmp(A[j],val)){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=val;
    }
}

int main(){
    student class10[]{{"Rithik",1,'A',96},{"Rick",2,'F',32},{"Mick",3,'B',78},{"Wick",4,'C',66}};
    size_t n = sizeof(class10)/sizeof(class10[0]);
    // Sort according to marks in ascending order
    insertionSort<student>(class10,n,[](student a, student b){return a.marks>b.marks;});
    for(int i=0;i<n;i++)
        cout<<class10[i];
}