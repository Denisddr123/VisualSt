#include <iostream>
using namespace std;

int main() {
    int mas[] = {5, 3, 6, 2, 7, 0, 2, 8, 9, 10};
    for (int i = 0; i < 10; i++)
    {
        bool flag = true;
        for (int j = 0; j < (10-(i+1)); j++)
        {
            if (mas[j] > mas[j+1])
            {
                flag = false;
                swap (mas[j], mas[j+1]);
            }
        }
        if (flag)
        {
            break;
        } 
    }
    cout<<"Массив в отсортированном виде: ";
    for (int i = 0; i < 10; i++)
    {
        cout<<mas[i]<<" ";
    }
    return 0;
}