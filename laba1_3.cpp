#include <iostream>
using namespace std;

int a=2, b=5;
int main() {
    int *pa = &a, *pb= &b;
    void obmen1(int, int);
    void obmen2(int*, int*);
    void obmen3(int&, int&);
    cout<< "до обмена : a= "<< a <<"b= "<<b<<endl;

    obmen1(a, b);
    cout<< "после обмена 1: a= "<< a <<"b= "<<b<<endl;
    obmen2(pa, pb);
    cout<< "после обмена 2: a= "<< a <<"b= "<<b<<endl;
    obmen3(a, b);
    cout<< "после обмена 3: a= "<< a <<"b= "<<b<<endl;
}
void obmen1(int x, int y) {
    int z=x;
    if (a==x) {
        a=y;
        b=z;
    } else
    {
        b=y;
        a=z;
    }
}
void obmen2(int* x, int* y) {
    int z= *x;
    *x = *y;
    *y= z;

}
void obmen3(int &x, int &y) {
    int z= x;
    x = y;
    y= z;
}