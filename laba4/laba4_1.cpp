#include <string.h>
#include <iostream>
#include <typeinfo>
#include "MineString.h"
using namespace std;

int main() {
    char str1[7]="qwerty"; char str2[11]="1234567890";
    int lenStrEnglish(char*);
    int lenStrWhile(const char*);
    int lenStrFor(const char*);
    char *copyStr(char*, const char*);
    int strCmp(char*, char*);
    int i;
    cout<<str1<<"\t\t Первая строка"<<endl;
    cout<<str2<<"\t Вторая сторка"<<endl;
    
    i = strlen(str2);
    cout<<i<<"\t\t Длина второй строки"<<endl;
    
    cout<<endl;
    cout<<"Конкатенация первой строки со второй."<<endl;
    strcat(str1, str2);
    cout<<str1<<"\t Первая строка после изменения"<<endl;
    cout<<str2<<"\t Вторая сторка после изменения"<<endl;

    i = strlen(str2);
    cout<<i<<"\t\t Длина второй строки"<<endl;

    i = strcmp(&str1[0], &str2[0]);
    cout<<i<<"\t\t Результат сравнения строк"<<endl;
    
    cout<<endl;
    cout<<"\t\t Копирование второй строки в первую"<<endl;
    strcpy(str1, str2);
    cout<<str1<<"\t Первая строка после изменения"<<endl;
    cout<<str2<<"\t\t Вторая сторка после изменения"<<endl;

    cout<<endl;
    char str4[]= "On platforms with a two byte.";
    cout<<str1<<"\t\t\t Первая строка"<<endl;
    cout<<str4<<"\t Вторая строка"<<endl;
    i = lenStrEnglish(str4);
    cout<<i<<"\t\t Длина второй строки, одним способом"<<endl;

    i = lenStrWhile(str4);
    cout<<i<<"\t\t Длина второй строки с помощью цикла while"<<endl;

    i = lenStrFor(str4);
    cout<<i<<"\t\t Длина второй строки с помощью цикла for"<<endl;

    cout<<endl;
    cout<<"Копирование второй строки в первую, своя функция."<<endl;
    copyStr(str1, str4);
    cout<<str1<<"\t\t\t Первая строка после изменения"<<endl;
    cout<<str4<<"\t Вторая строка после изменения"<<endl;

    char str3[] = "On platforms with a two bytu.";
    char str5[] = "The local variables have a lifetime which extends.";

    cout<<endl;
    cout<<str3<<"\t\t\t\t Первая новая строка"<<endl;
    cout<<str5<<"\t Вторая новая строка"<<endl;

    char *chr;
    cout<<"Сравнение строк, своя функция.  ";
    cout<<strCmp(str5, str3)<<endl;
    MineString minstr(str5);
    chr = minstr.getMineStr();
    cout<<endl;
    cout<<"Конкатенация первой строки со второй, своя функция."<<endl;
    minstr.concat(str3);
    chr = minstr.getMineStr();
    cout<<str3<<"\t\t\t\t\t\t\t Первая строка после изменения"<<endl;
    cout<<chr<<"\t Вторая строка после изменения"<<endl;
    cout<<endl;
    cout<<minstr.getLen()<<"\t\t Длина второй строки"<<endl;    
    return 0;
}

int strCmp(char *str, char *str2) {
    int lenStrWhile(const char*), z=0;
    int x = lenStrWhile(str), y = lenStrWhile(str2);
    if (x!=y)
    {
        return x-y;
    }
    for (int i = 0; i < x; i++)
    {
        z = str[i] - str2[i];
        if (z!=0) break;
    }
    return z;
}

char *copyStr(char *dest, const char *src) {
    int x = strlen(src), y = strlen(dest);
    for (int i = 0; i < (y); i++)
    {
        dest[i] = src[i];
    }
    return dest;
}

int lenStrEnglish(char* m) {
    long int x = (long int)m;
    char *ch;
    int i = sizeof(char);
    
    int len=0;
    while (x)
    {
        ch = (char*)x;
        if (*ch == '\0')
        {
            break;
        }
        x +=i;
        ++len;
    }
    return len;
}

int lenStrWhile(const char* m) {
    int length = 0;
    while (*m)
    {
        m++;
        length++;
    }
    return length;
}

int lenStrFor(const char* m) {
    int length = 0;
    for (; *m; length++, m++);
    return length;
}
