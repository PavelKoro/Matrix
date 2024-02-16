#include <iostream>
#include "Equation.h"

#define EPS 0.000000000001

Equation::Equation(int n): Gauss(n) {
    matr = new double[n*n];
    for(int i=0; i<n*n; i++) matr[i]=i;
}

Equation::Equation(Equation &other): Gauss(other) {
    matr = new double[n*n];
    for(int i=0; i<n*n; i++) matr[i]=other.matr[i];
}

Equation::~Equation() {
    delete[] matr;
}

double Equation::proper_value() {
    double a = coef_A(0)/*-*/, b = coef_B(0)/*+*/, c;
    while(1) {
        c = (a+b)/2.0;
        if(matrix_diff(c) > 0) {
            b = c;
        } else {
            a = c;
        }
        if((a - b) < EPS) {
            break;
        }
    }
    return c;
}

double Equation::matrix_diff(double L) {
    Equation tmp((*this));
    for(int i=0; i<n; i++) {
        tmp[i][i] = tmp[i][i] - L;
    }
    return tmp.det();
}

double Equation::coef_A(double i) {
    int a;
    int count = 0;
    while(1) {
        if(matrix_diff(i) < 0) {
            a = i;
            break;
        }
        if(count <= 15) {
            i += 1;
            if(count == 15) {
                i = 0;
            }
            count += 1;
        } else {
            i -= 1;
        }
    }
    return a;
}

double Equation::coef_B(double j) {
    double b;
    int count = 0;
    while(1) {
        if(matrix_diff(j) > 0) {
            b = j;
            break;
        }

        if(count <= 15) {
            j += 1;
            if(count == 15) {
                j = 0;
            }
            count += 1;
        } else {
            j -= 1;
        }
    }
    return b;
}

void Equation::print() {
    if((*this).det() != 0) {
      printf("L = %f -> det(B - L*E) = %f\n", (*this).proper_value(), (*this).matrix_diff((*this).proper_value()));
    } else {
      printf("Определитель равен нулю -> L = 0\n");
    }
}