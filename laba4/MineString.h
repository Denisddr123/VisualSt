#include <iostream>
using namespace std;

class MineString
{
private:
    char *str;
    int length;
public:
    MineString(const char*);
    MineString(const MineString &M);
    ~MineString();
    void concat(const char*);
    void copy(char*, const char*, int, int);
    int lenStrWhile(const char* m) {
        int length = 0;
        while (*m)
        {
            m++;
           length++;
        }
        return length;
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

MineString::~MineString()
{
    delete [] str;
}
