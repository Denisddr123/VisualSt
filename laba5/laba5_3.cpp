#include <stdio.h>
#include "../laba4/MineString.h"
int main() {
    int searchString(FILE*, MineString mineString);
    char name[50]= "sources.list", array[100]="after the final release";
    FILE *in;
    printf("Введите имя файла для просмотра: ");
    cin.getline(name, 50);
    //scanf("%s", name);

    printf("Найти подстроку: ");
    //scanf("%s", array);
    
    cin.getline(array, 100);
    //printf("Длина строки %s \n", &array[0]);
    //MineString *mineString = new MineString(array);

    MineString mineString(array);

    if ((in = fopen(name, "r")) == NULL) {
        printf("Файл %s не открыт", name);
    }
    else printf("Позиция найденной подстроки: %d", searchString(in, mineString));
    fclose(in);
}

int searchString(FILE *in, MineString mineString) {
    char ch, *arr=mineString.getMineStr();
    //printf("Файл %s ", arr);
    int j=0, lenght = mineString.getLen(), i, pos=-1;
    while ((ch = getc(in)) != EOF)
        {
            putchar(ch);
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
