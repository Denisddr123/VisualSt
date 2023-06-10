#include <stdio.h>
int main() {
    char ch, name[50], array[] = {'\a', '\b', '\f',
    '\n', '\r', '\t', '\v', '\\', '\'', '\"', '\?', ' '},
    *arr = array;
    int i=0, j=0;
    FILE *in;
    printf("Введите имя файла для просмотра: ");
    scanf("%s", name);

    if ((in = fopen(name, "r")) == NULL)
        printf("Файл %s не открыт", name);
    else
        while ((ch = getc(in)) != EOF)
        {
            j=0;
            while(j<13) {
                if (ch == array[j])
                {
                    i++;
                    break;
                }
                j++;
            };
            
            putchar(ch);
        }
        printf("Количество управляющих символов: %d", i);
    fclose(in);
}