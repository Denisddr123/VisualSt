#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "conio.h-master/conio.h"
#define N 5
using namespace std;
int main() {
    float minMatrix(float*);
    float maxMatrix(float*);
    float minLowerTriangularPart(float*);
    float minUpperTriangularPart(float*);
    float maxLowerTriangularPart(float*);
    float maxUpperTriangularPart(float*);
    float minMainDiagonal(float*);
    float maxMainDiagonal(float*);
    float minSecondaryDiagonal(float*);
    float maxSecondaryDiagonal(float*);
    float arithmeticMeanMatrix(float*);
    float arithmeticMeanUpperTriangular(float*);
    float arithmeticMeanLowerTriangular(float*);
    void sumLine(float*, float*);
    void sumOfColumns(float*, float*);
    void minValueOfColumns(float*, float*);
    void minValueOfLine(float*, float*);
    void maxValueOfColumns(float*, float*);
    void maxValueOfLine(float*, float*);
    void arithmeticMeanOfColumns(float*, float*);
    void arithmeticMeanLine(float*, float*);
    float sumLowerTriangularPart(float*);
    float sumUpperTriangularPart(float*);
    float closeValueToArithmeticMean(float*);
    float m[N][N], z;
    int i, j;
    for(i=0; i<N; i++) {
        for (j=0; j<N; j++) {
        m[i][j] = rand()/100000000.;
        }
    }
    
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            cout<<setw(12)<<setprecision(5)<<m[i][j];
        }
        cout << endl;
    }
    z = minMatrix(&m[0][0]);
    cout<<"Минимум матрицы :"<<z<<endl;

    z = maxMatrix(&m[0][0]);
    cout<<"Максимум матрицы :"<<z<<endl;

    z = minLowerTriangularPart(&m[0][0]);
    cout<<"Минимум нижнетреугольной части матрицы :"<<z<<endl;

    z = minUpperTriangularPart(&m[0][0]);
    cout<<"Минимум верхнетреугольной части матрицы :"<<z<<endl;

    z = maxLowerTriangularPart(&m[0][0]);
    cout<<"Максимум нижнетреугольной части матрицы :"<<z<<endl;

    z = maxUpperTriangularPart(&m[0][0]);
    cout<<"Максимум верхнетреугольной части матрицы :"<<z<<endl;

    z = minMainDiagonal(&m[0][0]);
    cout<<"Минимум главной диагонали матрицы :"<<z<<endl;

    z = maxMainDiagonal(&m[0][0]);
    cout<<"Максимум главной диагонали матрицы :"<<z<<endl;

    z = minSecondaryDiagonal(&m[0][0]);
    cout<<"Минимум второстепенной диагонали матрицы :"<<z<<endl;

    z = maxSecondaryDiagonal(&m[0][0]);
    cout<<"Максимум второстепенной диагонали матрицы :"<<z<<endl;

    z = arithmeticMeanMatrix(&m[0][0]);
    cout<<"Среднее значение матрицы :"<<z<<endl;

    z = arithmeticMeanLowerTriangular(&m[0][0]);
    cout<<"Среднее значение нижнетреугольной части матрицы :"<<z<<endl;

    z = arithmeticMeanUpperTriangular(&m[0][0]);
    cout<<"Среднее значение верхнетреугольной части матрицы :"<<z<<endl;

    float n[N];
    sumLine(&m[0][0], n);
    cout<<"Суммы строк"<<endl;
    for (i = 0; i < N; i++)
    {
        cout<<n[i]<<endl;
    }
    cout<<endl;

    sumOfColumns(&m[0][0], n);
    cout<<"Суммы столбцов"<<endl;
    for (i = 0; i < N; i++)
    {
        cout<<n[i]<<"   ";
    }
    cout<<endl;

    minValueOfLine(&m[0][0], n);
    cout<<"Минимальные значения строк"<<endl;
    for (i = 0; i < N; i++)
    {
        cout<<n[i]<<endl;
    }

    minValueOfColumns(&m[0][0], n);
    cout<<"Минимальные значения столбцов"<<endl;
    for (i = 0; i < N; i++)
    {
        cout<<n[i]<<"   ";
    }
    cout<<endl;

    maxValueOfLine(&m[0][0], n);
    cout<<"Максимальные значения строк"<<endl;
    for (i = 0; i < N; i++)
    {
        cout<<n[i]<<endl;
    }

    maxValueOfColumns(&m[0][0], n);
    cout<<"Максимальные значения столбцов"<<endl;
    for (i = 0; i < N; i++)
    {
        cout<<n[i]<<"   ";
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;

    arithmeticMeanLine(&m[0][0], n);
    cout<<"Среднеарифметические значения строк"<<endl;
    for (i = 0; i < N; i++)
    {
        cout<<n[i]<<endl;
    }

    arithmeticMeanOfColumns(&m[0][0], n);
    cout<<"Среднеарифметические значения столбцов"<<endl;
    for (i = 0; i < N; i++)
    {
        cout<<n[i]<<"   ";
    }
    cout<<endl;

    z = sumUpperTriangularPart(&m[0][0]);
    cout<<"Сумма элементов верхнетреугольной части матрицы :"<<z<<endl;

    z = sumLowerTriangularPart(&m[0][0]);
    cout<<"Сумма элементов нижнетреугольной части матрицы :"<<z<<endl;

    z = closeValueToArithmeticMean(&m[0][0]);
    cout<<"Элемент наиболее близкий к среднеарифметическому :"<<z<<endl;
    
    getch();
}

float closeValueToArithmeticMean(float *m) {
    float arithmeticMeanMatrix(float*);
    float s = arithmeticMeanMatrix(m);
    int i, j;
    float x=abs(s - *m), z = 0., y;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            z = abs(s - m[i*N+j]);
            if (x>z)
            {
                x = z;
                y = m[i*N+j];
            }
        }
    }
    return y;
}

float sumLowerTriangularPart(float *m) {
    int i, j, y=1;
    float z = 0.;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < y; j++)
        {
            z += m[i*N+j];
        }
        ++y;
    }
    return z;
}

float sumUpperTriangularPart(float *m) {
    int i, j, y=0;
    float z = 0.;
    for (i = 0; i < N; i++)
    {
        for (j = y; j < N; j++)
        {
            z += m[i*N+j];
        }
        ++y;
    }
    return z;
}

void arithmeticMeanOfColumns(float *m, float *n) {
    int i, j;
    float z = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            z += m[i+N*j];
        }
        n[i] = (float)z/N;
        z=0.;
    }
}

void arithmeticMeanLine(float *m, float *n) {
    int i, j;
    float z = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            z += m[i*N+j];
        }
        n[i] = (float)z/N;
        z=0.;
    }
}

void maxValueOfColumns(float *m, float *n) {
    int i, j;
    float z = __FLT_MIN__;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        { 
            if (z < m[i+N*j])
            {
                z = m[i+N*j];
            }
        }
        n[i] = z;
        z=__FLT_MIN__;
    }
}

void maxValueOfLine(float *m, float *n) {
    int i, j;
    float z = __FLT_MIN__;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (z < m[i*N+j])
            {
                z = m[i*N+j];
            }
            
            
        }
        n[i] = z;
        z=__FLT_MIN__;
    }
}

void minValueOfColumns(float *m, float *n) {
    int i, j;
    float z = __FLT_MAX__;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        { 
            if (z > m[i+N*j])
            {
                z = m[i+N*j];
            }
        }
        n[i] = z;
        z=__FLT_MAX__;
    }
}

void minValueOfLine(float *m, float *n) {
    int i, j;
    float z = __FLT_MAX__;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (z > m[i*N+j])
            {
                z = m[i*N+j];
            }
            
            
        }
        n[i] = z;
        z=__FLT_MAX__;
    }
}

void sumOfColumns(float *m, float *n) {
    int i, j;
    float z = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            z += m[i+N*j];
        }
        n[i] = z;
        z=0.;
    }
}

void sumLine(float *m, float *n) {
    int i, j;
    float z = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            z += m[i*N+j];
        }
        n[i] = z;
        z=0.;
    }
}

float arithmeticMeanUpperTriangular(float *m) {
    int i, j, y=0, x=0;
    float z = 0;
    for (i = 0; i < N; i++)
    {
        for (j = y; j < N; j++)
        {
            z += m[i*N+j];
            x++;
        }
        ++y;
    }
    return z/(float)x;
}

float arithmeticMeanLowerTriangular(float *m) {
    int i, j, y=1, x=0;
    float z = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < y; j++)
        {
            z += m[i*N+j];
            x++;
        }
        ++y;
    }
    return z/(float)x;
}

float arithmeticMeanMatrix(float *m) {
    int i, j, x=N*N;
    float z = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            z += m[i*N+j];
        }
    }
    return z/(float)x;
}

float minMatrix(float *m) {
    int i, j;
    float z = __FLT_MAX__;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (z>m[i*N+j])
            {
                z = m[i*N+j];
            }
        }
    }
    return z;
}
float maxMatrix(float *m) {
    int i, j;
    float z = __FLT_MIN__;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (z<m[i*N+j])
            {
                z = m[i*N+j];
            }
        }
    }
    return z;
}

float minLowerTriangularPart(float *m) {
    int i, j, y=1;
    float z = __FLT_MAX__;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < y; j++)
        {
            if (z>m[i*N+j])
            {
                z = m[i*N+j];
            }
        }
        ++y;
    }
    return z;
}

float minUpperTriangularPart(float *m) {
    int i, j, y=0;
    float z = __FLT_MAX__;
    for (i = 0; i < N; i++)
    {
        for (j = y; j < N; j++)
        {
            if (z>m[i*N+j])
            {
                z = m[i*N+j];
            }
        }
        ++y;
    }
    return z;
}

float maxLowerTriangularPart(float *m) {
    int i, j, y=1;
    float z = __FLT_MIN__;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < y; j++)
        {
            if (z<m[i*N+j])
            {
                z = m[i*N+j];
            }
        }
        ++y;
    }
    return z;
}

float maxUpperTriangularPart(float *m) {
    int i, j, y=0;
    float z = __FLT_MIN__;
    for (i = 0; i < N; i++)
    {
        for (j = y; j < N; j++)
        {
            if (z<m[i*N+j])
            {
                z = m[i*N+j];
            }
        }
        ++y;
    }
    return z;
}

float minMainDiagonal(float *m) {
    int i, j;
    float z = __FLT_MAX__;
    for (i = 0, j = 0; i < N; i++, j++)
    {
        if (z>m[i*N+j])
            {
                z = m[i*N+j];
            }
    }
    return z;
}

float maxMainDiagonal(float *m) {
    int i, j;
    float z = __FLT_MIN__;
    for (i = 0, j = 0; i < N; i++, j++)
    {
        if (z<m[i*N+j])
            {
                z = m[i*N+j];
            }
    }
    return z;
}

float minSecondaryDiagonal(float *m) {
    int i, j;
    float z = __FLT_MAX__;
    for (i = 0, j = N-1; i < N; i++, j--)
    {
        if (z>m[i*N+j])
            {
                z = m[i*N+j];
            }
    }
    return z;
}

float maxSecondaryDiagonal(float *m) {
    int i, j;
    float z = __FLT_MIN__;
    for (i = 0, j = N-1; i < N; i++, j--)
    {
        if (z<m[i*N+j])
            {
                z = m[i*N+j];
            }
    }
    return z;
}