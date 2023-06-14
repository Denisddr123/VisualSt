#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char keys[] = "tests", fileIn[] = "Autumn", fileOut[] = "AutumnOut",
    fileOut2[] = "AutumnOut2", ch, *key=keys;
    int i=0, j=0, z=0;
    FILE *in, *out;
    if (argc>1)
    {
        key=argv[1];
        printf("%s\n", key);
    }
    
    if ((in=fopen(fileIn, "r")) == NULL)
    {
        printf("Ошибка открытия файла для чтения\n");
        return 1;
    }
    if((out = fopen(fileOut, "w")) == NULL) {
        printf("Ошибка открытия файла для записи\n");
        return 1;
    }
    
    while ((ch = getc(in)) != EOF)
    {
        while (j<5)
        {
            ch ^= key[j];
            j++;
        }
        j=0;
        putc(ch, out);
        i++;
    }
   
    fclose(in);
    fclose(out);

    if ((in=fopen(fileOut, "r")) == NULL)
    {
        printf("Ошибка открытия файла для чтения\n");
        return 1;
    }
    if((out = fopen(fileOut2, "w")) == NULL) {
        printf("Ошибка открытия файла для записи\n");
        return 1;
    }

    while (z<(i+1))
    {
        ch = getc(in);
        while (j<5)
        {
            ch ^= key[j];
            j++;
        }
        j=0;
        z++;
        putc(ch, out);
        //printf("%c", ch);
    
    }

    fclose(in);
    fclose(out);
}