#include <iostream>
using namespace std;

class MineString
{
private:
    char *str;
    int length;
    void copy(char*, const char*, int, int);
public:
    MineString(const char*);
    MineString(const MineString &M);
    ~MineString();
    int strCmp(const char*, const char*) const;
    int strCmp(const char*) const;
    MineString& copy(const char*);
    MineString& copy(const MineString&);
    MineString& concat(const char*);
    void printStr();
    void setStr();
    MineString& operator=(const MineString&);
    MineString& operator+(const MineString&);
    int operator==(const MineString&);
    MineString& operator=(const char*);
    MineString& operator+(const char*);
    int operator==(const char*);
    int lenStrWhile(const char* m) const {
        int lengths = 0;
        while (*m)
        {
            m++;
           lengths++;
        }
        return lengths;
    }
    char* getMineStr() const {
        return &str[0];
    }
    int getLen() const {
        return length;
    }
};
MineString::MineString(const char* ch)
{
    length=lenStrWhile(ch);
    str = new char[length];
    copy(str, ch, length, 0);
}
MineString::MineString(const MineString &M) {
    length=M.getLen();
    str = new char[length];
    copy(str, M.getMineStr(), length, 0);
}
MineString& MineString::concat(const char* ch2) {
    int x=lenStrWhile(ch2), y = x+length;
    char *str2 = new char[y+1];
    copy(str2, str, length, 0);
    copy(str2, ch2, x, length);
    //str2[y] = '\0';
    MineString::~MineString();
    //delete [] str;
    str = str2;
    length = y;
    return *this;
}
void MineString::copy(char *dest, char const *src, int len, int indx) {
    int i=0, len1 = len+indx;
    while (indx<len1)
    {
        dest[indx]=src[i];
        i++;
        indx++;
    }
}
MineString& MineString::copy(char const *src) {
    int i=0, len = lenStrWhile(src);
    MineString::~MineString();
    //delete [] str;
    str = new char[len+1];
    while (i<len)
    {
        str[i]=src[i];
        i++;
    }
    //str[len]='\0';
    return *this;
}
MineString& MineString::copy(const MineString& m) {
    int i=0, len = m.getLen();
    char *s = m.getMineStr();
    MineString::~MineString();
    //delete [] str;
    str = new char[len+1];
    while (i<len)
    {
        str[i]=s[i];
        i++;
    }
    //str[len]='\0';
    return *this;
}
void MineString::printStr() {
    std::cout<<str<<endl;
}
void MineString::setStr() {
    char ch[100];
    std::cin.getline(ch, 100);
    MineString::copy(ch);
}
MineString& MineString::operator=(const MineString& m) {
    return MineString::copy(m);
}
MineString& MineString::operator=(const char* ch) {
    return MineString::copy(ch);
}
int MineString::operator==(const MineString& m) {
    return MineString::strCmp(m.getMineStr());
}
int MineString::operator==(const char* ch) {
    return MineString::strCmp(ch);
}
MineString& MineString::operator+(const MineString& m) {
    return MineString::concat(m.getMineStr());
}
MineString& MineString::operator+(const char* ch) {
    return MineString::concat(ch);
}
int MineString::strCmp(const char *str1, const char *str2) const {
    int z=0;
    int x = lenStrWhile(str1), y = lenStrWhile(str2);
    if (x!=y)
    {
        return x-y;
    }
    for (int i = 0; i < x; i++)
    {
        z = str1[i] - str2[i];
        if (z!=0) break;
    }
    return z;
}
int MineString::strCmp(const char *str2) const {
    int z=0;
    int x = length, y = lenStrWhile(str2);
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

MineString::~MineString()
{
    delete [] str;
}
