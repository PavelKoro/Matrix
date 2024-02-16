#ifndef GAUSS
#define GAUSS

#include "Matrix2D.h"

class Gauss : public Matrix2D
{
  double *arr; // матрица
  int n = get_N(); // размер матрицы n*n
  int sign;
    
  public:
    Gauss(int n);
    Gauss(Gauss &other);
    virtual ~Gauss();

    void gauss_method(); // Метод Гаусса
    double det(); // Определитель

    int max_column(int num_column); // max эл-т в строчке
    void swap_line(int line_1, int line_2); // меняет строчки местами
    void arithmetic(int line_1, int line_2); // производит арифметические действия между двумя строчками

    virtual void print(); // вывод матрицы
};
#endif // GAUSS