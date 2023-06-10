#include <string.h>
#include <iostream>
using namespace std;

int main() {
    char str1[7]="qwerty"; char const str2[11]="1234567890";
    string * str3= new string("qwerty"); string str4 ="1234567890"; string str5= "before";
    const char *ch = &str2[0];
    //str3->operator += "1234567890";
    str3->append(str4);
    str5.append(str4);
    //str3->append("1234567890");

    int i;
    cout<<str1<<endl;
    cout<<str2<<endl;
    cout<<str3->data()<<endl;
    cout<<str4.data()<<endl;
    cout<<str5.data()<<endl;
    cout<<str4.data()<<endl;
    
    i = strlen(str2);
    cout<<i<<endl;
    
    strcat(str1, str2);

    cout<<str1<<endl;
    cout<<str2<<endl;

    i = strlen(str2);
    cout<<i<<endl;

    i = strcmp(&str1[0], &str2[0]);
    cout<<i<<endl;
    /* cout<<str1<<endl;
    cout<<str2<<endl; */
    strcpy(str1, str2);
    cout<<str1<<endl;
    cout<<str2<<" end"<<endl;
    return 0;
}