#include <iostream>
using namespace std;
int main() {
    int i, k;
    int power(int, int);
    for (i = 0; i < 10; i++)
    {
        k = power(2, i);
        cout<<"i = "<<i<<", k = "<<k<<endl;
    }
    
}
int power(int x, int n) {
    int i, p=1;
    for (i = 1; i < n; i++)
    {
        p*=x;
    }
    return p;
}