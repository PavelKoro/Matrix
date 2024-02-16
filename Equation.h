#ifndef EQUATION
#define EQUATION

#include "Gauss.h"

class Equation: public Gauss 
{
    double *matr; // матрица
    int n = get_N(); // размер матрицы n*n
    
    public:
        Equation(int n);
        Equation(Equation &other);
        virtual ~Equation();

        double proper_value(); // собственное значение

        double matrix_diff(double L); // det(B - L*E)
        double coef_A(double i); // коэффициент a
        double coef_B(double j); // коэффициент b

        virtual void print(); // вывод матрицы
};
#endif // EQUATION