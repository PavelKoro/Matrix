#ifndef MATRIX2D
#define MATRIX2D

#include <cmath>
#include <cstdio>

class Matrix2D {
  double *data;
  int n;
  int ERROR;

  public:
    Matrix2D(int n);
    Matrix2D(Matrix2D &other);
    virtual ~Matrix2D();

    int err(); // значение эл-та ERROR
    int get_N(); // значение размера матрицы
    double matrix_num(int i); // получить эл-т матрицы
    void fill(int i, double num); // заполнение матрицы
    void fill_fail(char* arr, int n); // заполнение матрицы из файла
    int size_fail(char* arr); // кол-во эл-тов в файле

    virtual void print(); // вывод матрицы

    double* operator[](int i);
};



#endif // MATRIX2D
