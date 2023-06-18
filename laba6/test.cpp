#include "MineString.h"

int main() {
    int x;
    MineString mineString("Simple text");
    MineString mineString3("Simple text");
    MineString mineString2("On platforms with a two bytu.");
    x= mineString == mineString2;
    std::cout<<x<<endl;
    x= mineString == mineString3;
    std::cout<<x<<endl;
    mineString = mineString2;
    std::cout<<mineString.getMineStr()<<endl;
    mineString3+mineString;
    mineString3+mineString2;
    mineString3.concat(" test");
    std::cout<<mineString3.getMineStr()<<endl;
    mineString3="fill";
    mineString3="fill1";
    mineString3="fill2";
    std::cout<<mineString3.getMineStr()<<endl;
    mineString3.concat(" test");
    mineString3.concat(" test");
    mineString3.concat(" test");
    mineString3+" tests!";
    mineString3+" tests!";
    std::cout<<mineString3.getMineStr()<<endl;
    
    MineString *m = new MineString(mineString2);
    
    std::cout<<m->getMineStr()<<endl;
    //MineString *m2 = new MineString(m->getMineStr());
    //MineString *m2 = new MineString("Ptr*");
    MineString m2 = *m;
    std::cout<<m2.getMineStr()<<endl;
    //m2 = m;
    m2.concat("101010");
    std::cout<<m2.getMineStr()<<endl;
    m->copy("Simple text");
    m2 + m;
    std::cout<<m->getMineStr()<<endl;
    std::cout<<m2.getMineStr()<<endl;
    m->copy("string");
    std::cout<<m->getMineStr()<<endl;
    std::cout<<m2.getMineStr()<<endl;
    m2.copy(m);
    m->copy("striiiiiing");
    std::cout<<m->getMineStr()<<endl;
    std::cout<<m2.getMineStr()<<endl;
    /* m->setStr();
    m->printStr(); */
    x = m->strCmp("aa","ab"); 
    std::cout<<x<<endl;
    MineString mine = "select";
    mine.copy("1234");
    mine.copy("5678");
    
    mine.copy("1111");
    mine.copy("2222");
    mine+" 5678";
    //std::cout<<mine.getMineStr()<<endl;
    mine = mineString2 = mine;
    std::cout<<mine.getMineStr()<<endl;
    std::cout<<mineString2.getMineStr()<<endl;
    mine="help";
    mine.copy("1111");
    mine.copy("56789");
    std::cout<<mine.getMineStr()<<endl;
    std::cout<<mineString2.getMineStr()<<endl;
    mine.concat(" break");
    mine.copy("056789");
    mine + " break";
    mine + " break";
    
    std::cout<<mine.getMineStr()<<endl;
    std::cout<<mineString2.getMineStr()<<endl;
    mine+mineString;
    std::cout<<mine.getMineStr()<<endl;
    std::cout<<mineString2.getMineStr()<<endl;
    *m="select";
    *m+" what";
    std::cout<<m->getMineStr()<<endl;
    (*m)+mine;
    std::cout<<m->getMineStr()<<endl;

     MineString mi = "select";
    std::cout<<mi.getMineStr()<<endl;
    mi + " break";
    mi + " break";
    mi+mineString;
    std::cout<<mi.getMineStr()<<endl;

    delete(m);
}