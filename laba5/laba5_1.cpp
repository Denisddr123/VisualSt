#include <stdio.h>
int main() {
    char name[50];
    FILE *in;
    printf("Введите имя файла для просмотра: ");
    scanf("%s", name);

    if ((in = fopen(name, "r")) == NULL)
        printf("Файл %s не открыт!", name);
    else
        while (!feof(in))
        {   
            putchar(getc(in));
        }
    fclose(in);
}