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
    int copy(const char*);
    void concat(const char*);
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
void MineString::concat(const char* ch2) {
    int x=lenStrWhile(ch2), y = x+length;
    char *str2 = new char[y];
    copy(str2, str, length, 0);
    copy(str2, ch2, x, length);
    delete [] str;
    str = str2;
    length = y;
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
int MineString::copy(char const *src) {
    int i=0, len = lenStrWhile(src);
    if (len>length)
    {
        return 1;
    }
    while (i<len)
    {
        str[i]=src[i];
        i++;
    }
    return 0;
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
