#include <iostream>
#include "conio.h-master/conio.h"
using namespace std;

int main() {
    int mas[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    int a=0, b=0, i=0, j=0, z=0, x=0, y=0;
    int n=sizeof(mas)/sizeof(int);
    int even[n], odd[n];
    void sortEvenAsc(int*, int*, int);
    void sortOddDesc(int*, int*, int);
    void sortAsc(int*, int, int);
    void sortDesc(int*, int, int);
    void printMas(int*, int);
    clrscr();
    
    printMas(mas, n);
    
    sortAsc(mas, 6, n-1);
    printMas(mas, n);

    sortAsc(mas, 3, n-4);
    printMas(mas, n);

    sortDesc(mas, 3, n-1);
    printMas(mas, n);

    for (i = 0; i < n; i++)
    {
        if (mas[i]%2 == 0)
        {
            even[j] = i;
            j++;
        } else {
            odd[z] = i;
            z++;
        }
        
    }
 
    sortEvenAsc(mas, even, j);
    printMas(mas, n);
    sortOddDesc(mas, odd, z);

    printMas(mas, n);
    
    return 0;
}
void printMas(int* mas, int n) {
    for (int i = 0; i < n; i++)
    {
        cout<<mas[i]<<"  ";
    }
    cout<<endl;
}

void sortEvenAsc(int* mas, int* mas2, int j) {
    for (int i = 0; i < j; i++)
    {
        bool flag = true;
        for (int z = 0; z < (j-i); z++)
        {
            if (mas[mas2[z]] > mas[mas2[z+1]])
            {
                flag = false;
                swap (mas[mas2[z]], mas[mas2[z+1]]);
            }
        }
        if (flag)
        {
            break;
        } 
    }
    
}

void sortOddDesc(int* mas, int* mas2, int j) {
    for (int i = 0; i < j; i++)
    {
        bool flag = true;
        for (int z = j-1; z > i; z--)
        {
            if (mas[mas2[z]] > mas[mas2[z-1]])
            {
                flag = false;
                swap (mas[mas2[z]], mas[mas2[z-1]]);
            }
        }
        if (flag)
        {
            break;
        } 
    }
    
}

void sortAsc(int* mas, int i, int j) {
    int n = j-i;
    for (int x = 0; x < n+1; x++)
    {
        bool flag = true;
        for (int z = i; z < (j-x); z++)
        {
            if (mas[z] > mas[z+1])
            {
                flag = false;
                swap (mas[z], mas[z+1]);
            }
        }
        if (flag)
        {
            break;
        } 
    }
    
}

void sortDesc(int* mas, int i, int j) {
    int n = j-i;
    for (int x = 0; x < n+1; x++)
    {
        bool flag = true;
        for (int z = j; z > (i+x); z--)
        {
            if (mas[z] > mas[z-1])
            {
                flag = false;
                swap (mas[z], mas[z-1]);
            }
        }
        if (flag)
        {
            break;
        } 
    }
    
}