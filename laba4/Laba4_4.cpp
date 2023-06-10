#include <string.h>
#include <iostream>
#include <typeinfo>
#include "MineStringMalloc.h"
using namespace std;

int main() {
    char *str1, *str2;
    void getStrings(char*, char*);
    int lenStrEnglish(char*);
    int lenStrWhile(const char*);
    int lenStrFor(const char*);
    char *copyStr(char*, const char*);
    int strCmp(char*, char*);
    int i;

    str1=(char*)calloc(30, sizeof(char));
    str2=(char*)calloc(51, sizeof(char));

    getStrings(str1, str2);
    cout<<str1<<"\t\t\t\t Первая строка"<<endl;
    cout<<str2<<"\t Вторая строка"<<endl;
    i = lenStrEnglish(str1);
    cout<<i<<"\t\t Длина первой строки"<<endl;
    i = lenStrEnglish(str2);
    cout<<i<<"\t\t Длина второй строки, одним способом"<<endl;

    i = lenStrWhile(str2);
    cout<<i<<"\t\t Длина второй строки с помощью цикла while"<<endl;

    i = lenStrFor(str2);
    cout<<i<<"\t\t Длина второй строки с помощью цикла for"<<endl;

    cout<<endl;

    cout<<"Копирование второй строки в первую, своя функция."<<endl;
    copyStr(str1, str2);
    cout<<str1<<"\t\t\t\t Первая строка после изменения"<<endl;
    cout<<str2<<"\t Вторая строка после изменения"<<endl;

    getStrings(str1, str2);

    cout<<endl;
    cout<<str1<<"\t\t\t\t Первая новая строка"<<endl;
    cout<<str2<<"\t Вторая новая строка"<<endl;

    char *chr;
    cout<<"Сравнение строк, своя функция.  ";
    cout<<strCmp(str1, str2)<<endl;
    MineString minstr(str1);
    chr = minstr.getMineStr();
    cout<<endl;
    cout<<"Конкатенация первой строки со второй, своя функция."<<endl;
    minstr.concat(str2);
    chr = minstr.getMineStr();
    cout<<str1<<"\t\t\t\t\t\t\t Первая строка после изменения"<<endl;
    cout<<chr<<"\t Вторая строка после изменения"<<endl;
    cout<<endl;
    i = lenStrEnglish(str1);
    cout<<i<<"\t\t Длина первой строки"<<endl;
    cout<<minstr.getLen()<<"\t\t Длина второй строки"<<endl;
        
    free(str2);
    free(str1);    
    return 0; 
}

void getStrings(char * str1, char * str2) {
    int x=0;
    char str3[] = "On platforms with a two bytu.";
    char str4[] = "The local variables have a lifetime which extends.";
    while (str3[x] != '\0')
    {
        *str1=str3[x];
        x++;
        str1++; 
    }
    x=0;
    while (str4[x] != '\0')
    {
        *str2=str4[x];
        x++;
        str2++;
    }
    *(str1++) = '\0';
    *(str2++) = '\0';
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
