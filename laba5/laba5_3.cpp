#include <stdio.h>
#include "MineString.h"
int main() {
    int searchString(FILE*, MineString mineString);
    char name[50]= "sources.list", array[100]="after the final release";
    FILE *in;
    printf("Введите имя файла для просмотра: ");
    cin.getline(name, 50);

    printf("Найти подстроку: ");
    cin.getline(array, 100);

    MineString mineString(array);

    if ((in = fopen(name, "r")) == NULL) {
        printf("Файл %s не открыт", name);
    }
    else printf("Позиция найденной подстроки: %d", searchString(in, mineString));
    fclose(in);
}

int searchString(FILE *in, MineString mineString) {
    char ch, *arr=mineString.getMineStr();
    int j=0, lenght = mineString.getLen(), i, pos=-1;
    
    while ((ch = getc(in)) != EOF)
        {
            printf("%c", ch);
            if (j==lenght)
                {
                    pos=(i-j);
                    break;
                } else if(ch != arr[j]) {
                    if (j>0)
                    {
                        fseek(in, i, SEEK_SET);
                    }
                    j=0;
                    continue;
                } else {
                    i=ftell(in);
                    j++;
                }
        }
    return pos;
}
